/*  
 *  Name:Achal Rajyaguru || ID: 015958670
 */
#include <linux/module.h>	
#include <linux/kernel.h>	
#include <asm/msr.h>

#define MAX_MSG 80


#define IA32_VMX_PINBASED_CTLS	0x481

#define IA32_VMX_BASIC_CTLS 0x480

#define IA32_VMX_PROCBASED_CTLS 0x482

#define IA32_VMX_PROCBASED_CTLS2 0x48B

#define IA32_VMX_EXIT_CTLS 0x483

#define IA32_VMX_ENTRY_CTLS 0x484

#define IA32_VMX_TRUE_PINBASED_CTLS 0x48D

#define IA32_VMX_TRUE_PROCBASED_CTLS 0x48E

#define IA32_VMX_TRUE_EXIT_CTLS 0x48F

#define IA32_VMX_TRUE_ENTRY_CTLS 0x490


// writing code to report capability

struct capability_info {
	uint8_t bit;
	const char *name;
};


// adding pinased capability info

struct capability_info pinbased[5] =
{
	{ 0, "External Interrupt Exiting" },
	{ 3, "NMI Exiting" },
	{ 5, "Virtual NMIs" },
	{ 6, "Activate VMX Preemption Timer" },
	{ 7, "Process Posted Interrupts" }
};
