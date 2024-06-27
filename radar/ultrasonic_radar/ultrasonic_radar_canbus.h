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
#include "radar/ultrasonic_radar/ultrasonic_radar_message_manager.h"

#include "canbus/proto/can_card_parameter.pb.h"
#include "canbus/proto/sensor_canbus_conf.pb.h"
#include "common_msgs/sensor_msgs/ultrasonic_radar.pb.h"
#include "radar/ultrasonic_radar/proto/ultrasonic_radar_conf.pb.h"

#include "cyber/common/macros.h"
#include "cyber/time/time.h"

/**
 * @namespace apollo::drivers
 * @brief apollo::drivers
 */
namespace apollo {
namespace drivers {
namespace ultrasonic_radar {

/**
 * @class UltrasonicRadarCanbus
 *
 * @brief template of canbus-based sensor module main class (e.g.,
 * ultrasonic_radar).
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

class UltrasonicRadarCanbus {
 public:
  UltrasonicRadarCanbus();
  ~UltrasonicRadarCanbus();

  /**
   * @brief obtain module name
   * @return module name
   */
  std::string Name() const;

  /**
   * @brief module initialization function
   * @return initialization status
   */
  apollo::common::Status Init(
      const std::string& config_path,
      const std::shared_ptr<::apollo::cyber::Writer<Ultrasonic>>& writer);

  /**
   * @brief module start function
   * @return start status
   */
  apollo::common::Status Start();

 private:
  Status OnError(const std::string& error_msg);
  void RegisterCanClients();

  UltrasonicRadarConf ultrasonic_radar_conf_;
  std::shared_ptr<CanClient> can_client_;
  CanReceiver<Ultrasonic> can_receiver_;
  std::unique_ptr<UltrasonicRadarMessageManager> sensor_message_manager_;

  int64_t last_timestamp_ = 0;
  apollo::common::monitor::MonitorLogBuffer monitor_logger_buffer_;
};

}  // namespace ultrasonic_radar
}  // namespace drivers
}  // namespace apollo
