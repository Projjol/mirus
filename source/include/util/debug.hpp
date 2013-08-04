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

#ifndef _MIRUS_KERNEL_DEBUG_H_
#define _MIRUS_KERNEL_DEBUG_H_

#include <hw/serial.hpp>
#include <util/string.hpp>

namespace mirus
{
    class debugger
    {
        public:
            static void write(const char *str);
            static void write(const char chr);
            static void write(const int wint);

            static void writeln(const char *str);

            static void flush();
    };
}

#endif
