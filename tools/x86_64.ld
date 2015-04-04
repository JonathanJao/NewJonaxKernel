OUTPUT_FORMAT(elf64-x86-64)
ENTRY(start)
SECTIONS
{
    . = 0x100000;

    .text : AT(ADDR(.text) - 0x100000)
    {
        _code = .;
        *(.text)
        *(.rodata*)
        . = ALIGN(4096);
    }

   .data : AT(ADDR(.data) - 0x100000)
   {
        _data = .;
        *(.data)
        . = ALIGN(4096);
   }

   .ehframe : AT(ADDR(.ehframe) - 0x100000)
   {
       _ehframe = .;
       *(.ehframe)
        . = ALIGN(4096);
   }

   .bss : AT(ADDR(.bss) - 0x100000)
   {
       _bss = .;
       *(.bss)
       . = ALIGN(4096);
   }

   _end = .;
}