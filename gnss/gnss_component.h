/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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
#pragma once

#include <memory>
#include <string>
#include <vector>

#include "gnss/stream/raw_stream.h"
#include "mimas/monitor_log/monitor_log_buffer.h"

#include "cyber/cyber.h"

namespace apollo {
namespace drivers {
namespace gnss {

using apollo::cyber::Component;
using apollo::cyber::Reader;
using apollo::cyber::Writer;
using apollo::drivers::gnss::RawData;

class GnssDriverComponent : public Component<> {
 public:
  GnssDriverComponent();
  bool Init() override;

 private:
  std::unique_ptr<RawStream> raw_stream_ = nullptr;
  apollo::common::monitor::MonitorLogBuffer monitor_logger_buffer_;
};

CYBER_REGISTER_COMPONENT(GnssDriverComponent)

}  // namespace gnss
}  // namespace drivers
}  // namespace apollo
