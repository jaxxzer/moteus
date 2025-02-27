// Copyright 2018 Josh Pieper, jjp@pobox.com.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <cstdint>

namespace moteus {

constexpr float k2Pi = 6.283185307179586f;
constexpr float kPi = 3.141592653589793f;
constexpr float kSqrt3_4 = 0.86602540378f;
constexpr float kSqrt6 = 2.449489742783178f;
constexpr float kSqrt3 = 1.7320508075688772f;
constexpr float kSqrt2 = 1.4142135623730951f;

inline float WrapZeroToTwoPi(float x) {
  // We would use fmodf, but we're trying to be fast here and don't
  // care too much about accuracy.

  // const float mod = ::fmodf(x, k2Pi);

  const int32_t divisor = static_cast<int>(x / k2Pi);
  const float mod = x - divisor * k2Pi;
  return (mod >= 0.0f) ? mod : (mod + k2Pi);
}

}
