// Copyright 2014 Google Inc. All rights reserved.
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

#include "libc_rand.h"

#include <stdint.h>  // uint64_t
//#include <stdio.h>  // printf
#include <stdlib.h>  // srand
#include <time.h>  // time

// Copied from client/python/fastrand.c
uint64_t randbits(float p1, int num_bits) {
  uint64_t result = 0;
  int threshold = (int)(p1 * RAND_MAX);
  int i;
  for (i = 0; i < num_bits; ++i) {
    uint64_t bit = (rand() < threshold);
    result |= (bit << i);
  }
  return result;
}

void GlobalInit() {
  int seed = time(NULL);
  srand(seed);
}

namespace rappor {

unsigned int LibcRand::f_bits() {
  return 0;
}

unsigned int LibcRand::p_bits() {
  return 0;
}

unsigned int LibcRand::q_bits() {
  return 0;
}

}  // namespace rappor