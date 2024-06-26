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

#include "lidar/robosense/decoder/decoder_128.hpp"
#include "lidar/robosense/decoder/decoder_16.hpp"
#include "lidar/robosense/decoder/decoder_32.hpp"
#include "lidar/robosense/decoder/decoder_bp.hpp"

namespace apollo {
namespace drivers {
namespace robosense {
template <typename vpoint>
class DecoderFactory {
 public:
  inline static std::shared_ptr<DecoderBase<vpoint>> createDecoder(
      const std::string &lidar_type, const RS_Param &param) {
    if (lidar_type == "RS16") {
      return std::make_shared<Decoder16<vpoint>>(param);
    } else if (lidar_type == "RS32") {
      return std::make_shared<Decoder32<vpoint>>(param);
    } else if (lidar_type == "RSBP") {
      return std::make_shared<DecoderBP<vpoint>>(param);
    } else if (lidar_type == "RS128") {
      return std::make_shared<Decoder128<vpoint>>(param);
    } else {
      return nullptr;
    }
  }
};

}  // namespace robosense
}  // namespace drivers
}  // namespace apollo
