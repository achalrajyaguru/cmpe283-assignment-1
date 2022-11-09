# CMPE 283 - Virtualization Technologies
## Assignment 1

### Name: Achal Rajyaguru
### ID: 015958670
### Term: Fall22

#### Questions:

1. For each member in your team, provide 1 paragraph detailing what parts of the lab that member implemented / researched. (You may skip this question if you are doing the lab by yourself).

2. Describe in detail the steps you used to complete the assignment. Consider your reader to be someone skilled in software development but otherwise unfamiliar with the assignment. Good answers to this question will be recipes that someone can follow to reproduce your development steps.

#### Answers:

 1. 
 
 - Created a local clone of the Linux Kernel by downloading and building the necessary modules and libraries.
 - Added the custom logic to the cmpe283-1.c code in order to enable our system to read and output the capabilities of the various MSRs.
 - After importing the module and outputting the kernel buffer, I staged and committed the cmpe283-1.c code file and Makefile.
 - Created a thorough diff file was created when the modifications were committed to the repository.
 - Tested the device to see whether it could recognize features and support VMX virtualization.
 - Tested and confirmed the code's functioning by contrasting it with the example output provided.