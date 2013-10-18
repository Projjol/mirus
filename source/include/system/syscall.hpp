// Copyright 2013 Mirus Project

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//
// syscall.hpp - System call implimentation
//

#pragma once

#include <cpu/regs.hpp>

namespace mirus
{
    namespace system
    {
        void init_syscalls();
        void syscall_handler(cpu::regs* r);
        static uint32_t test_syscall();
        void test_syscalls(int eax);
    } // !namespace
} // !namespace