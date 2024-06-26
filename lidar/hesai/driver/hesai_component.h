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

#pragma once

#include <memory>
#include <string>

#include "lidar/hesai/driver/driver.h"
#include "lidar/hesai/parser/parser_factory.h"

#include "lidar/proto/config.pb.h"

#include "cyber/cyber.h"

namespace apollo {
namespace drivers {
namespace hesai {

class HesaiComponent : public ::apollo::cyber::Component<> {
 public:
  ~HesaiComponent() {}
  bool Init() override;

 private:
  std::shared_ptr<HesaiDriver> driver_;
  Config hesai_conf_;
};

CYBER_REGISTER_COMPONENT(HesaiComponent)

}  // namespace hesai
}  // namespace drivers
}  // namespace apollo
