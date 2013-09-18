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
// debug.cpp - debugger
//

#include <debug/debug.hpp>
#include <hardware/serial.hpp>
#include <util/string.hpp>

namespace mirus
{
    namespace debug
    {
        void debugger::write(const char *str)
        {
            unsigned int len = strlen(str);

            for (unsigned int i = 0; i < len; i++)
            {
                hardware::serial::write(str[i]);
            }
        }

        void debugger::write(char chr)
        {
            hardware::serial::write(chr);
        }

        void debugger::write(int wint)
        {
            char *num = iota(wint);
            debugger::write(num);
        }

        void debugger::writeln(const char *str)
        {
            debugger::write(str);
            debugger::write('\n');
        }

        void debugger::flush()
        {
            hardware::serial::write('\n');
        }
    } // !namespace
} // !namespace