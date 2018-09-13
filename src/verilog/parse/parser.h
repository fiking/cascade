// Copyright 2017-2018 VMware, Inc.
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

#ifndef CASCADE_SRC_VERILOG_PARSE_PARSER_H
#define CASCADE_SRC_VERILOG_PARSE_PARSER_H

#include <iostream>
#include <stack>
#include <string>
#include "src/base/log/loggable.h"
#include "src/verilog/ast/ast_fwd.h"
#include "src/verilog/ast/visitors/editor.h"
#include "src/verilog/parse/lexer.h"
#include "src/verilog/parse/verilog.tab.hh"

namespace cascade {

class Parser : public Editor, public Loggable {
  public:
    // Constructors:
    Parser();
    ~Parser() override = default;

    Parser& debug_lexer(bool debug);
    Parser& debug_parser(bool debug);

    // Parser Interface:
    void push();
    void push(const std::string& path);
    std::pair<Node*, bool> parse(std::istream& is);
    void pop();

  private:
    bool debug_lexer_;
    friend class yyLexer;
    yyLexer lexer_;

    bool debug_parser_;
    friend class yyParser;
    
    std::stack<std::pair<std::string, location>> loc_;
    Node* res_;
    bool eof_;

    location& loc();

    void edit(ModuleDeclaration* md) override;
    void edit(ModuleInstantiation* mi) override;
};

} // namespace cascade 

#endif
