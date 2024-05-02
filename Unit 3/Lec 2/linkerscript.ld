 
ENTRY( reset )

MEMORY
{

MEM (rwx) : ORIGIN = 0x00000000 , LENGTH = 64M

}

SECTIONS
{
    . = 0x10000 ;
    .startup . :
    {
    startup.o(.text)
    } > MEM
    .text :
    {
    *(.text) *(.rodata)
    } > MEM
    .data :
    {
    *(.data)
    } > MEM
    .bss :
    {
    *(.bss) *(COMMON)
    } > MEM
    . = . + 0x1000 ;
    stack_top = . ;
}
