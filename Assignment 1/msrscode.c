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

struct capability_info procbased_ctls2[23] =
{
	{ 0, "Virtualize APIC accesses" },
	{ 1, "Enable EPT" },
	{ 2, "Descriptor-table exiting" },
	{ 3, "Enable RDTSCP" },
	{ 4, "Virtualize x2APIC mode" },
	{ 5, "Enable VPID" },
	{ 6, "WBINVD exiting" },
	{ 7, "Unrestricted guest" },
	{ 8, "APIC-register virtualization" },
	{ 9, "Virtual-interrupt delivery" },
	{ 10, "PAUSE-loop exiting" },
	{ 11, "RDRAND exiting" },
	{ 12, "Enable INVPCID" },
	{ 13, "Enable VM functions" },
	{ 14, "VMCS shadowing" },
	{ 15, "Enable ENCLS exiting" },
	{ 16, "RDSEED exiting" },
	{ 17, "Enable PML" },
	{ 18, "EPT-violation" },
	{ 19, "Conceal VMX nonroot operation from Intel PT" },
	{ 20, "Enable XSAVES/XRSTORS" },
	{ 22, "Mode-based execute control for EPT" },
	{ 25, "Use TSC scaling" }
};



//adding entry controls 

struct capability_info entry[9] =
{
	{ 2, "Load debug controls" },
	{ 9, "IA-32e mode guest" },
	{ 10, "Entry to SMM" },
	{ 11, "Deactivate dual-monitor treatment" },
	{ 13, "Load IA32_PERF_GLOBAL_CTRL" },
	{ 14, "Load IA32_PAT" },
	{ 15, "Load IA32_EFER" },
	{ 16, "Load IA32_BNDCFGS" },
	{ 17, "Conceal VM entries from Intel PT" }
};

// adding exit controls

struct capability_info exit[11] =
{
	{ 2, "Save debug controls" },
	{ 9, "Host addressspace size" },
	{ 12, "Load IA32_PERF_GLOB AL_CTRL" },
	{ 15, "Acknowledge interrupt on exit" },
	{ 18, "Save IA32_PAT" },
	{ 19, "Load IA32_PAT" },
	{ 20, "Save IA32_EEFR" },
	{ 21, "Load IA32_EFER" },
	{ 22, "Save VMXpreemption timer value" },
	{ 23, "Clear IA32_BNDCFGS" },
	{ 24, "Conceal VM exits from Intel PT" },
};


// code to generate required yes/ no output

void
report_capability(struct capability_info *cap, uint8_t len, uint32_t lo,
    uint32_t hi)
{
	uint8_t i;
	struct capability_info *c;
	char msg[MAX_MSG];

	memset(msg, 0, sizeof(msg));

	for (i = 0; i < len; i++) {
		c = &cap[i];
		snprintf(msg, 79, "  %s: Can set=%s, Can clear=%s\n",
		    c->name,
		    (hi & (1 << c->bit)) ? "Yes" : "No",
		    !(lo & (1 << c->bit)) ? "Yes" : "No");
		printk(msg);
	}
}

//prionting vmx features

void
detect_vmx_features(void)
{
	uint32_t lo, hi;
	
	rdmsr(IA32_VMX_BASIC_CTLS, lo, hi);
	pr_info("Basic Controls MSR: 0x%llx\n",
		(uint64_t)(lo | (uint64_t)hi << 32));
	//report_capability(pinbased, 5, lo, hi);
	
	pr_info("\n");

	if(!((hi>>23)&& 1))
	{
		/* Pinbased controls */
		rdmsr(IA32_VMX_PINBASED_CTLS, lo, hi);
		pr_info("Pinbased Controls MSR: 0x%llx\n",
			(uint64_t)(lo | (uint64_t)hi << 32));
		report_capability(pinbased, 5, lo, hi);

		pr_info("\n");
		
		/* Procbased controls */
		rdmsr(IA32_VMX_PROCBASED_CTLS, lo, hi);
		pr_info("Procbased Controls MSR: 0x%llx\n",
			(uint64_t)(lo | (uint64_t)hi << 32));
		report_capability(procbased, 21, lo, hi);

		pr_info("\n");
		
		if((hi>>31)&& 1)
		{
			/* Procbased_ctls2 controls */
			rdmsr(IA32_VMX_PROCBASED_CTLS2, lo, hi);
			pr_info("Procbased_ctls2 Controls MSR: 0x%llx\n",
				(uint64_t)(lo | (uint64_t)hi << 32));
			report_capability(procbased_ctls2, 23, lo, hi);

			pr_info("\n");
		}
		
		/* Exit controls */
		rdmsr(IA32_VMX_EXIT_CTLS, lo, hi);
		pr_info("Exit Controls MSR: 0x%llx\n",
			(uint64_t)(lo | (uint64_t)hi << 32));
		report_capability(exit, 11, lo, hi);

		pr_info("\n");
		
		/* Entry controls */
		rdmsr(IA32_VMX_ENTRY_CTLS, lo, hi);
		pr_info("Entry Controls MSR: 0x%llx\n",
			(uint64_t)(lo | (uint64_t)hi << 32));
		report_capability(entry, 9, lo, hi);
	
	}
	else
	{
		/* True Pinbased controls */
		rdmsr(IA32_VMX_TRUE_PINBASED_CTLS, lo, hi);
		pr_info("Pinbased Controls MSR: 0x%llx\n",
			(uint64_t)(lo | (uint64_t)hi << 32));
		report_capability(pinbased, 5, lo, hi);

		pr_info("\n");
		
		/* True Procbased controls */
		rdmsr(IA32_VMX_TRUE_PROCBASED_CTLS, lo, hi);
		pr_info("Procbased Controls MSR: 0x%llx\n",
			(uint64_t)(lo | (uint64_t)hi << 32));
		report_capability(procbased, 21, lo, hi);
		
		pr_info("\n");
		
		/* True Exit controls */
		rdmsr(IA32_VMX_TRUE_EXIT_CTLS, lo, hi);
		pr_info("Exit Controls MSR: 0x%llx\n",
			(uint64_t)(lo | (uint64_t)hi << 32));
		report_capability(exit, 11, lo, hi);

		pr_info("\n");
		
		/* True Entry controls */
		rdmsr(IA32_VMX_TRUE_ENTRY_CTLS, lo, hi);
		pr_info("Entry Controls MSR: 0x%llx\n",
			(uint64_t)(lo | (uint64_t)hi << 32));
		report_capability(entry, 9, lo, hi);
	}


}
