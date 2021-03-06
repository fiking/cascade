// Copyright 2017-2019 VMware, Inc.
// SPDX-License-Identifier: BSD-2-Clause
//
// The BSD-2 license (the License) set forth below applies to all parts of the
// Cascade project.  You may not use this file except in compliance with the
// License.
//
// BSD-2 License
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS AS IS AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef CASCADE_SRC_TARGET_COMPILER_STUB_CORE_H
#define CASCADE_SRC_TARGET_COMPILER_STUB_CORE_H

#include "target/core.h"
#include "target/input.h"
#include "target/state.h"

namespace cascade {

class StubCore : public Core {
  public:
    explicit StubCore(Interface* interface);
    ~StubCore() override = default;

    State* get_state() override;
    void set_state(const State* s) override;
    Input* get_input() override;
    void set_input(const Input* i) override;

    void read(VId id, const Bits* b) override;
    void evaluate() override;
    bool there_are_updates() const override;
    void update() override;
    bool there_were_tasks() const override;

    bool is_stub() const override;
};

inline StubCore::StubCore(Interface* interface) : Core(interface) { }

inline State* StubCore::get_state() {
  return new State();
} 

inline void StubCore::set_state(const State* s) {
  // Does nothing.
  (void) s;
}

inline Input* StubCore::get_input() {
  return new Input();
}

inline void StubCore::set_input(const Input* i) {
  // Does nothing.
  (void) i;
}

inline void StubCore::read(VId id, const Bits* b) {
  // Does nothing.
  (void) id;
  (void) b;
}

inline void StubCore::evaluate() {
   // Does nothing.
}

inline bool StubCore::there_are_updates() const {
  return false;
}

inline void StubCore::update() {
  // Does nothing.
}

inline bool StubCore::there_were_tasks() const {
  return false;
}

inline bool StubCore::is_stub() const {
  return true;
}

} // namespace cascade

#endif
