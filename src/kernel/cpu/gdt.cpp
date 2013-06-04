#include <cpu/gdt.hpp>

// methods and variables used in the asm file
namespace mirus {
    extern "C" {
        void gdt_flush();
        mirus::gdt_ptr gp;
    }
}

// simple 3 entry gdt
static mirus::gdt_entry gdt[3];

void mirus::gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran) {
    using namespace mirus;

    // descriptor base address
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    // limits
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);

    // flags + granularity
    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

void mirus::gdt_install() {
    using namespace mirus;

    // setup gdt pointer
    gp.limit = (sizeof(gdt_entry) * 3) - 1;
    gp.base = (unsigned int)&gdt;

    // NULL desc.
    gdt_set_gate(0, 0, 0, 0, 0);

    /* The second entry is our Code Segment. The base address
    *  is 0, the limit is 4GBytes, it uses 4KByte granularity,
    *  uses 32-bit opcodes, and is a Code Segment descriptor.
    *  Please check the table above in the tutorial in order
    *  to see exactly what each value means */
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

    /* The third entry is our Data Segment. It's EXACTLY the
    *  same as our code segment, but the descriptor type in
    *  this entry's access byte says it's a Data Segment */
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    // finalize
    gdt_flush();
}