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
// syscall.cpp - System call implimentation
//

#include <stdafx.hpp>
#include <system/syscall.hpp>
#include <cpu/irq.hpp>
#include <cpu/isr.hpp>

namespace mirus
{
    namespace system
    {
        static int test_syscall()
        {
            kprintf("Test syscall called.\n");
            return 0;
        }

        uintptr_t syscalls[1] =
        {
            (uintptr_t)&test_syscall
        };

        typedef uint32_t (*syscall_t)(...);

        void syscall_handler(cpu::regs* r)
        {
            ktrace(trace_level::msg, "System call called\n");
            if (r->eax >= 3)
                return;

            uintptr_t location = syscalls[r->eax];
            if (!location)
                return;

            syscall_t func = (syscall_t)location;
            uint32_t ret = func(r->ebx, r->ecx, r->edx, r->esi, r->edi);

            r->eax = ret;
        }

        void test_syscalls(int eax)
        {
            cpu::regs* r;
            r->eax = eax;
            r->ebx = 0;
            r->ecx = 0;
            r->edx = 0;
            r->esi = 0;
            r->edi = 0;
            syscall_handler(r);
        }

        void init_syscalls()
        {
            cpu::irq::install_handler(0x7F, &syscall_handler);
            // cpu::isr::install_handler(0x7F, &syscall_handler);
        }
    } // !namespace
} // !namespace