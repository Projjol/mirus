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

#ifndef _MIRUS_KERNEL_TERMINAL_H_
#define _MIRUS_KERNEL_TERMINAL_H_

#include <stddef.h>
#include <stdint.h>
#include <util/string.hpp>
#include <core/ioport.hpp>
#include <mem/memory.hpp>

// TODO: move under mirus namespace
// TODO: move under a mirus::io::term class (or similar)
// TODO: prettyfy/make simpiler

// Hardware text mode color constants.
enum vga_color
{
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_MAGENTA = 5,
    COLOR_BROWN = 6,
    COLOR_LIGHT_GREY = 7,
    COLOR_DARK_GREY = 8,
    COLOR_LIGHT_BLUE = 9,
    COLOR_LIGHT_GREEN = 10,
    COLOR_LIGHT_CYAN = 11,
    COLOR_LIGHT_RED = 12,
    COLOR_LIGHT_MAGENTA = 13,
    COLOR_LIGHT_BROWN = 14,
    COLOR_WHITE = 15,
};

namespace mirus
{
    // create a color
    uint8_t make_color(enum vga_color fg, enum vga_color bg);

    // create a VGA entry
    uint16_t make_vgaentry(char c, uint8_t color);

    // init the terminal
    void terminal_initialize();

    // set color
    void terminal_setcolor(uint8_t color);

    // put an entry at location
    void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);

    // put a char at a location
    void terminal_putchar(char c);
    void terminal_putchar(char c, uint8_t color);

    // write a string
    void terminal_writestring(const char *data);
    void terminal_writestring(const char *data, uint8_t color);

    // clear function
    void terminal_clear();
    void terminal_clear(uint8_t color);

    // our test void
    void test();

    // scroll it
    void terminal_scroll();

    // move cursor
    void terminal_move_cursor();
}

#endif