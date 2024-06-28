/*
 * Utils.h
 *
 * Created: 6/26/2024 11:37:07 PM
 *  Author: Nader
 */ 


#ifndef UTILS_H_
#define UTILS_H_
#define MASK   1UL


// Macro to set a specific bit in a register
// REG: The register in which the bit needs to be set
// BIT: The bit position to be set (0 for least significant bit)
#define SET_BIT(REG, BIT) (REG |= (1 << BIT))

// Macro to clear a specific bit in a register
// REG: The register in which the bit needs to be cleared
// BIT: The bit position to be cleared (0 for least significant bit)
#define CLEAR_BIT(REG, BIT) (REG &= ~(1 << BIT))

// Macro to read a specific bit in a register
// REG: The register from which the bit needs to be read
// BIT: The bit position to be read (0 for least significant bit)
// Returns a non-zero value if the bit is set, otherwise returns 0
#define READ_BIT(REG, BIT)  ((REG >>BIT)&1)

// Macro to toggle a specific bit in a register
// REG: The register in which the bit needs to be toggled
// BIT: The bit position to be toggled (0 for least significant bit)
// Toggles the bit, setting it if it was clear and clearing it if it was set
#define TOGGLE_BIT(REG, BIT) (REG ^= (1 << BIT))



#endif /* UTILS_H_ */