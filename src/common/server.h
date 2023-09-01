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

#ifndef __PPL_LLM_SERVER_H__
#define __PPL_LLM_SERVER_H__

#include "request.h"
#include "response.h"
#include <memory>

namespace ppl { namespace llm {

class Connection {
public:
    virtual ~Connection() {}
    virtual void Send(const Response&) = 0;
    virtual void NotifyFailure(uint64_t id) = 0;
};

class RequestProcessor {
public:
    virtual ~RequestProcessor() {}
    virtual void Wait() = 0; // XXX will be removed
    virtual void Work() = 0; // XXX will be removed
    virtual void Process(const std::shared_ptr<Request>&, Connection*) = 0;
};

class Server {
public:
    virtual ~Server() {}
    virtual void Loop(RequestProcessor*) = 0;
};

}} // namespace ppl::llm

#endif
