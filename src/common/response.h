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

#ifndef __PPL_LLM_RESPONSE_H__
#define __PPL_LLM_RESPONSE_H__

#include <stdint.h>
#include <string>

namespace ppl { namespace llm {

// ref: https://huggingface.github.io/text-generation-inference/
enum class FinishFlag {
    NOT_FINISHED,
    LENGTH, 
    EOS_TOKEN,
    STOP_SEQUENCE   // not used yet
};

struct Response final {
    uint64_t id;
    std::string generated;
    int token;
    FinishFlag finish_flag;
    float logprob;
    bool is_special;
};

}} // namespace ppl::llm

#endif
