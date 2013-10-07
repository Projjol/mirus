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
// debug.hpp - debugger
//

#pragma once

namespace mirus
{
    namespace debug
    {
        enum class debug_level : int
        {
            log = 0,
            error = 1,
            msg = 2,
            trace = 3,
            warning = 4,
            none = 5
        };

        class debugger
        {
        public:
            static int write(debug_level level, 
                const char *fmt, 
                ...);
        };
    } // !namespace
} // !namespace