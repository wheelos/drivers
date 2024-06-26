/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
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

/**
 * @file
 */

#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "canbus/can_client/can_client.h"
#include "canbus/can_client/can_client_factory.h"
#include "canbus/can_comm/can_receiver.h"
#include "canbus/can_comm/can_sender.h"
#include "canbus/can_comm/message_manager.h"
#include "canbus/sensor_gflags.h"
#include "mimas/monitor_log/monitor_log_buffer.h"
#include "mimas/status/status.h"
#include "mimas/util/util.h"
#include "radar/racobit_radar/protocol/radar_config_200.h"
#include "radar/racobit_radar/racobit_radar_message_manager.h"

#include "canbus/proto/can_card_parameter.pb.h"
#include "canbus/proto/sensor_canbus_conf.pb.h"
#include "common_msgs/sensor_msgs/racobit_radar.pb.h"

#include "cyber/cyber.h"
#include "cyber/time/time.h"

/**
 * @namespace apollo::drivers
 * @brief apollo::drivers
 */
namespace apollo {
namespace drivers {
namespace racobit_radar {

/**
 * @class RacobitRadarCanbus
 *
 * @brief template of canbus-based sensor module main class (e.g.,
 * racobit_radar).
 */

using apollo::common::ErrorCode;
using apollo::common::Status;
using apollo::common::monitor::MonitorMessageItem;
using apollo::cyber::Time;
using apollo::drivers::canbus::CanClient;
using apollo::drivers::canbus::CanClientFactory;
using apollo::drivers::canbus::CanReceiver;
using apollo::drivers::canbus::SenderMessage;
using apollo::drivers::canbus::SensorCanbusConf;

class RacobitRadarCanbusComponent : public apollo::cyber::Component<> {
 public:
  // TODO(lizh): check whether we need a new msg item, say
  // MonitorMessageItem::SENSORCANBUS
  RacobitRadarCanbusComponent();
  ~RacobitRadarCanbusComponent();

  /**
   * @brief module initialization function
   * @return initialization success(true) or not(false).
   */
  bool Init() override;

 private:
  void RegisterCanClients();
  apollo::common::ErrorCode ConfigureRadar();
  Status OnError(const std::string &error_msg);
  std::shared_ptr<CanClient> can_client_;
  CanReceiver<RacobitRadar> can_receiver_;
  std::unique_ptr<RacobitRadarMessageManager> sensor_message_manager_;

  int64_t last_timestamp_ = 0;
  apollo::common::monitor::MonitorLogBuffer monitor_logger_buffer_;
  bool start_success_ = false;
  // cyber
  RacobitRadarConf racobit_radar_conf_;
  std::shared_ptr<cyber::Writer<RacobitRadar>> racobit_radar_writer_;
};

CYBER_REGISTER_COMPONENT(RacobitRadarCanbusComponent)

}  // namespace racobit_radar
}  // namespace drivers
}  // namespace apollo
