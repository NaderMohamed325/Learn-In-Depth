// Startup file for ARM Cortex-M microcontrollers

#include <stdint.h>

// Define the start of the stack
#define STACK_START 0x20002800U

// Symbols from the linker script
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
extern int main();
// Function prototypes for interrupt handlers
void Default_Handler(void);
void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));
// Add other interrupt handlers here

// Default handler for unused interrupts
void Default_Handler() {
    while (1) {}
}

// Reset handler: Initializes data and bss sections, then jumps to main
void Reset_Handler() {
    uint32_t Data_size = (uint32_t) &_E_data - (uint32_t) &_S_data;
    uint32_t *Src = (uint32_t *) &_E_text;
    uint32_t *Dst = (uint32_t *) &_S_data;
    for (int i = 0; i < Data_size; ++i) {
        *(Dst++) = *(Src++);
    }

    Data_size = (uint32_t) &_E_bss - (uint32_t) &_S_bss;
    Dst = (uint32_t *) &_S_bss;
    for (int i = 0; i < Data_size; ++i) {
        *(Dst++) = 0U;
    }

    // Call main function
    main();

    // In case main returns, enter an infinite loop
    while (1) {}
}

// Vector table
uint32_t Vectors[] __attribute__((section(".vector"))) = {
        STACK_START,
        (uint32_t)&Reset_Handler,
        (uint32_t)&NMI_Handler,
        (uint32_t)&HardFault_Handler,
        (uint32_t)&MemManage_Handler,
        (uint32_t)&BusFault_Handler,
        (uint32_t)&UsageFault_Handler,
        0,
        0,
        0,
        0,
        (uint32_t)&SVC_Handler,
        (uint32_t)&DebugMon_Handler,
        0,
        (uint32_t)&PendSV_Handler,
        (uint32_t)&SysTick_Handler,
        // Add other interrupt handler addresses here
};
