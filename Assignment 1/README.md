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


 <u> Steps to access GCP (only available until 10th Nov): </u>

 Credentials:
 
 - root user id: achal
 - root user password: macbookpro
 - external ip address: 34.94.23.23
 - internal ip address: 10.168.0.3

 ![alt text](http://url/to/gcpserver.png)

I have attached a screenshot for the specifications for the isntance if you want to replicate it for yourself in the future. If you wish to access it with NoMachine then make sure to add firewall acceptions in the VPC network security options because the firewall wont allow access to the instance otherwise. I will mention a video link which will help you setup your own GCP instance.

- YouTube video link: https://www.youtube.com/watch?v=UYLA_fFdciA

In the video I have share above the instructor is using an amd system for configuration, for our system we need to setup an x86 based ubuntu, so the only necessary change is to pick an x86 system. YOu will need a NoMachine to access this linux instance. You can skip to 8:56 in the video to start with NoMachine setup.

<u> Steps to access on an intel based laptop with Ubuntu: </u>

- For this step you need a laptop with Ubuntu installed. After logging into the laptop run the following 3 commands to setup up the laptop for the next steps.

	1. sudo apt-get update
	2. sudo apt-get upgrade
	3. sudo reboot

After this your linux system is ready to run the setup.


Steps to 


