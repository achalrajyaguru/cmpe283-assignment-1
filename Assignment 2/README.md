# CMPE 283 - Virtualization Technologies
## Assignment 2

### Name: Achal Rajyaguru
### ID: 015958670
### Term: Fall22


## Tasks completed:

1. Added feature to detect the time spent inside VMM for processing all exits for CPUID 0x4ffffffe leaf node.
2. Built and loaded the kernel again for outer VM.
3. Tested the feature by running cpuid command in inner VM.
4. Captured output in system message log.
5. Added feature to detect total number of exits for CPUID 0x4fffffff leaf node.
6. Created an inner VM and installed required cpuid packages 
7. Built and loaded the kernel again for outer VM.
8. Tested the feature by running cpuid command in inner VM.
9. Captured output in system message log.
10. Created an inner VM and installed required cpuid packages
## Steps to follow:

- sudo make -j 8 modules
- sudo make INSTALL_MOD_STRIP=1 modules_install
- sudo make install
- sudo rmmod kvm_intel" followed by "sudo rmmod kvm
- sudo modprobe kvm
- sudo modprobe kvm_intel
- lsmod | grep kvm

Created an Ubuntu VM instance inside existing VM by installing virtual manager using following command

- sudo apt update
- sudo apt install cpu-checker
- kvm-ok
- sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virtinst virt-manager

- sudo systemctl is-active libvirtd
- virt-manager


















