#include <term/terminal.hpp>
#include <misc/printf.hpp>

#include <cpu/gdt.hpp>
#include <cpu/idt.hpp>
#include <cpu/isr.hpp>
#include <cpu/irq.hpp>

#include <hw/pit.hpp>
#include <hw/keyboard.hpp>

extern "C" void kernel_main()
{
    // install the GDT
	mirus::gdt_install();

    // install the IDT
    mirus::idt_install();

    // install ISRs
    mirus::isrs_install();

    // install IRQs
    mirus::irq_install();

    // initilize display
	mirus::terminal_initialize();

    // install timer
    //mirus::timer_install();

    // install keyboard
    mirus::keyboard_install();

    asm volatile("sti");

    // print version number
	mirus::printf("mirus ");
	mirus::printf(BUILD_MAJOR);
	mirus::printf(".");
	mirus::printf(BUILD_MINOR);
	mirus::printf(".");
	mirus::printf(BUILD_NUM);
    mirus::printf("\r");
    mirus::printf("\r");

    // WHAT THE HELL
    mirus::timer_wait(1);

    mirus::printf("Write some stuff: ");
}
