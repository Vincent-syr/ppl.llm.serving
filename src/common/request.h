// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef __PPL_LLM_REQUEST_H__
#define __PPL_LLM_REQUEST_H__

#include <stdint.h>
#include <string>
#include <vector>
#include <unordered_set>
#include <memory>

namespace ppl { namespace llm {

struct Request final {
    Request() {}
    Request(uint64_t _id, std::string _prompt, float _temperature, uint32_t _generation_length)
        : id(_id), prompt(_prompt), temperature(_temperature), generation_length(_generation_length) {}
    uint64_t id;
    std::string prompt;
    float temperature = 1.f;
    float top_p = 0.f;
    int32_t top_k = 1;
    float repetition_penalty = 1.f;
    float presence_penalty = 0.f;
    float frequency_penalty = 0.f;
    int32_t generation_length = 0;
    bool early_stopping = true;
    bool is_token_in_out = false;
    std::shared_ptr<std::vector<int>> token_ids;
    std::shared_ptr<std::unordered_set<int>> stop_tokens;
};

}} // namespace ppl::llm

#endif
