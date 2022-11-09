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
 - Simulating the responses to the report's questions.
 - Built all kernel modules and kernel
 - Trouble shooted the errors faced while setting up the environment
 - Setup the Linux system on GCP and accessed it with nomachine desktop app

 2. 

 Before starting the coding portion I decided to try out other options. Initially I started the assignment with GCP by creating an instance and accessing it with nomachine on my desktop. It worked for first 2 days but after a reboot I wasn't able to access the instance from nomachine and was facing a SSH key transfer error. I wasn't able to get it running again so I continued with a different linux system. I dual booted ubuntu into one of my old windows laptop. 

 The linux instance is still active on my GCP account and can be accessed until 10th November. I will mention the steps to remotely access the instance. The installation steps are gonna be independept of the choice of platform. The code with run on both GCP and linux system.


 Steps to access GCP:

 Credentials:
 
 - root user id: achal
 - root user password: macbookpro
 - external ip address: 34.94.23.23
 - internal ip address: 10.168.0.3

 ![alt text](http://url/to/gcpserver.png)
