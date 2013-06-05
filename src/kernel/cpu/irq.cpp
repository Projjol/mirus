#include <cpu/irq.hpp>

static mirus::irq_handler_t irq_routines[16] = { 0 };

void mirus::irq_install_handler(int irq, irq_handler_t handler) {
    irq_routines[irq] = handler;
}

void mirus::irq_uninstall_handler(int irq) {
    irq_routines[irq] = 0;
}

void mirus::irq_remap() {
    mirus::outb(0x20, 0x11);
    mirus::outb(0xA0, 0x11);
    mirus::outb(0x21, 0x20);
    mirus::outb(0xA1, 0x28);
    mirus::outb(0x21, 0x04);
    mirus::outb(0xA1, 0x02);
    mirus::outb(0x21, 0x01);
    mirus::outb(0xA1, 0x01);
    mirus::outb(0x21, 0x0);
    mirus::outb(0xA1, 0x0);
}

void mirus::irq_gates() {
    mirus::idt_set_gate(32, (unsigned)irq0, 0x08, 0x8E);
    mirus::idt_set_gate(33, (unsigned)irq1, 0x08, 0x8E);
    mirus::idt_set_gate(34, (unsigned)irq2, 0x08, 0x8E);
    mirus::idt_set_gate(35, (unsigned)irq3, 0x08, 0x8E);
    mirus::idt_set_gate(36, (unsigned)irq4, 0x08, 0x8E);
    mirus::idt_set_gate(37, (unsigned)irq5, 0x08, 0x8E);
    mirus::idt_set_gate(38, (unsigned)irq6, 0x08, 0x8E);
    mirus::idt_set_gate(39, (unsigned)irq7, 0x08, 0x8E);
    mirus::idt_set_gate(40, (unsigned)irq8, 0x08, 0x8E);
    mirus::idt_set_gate(41, (unsigned)irq9, 0x08, 0x8E);
    mirus::idt_set_gate(42, (unsigned)irq10, 0x08, 0x8E);
    mirus::idt_set_gate(43, (unsigned)irq11, 0x08, 0x8E);
    mirus::idt_set_gate(44, (unsigned)irq12, 0x08, 0x8E);
    mirus::idt_set_gate(45, (unsigned)irq13, 0x08, 0x8E);
    mirus::idt_set_gate(46, (unsigned)irq14, 0x08, 0x8E);
    mirus::idt_set_gate(47, (unsigned)irq15, 0x08, 0x8E);
}

void mirus::irq_install() {
    irq_remap();
    irq_gates();

    IRQ_RES;
}

void mirus::irq_ack(int irq_no) {
    if (irq_no >= 12) {
        mirus::outb(0xA0, 0x20);
    }

    mirus::outb(0x20, 0x20);
}

extern "C" void mirus::irq_handler(struct regs *r) {
    IRQ_OFF;
    void (*handler)(struct regs *r);

    if (r->int_no > 47 || r->int_no < 32) {
        handler = 0;
    } else {
        handler = irq_routines[r->int_no - 32];
    }

    if (handler) {
        handler(r);
    } else {
        irq_ack(r->int_no - 32);
    }

    IRQ_RES;
}