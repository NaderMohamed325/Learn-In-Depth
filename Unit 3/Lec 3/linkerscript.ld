ENTRY(Reset_Handler)

MEMORY {
    Flash(rx) : ORIGIN = 0x08000000, LENGTH = 128k
    Sram(rwx) : ORIGIN = 0x20000000, LENGTH = 64k
}

SECTIONS {
    .text :
    {
        *(.vector)
        *(.text)
        *(.rodata)
        _E_text = .;
        . = ALIGN(4);
    } > Flash

    .data :
    {
        _S_data = .;
        *(.data)
        _E_data = .;
        . = ALIGN(4);
    } > Sram AT> Flash

    .bss :
    {
        _S_bss = .;
        *(.bss)
        _E_bss = .;
        . = ALIGN(4);
    } > Sram
}
