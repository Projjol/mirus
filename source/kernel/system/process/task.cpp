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
// task.cpp - Task stuff
//

#include <system/process/task.hpp>
#include <cpu/tss.hpp>

namespace mirus
{
    namespace system
    {
        extern "C" void jmp_usermode();

        //
        // enter_userpace - Goodbye kernel
        //
        void enter_userspace()
        {
            cpu::set_kernel_stack(0x9000);
            jmp_usermode();
        }
    } // !namespace
} // !namespace