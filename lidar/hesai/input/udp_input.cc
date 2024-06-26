/******************************************************************************
 * Copyright 2020 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "lidar/hesai/input/udp_input.h"

#include <arpa/inet.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/file.h>
#include <sys/socket.h>

#include <cerrno>
#include <cstring>
#include <sstream>

#include "cyber/cyber.h"

namespace apollo {
namespace drivers {
namespace hesai {

Input::Input(uint16_t port, uint16_t gpsPort) {
  socketForLidar = -1;
  socketForLidar = socket(PF_INET, SOCK_DGRAM, 0);
  if (-1 == socketForLidar) {
    AERROR << "socket open error";
    return;
  }

  sockaddr_in myAddress;                     // my address information
  memset(&myAddress, 0, sizeof(myAddress));  // initialize to zeros
  myAddress.sin_family = AF_INET;            // host byte order
  myAddress.sin_port = htons(port);          // port in network byte order
  myAddress.sin_addr.s_addr = INADDR_ANY;    // automatically fill in my IP

  if (bind(socketForLidar, reinterpret_cast<sockaddr *>(&myAddress),
           sizeof(sockaddr)) == -1) {
    AERROR << "bind error, port:" << port;
    return;
  }

  if (fcntl(socketForLidar, F_SETFL, O_NONBLOCK | FASYNC) < 0) {
    AERROR << "fcntl error";
    return;
  }

  if (port == gpsPort) {
    socketNumber = 1;
    return;
  }

  // gps socket
  socketForGPS = -1;
  socketForGPS = socket(PF_INET, SOCK_DGRAM, 0);
  if (socketForGPS == -1) {
    return;
  }

  sockaddr_in myAddressGPS;                        // my address information
  memset(&myAddressGPS, 0, sizeof(myAddressGPS));  // initialize to zeros
  myAddressGPS.sin_family = AF_INET;               // host byte order
  myAddressGPS.sin_port = htons(gpsPort);          // port in network byte order
  myAddressGPS.sin_addr.s_addr = INADDR_ANY;  // automatically fill in my IP

  if (bind(socketForGPS, reinterpret_cast<sockaddr *>(&myAddressGPS),
           sizeof(sockaddr)) == -1) {
    AERROR << "gps bind error";
    return;
  }

  if (fcntl(socketForGPS, F_SETFL, O_NONBLOCK | FASYNC) < 0) {
    AERROR << "gps fcntl error";
    return;
  }

  socketNumber = 2;
}

Input::~Input(void) {
  if (socketForGPS > 0) close(socketForGPS);
  if (socketForLidar > 0) (void)close(socketForLidar);
}

// return : 0 - lidar
//          1 - gps
//         -1 - error
int Input::GetPacket(HesaiPacket *pkt) {
  struct pollfd fds[socketNumber];
  if (socketNumber == 2) {
    fds[0].fd = socketForGPS;
    fds[0].events = POLLIN;

    fds[1].fd = socketForLidar;
    fds[1].events = POLLIN;
  } else if (socketNumber == 1) {
    fds[0].fd = socketForLidar;
    fds[0].events = POLLIN;
  }
  static const int POLL_TIMEOUT = 1000;  // one second (in msec)

  sockaddr_in senderAddress;
  socklen_t senderAddressLen = sizeof(senderAddress);
  int retval = poll(fds, socketNumber, POLL_TIMEOUT);
  if (retval < 0) {
    if (errno != EINTR) {
      AERROR << "poll() error:" << strerror(errno);
    }
    return -1;
  }
  if (retval == 0) {
    AERROR << "poll() timeout";
    return -1;
  }
  if ((fds[0].revents & POLLERR) || (fds[0].revents & POLLHUP) ||
      (fds[0].revents & POLLNVAL)) {
    AERROR << "poll() reports hesai error";
    return -1;
  }

  senderAddressLen = sizeof(senderAddress);
  ssize_t nbytes = 0;
  for (int i = 0; i != socketNumber; ++i) {
    if (fds[i].revents & POLLIN) {
      nbytes = recvfrom(fds[i].fd, &pkt->data[0], ETHERNET_MTU, 0,
                        reinterpret_cast<sockaddr *>(&senderAddress),
                        &senderAddressLen);
      break;
    }
  }

  if (nbytes < 0) {
    if (errno != EWOULDBLOCK) {
      AERROR << "recvfrom error";
      return -1;
    }
  }

  pkt->size = nbytes;
  return 0;
}

}  // namespace hesai
}  // namespace drivers
}  // namespace apollo
