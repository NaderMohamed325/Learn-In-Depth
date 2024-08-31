/*
 * CortexMX__Os_Porting.h
 *
 *  Created on: Aug 31, 2024
 *      Author: xcite
 */

#ifndef CORTEX_OS
#define CORTEX_OS

#define OS_SET_PSP(add)  __asm volatile("mov r0 ,%0 \n\t msr PSP , r0 " : : "r"(add)  )
#define OS_GET_PSP(add)  __asm volatile("mrs r0 ,PSP \n\t mov %0 , r0 " :  "=r"(add)  )

#define OS_SP_PSP()      __asm volatile("mrs r0 ,CONTROL \n\t mov r1 ,#0x02 \n\t  orr r0,r0,r1 \n\t msr CONTROL , r0")
#define OS_PSP_SP()      __asm volatile("mrs r0 ,CONTROL \n\t mov r1 ,#0x05 \n\t  and r0,r0,r1 \n\t msr CONTROL , r0")

#define OS_Switch_to_privilged()   __asm("mrs r3, CONTROL \n\t lsr r3, r3, #0x01 \n\t lsr r3, r3, #0x01 \n\t msr CONTROL , r3")
#define OS_Switch_to_unprivilged() __asm("mrs r3, CONTROL \n\t orr r3, r3, #0x01 \n\t msr CONTROL , r3")










#endif
