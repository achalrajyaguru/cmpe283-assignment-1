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


// adding procbased controls

struct capability_info procbased[21] =
{
	{2 , "Interrupt-window" },
	{3 , "Use TSC offsetting" },
	{7 , "HLT exiting" },
	{9 , "INVLPG exiting" },
	{10 , "MWAIT exiting" },
	{11 , "RDPMC exiting" },
	{12 , "RDTSC exiting" },
	{15 , "CR3-load exiting" },
	{16 , "CR3-store exiting" },
	{19 , "CR8-load exiting" },
	{20 , "CR8-store exiting" },
	{21 , "Use TPR shadow" },
	{22 , "NMI-window exiting" },
	{23 , "MOV-DR exiting" },
	{24 , "Unconditional I/O" },
	{25 , "Use I/O bitmaps" },
	{27 , "Monitor trap flag" },
	{28 , "Use MSR Bitmaps" },
	{29 , "MONITOR exiting" },
	{30 , "PAUSE exiting" },
	{31 , "Activate secondary controls" }
};

