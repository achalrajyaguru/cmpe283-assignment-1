# CMPE 283 - Virtualization Technologies
## Assignment 3

### Name: Achal Rajyaguru
### ID: 015958670
### Term: Fall22


## Requirements
Have a running copnfiguration from assignment2.

## Tasks completed

- Added feature to detect the time spent inside VMM for processing all exits for CPUID 0x4ffffffd leaf node.
- Created an inner VM and installed required cpuid packages 
- Built and loaded the kernel again for outer VM.
- Tested the feature by running cpuid command in inner VM.
- Captured output in system message log.


## Steps followed:

- sudo make -j 8 modules
- sudo make INSTALL_MOD_STRIP=1 modules_install
- sudo make install
- sudo rmmod kvm_intel" followed by "sudo rmmod kvm
- sudo modprobe kvm
- sudo modprobe kvm_intel
- lsmod | grep kvm
- sudo apt update
- sudo apt install cpu-checker
- kvm-ok
- sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virtinst virt-manager

- sudo systemctl is-active libvirtd
- virt-manager


## Steps for output:

Type the command:

- dmesg


## Observations:

### Least frequent exits happened:

Exit type 0 - Exception or non-maskable interrupt (NMI)
Exit type 7 - Interrupt window
Exit type 28 - Control-register access
Exit type 29 - MOV DR
Exit type 31 - RDMSR
Exit type 40 - PAUSE
Exit type 49 - EPT misconfiguration
Exit type 54 - WBINVD or WBNOINVD
Exit type 55 - XSETBV

### Most frequent exits happened:

Exit type 1 - External Interrupt
Exit type 10 - CPUID
Exit type 12 - HLT
Exit type 30 - I/O instruction
Exit type 32 - WRMSR
Exit type 48 - EPT violation

### Number of exit status:

Nope, the number of exits does not increase at a stable rate.I have a lot exits on External Interrrupt Exit, Interrupt Window Exit, Control-register access exits, and IO Exits(attched some outputs below). In my case, total exits is 515,155 after boot up by using dmesg.


















