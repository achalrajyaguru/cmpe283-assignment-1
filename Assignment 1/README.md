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


 Steps to access GCP (only available until 10th Nov): 

 Credentials:
 
 - root user id: achal
 - root user password: macbookpro
 - external ip address: 34.94.23.23
 - internal ip address: 10.168.0.3

 ![alt text](http://url/to/gcpserver.png)

I have attached a screenshot for the specifications for the isntance if you want to replicate it for yourself in the future. If you wish to access it with NoMachine then make sure to add firewall acceptions in the VPC network security options because the firewall wont allow access to the instance otherwise. I will mention a video link which will help you setup your own GCP instance.

- YouTube video link: https://www.youtube.com/watch?v=UYLA_fFdciA

In the video I have share above the instructor is using an amd system for configuration, for our system we need to setup an x86 based ubuntu, so the only necessary change is to pick an x86 system. YOu will need a NoMachine to access this linux instance. You can skip to 8:56 in the video to start with NoMachine setup.

Steps to access on an intel based laptop with Ubuntu: 

- For this step you need a laptop with Ubuntu installed. After logging into the laptop run the following 3 commands to setup up the laptop for the next steps.

	1. sudo apt-get update
	2. sudo apt-get upgrade
	3. sudo reboot

After this your linux system is ready to run the setup. After reboot you will need to login in to your linux system.


Steps to run the program:

Step-1 : Installing Git

First you will need to install git in your system

- sudo apt-get install git-all

You can also try 

- sudo apt install git

If you already have git on your system then you can type

- git --version

You can reinstall git by using 
- sudo apt-get update

Step-2 : Entering the root user to avoid permission denied issue

Now you will need to be in the base user mode of your linux system. You can do this by typing
- cd

Now enter the root user to make sure you dont get any permission error. Type the command

- sudo -s

To exit the root mode you can type
- exit

Continue to step 3 when you enter the root user mode

Step-3 : Cloning the linux repo 

After the first step you want to clone the linux git repo into your home directory. You can do it by using the below command

- git clone https://github.com/torvalds/linux.git

I am including my edited and configured git repo in my assignment git, but all systems are different and there is a chance that if you download an already configured kernel then it wont work so this is what i will recommend

Cloning the whole git repo will take some time depending on your internet speed. After the cloning is finished, you can type the below code and enter into the folder

- cd linux

After this, we can start the configuration of our linux kernel

Step 4: Install all the important libraries and make changes to the kernel config file

Start installing the below mentioned libraries. While installing them, i faced a few errors . I will mention how i solved them and attach important links and documentation. I am mentioning all the installation code in no particular order out of memory.



- sudo apt-get install libncurses-dev
- 
- sudo apt install htop
- sudo apt-get update
- sudo apt-get upgrade
- sudo apt-get install build-essential
- sudo apt-get install libelf-dev
- sudo apt-get install flex
- sudo apt-get install bison
- sudo apt-get install libncurses5-dev gcc make git exuberant-ctags bc libssl-dev
- sudo apt install dwarves
- make 
(while executing make you may see an error, if so then execute the below code)

- make oldconfig
- make prepare

(while executing make oldconfig you will have to press y on a lot of installation prompts, to avoid this enter the below code, it will automatically answer all the questions)

- yes "" | make oldconfig

Reference Source: https://serverfault.com/questions/116299/automatically-answer-defaults-when-doing-make-oldconfig-on-a-kernel-tree

After this run the below code

- make oldconfig && make prepare

Now, type in

- make menuconfig

It will open a menu. Usually this menu is correct but you want to make sure that Load modules is selected to yes before moving on further. Save the setting in the same .config file and press Esc twice.

- make

- make modules

(There is a chance that you might face a missing certificate error. To solve it, you will have to navigate into the kconfig file in your linux folder. Here you will have to comment out the code for config System_Key_List and config System_key_Rings. Doing this will get rid of the certificate error)

- make modules_install

- make install

- make all

Following these steps has helped me get the results, I have mentioned the 3 big errors which i faced, the libraries which we have installed will help us avoid any future error which i faced during setup and hopefully you wont see them in your system, if you do then google the last 2 lines of the error and you will probably find a solution easily. The Linux community is very big :-)

Step-5 : Coding in C which will help us see the functionalities of MSRs

You can copy paste the code from this repo into your own c file with the below code

- gedit <file_name>.c

This will open up a text file where you can copy paste the code that i have used. 

You can also clone my Assignment 1 Github repo into a different folder and cut+paste the code from my repo. You can use the below code

- cd 
(This will exit you from the linux repo and bring you to base)

- cd Downloads
(Here, you can clone my github repo)

- git clone https://github.com/achalrajyaguru/cmpe283-assignment-1.git

Navigate to the Assignment-1 folder and copy paste the .c file into the linux folder. This will save you more time. By the time this read me is live, tehre will be the linux file as well which will make it a big file to download and might take up space if your try to access it from the GCP so you might run into an out of storage error if your VM is running low on memory so keep that in mind. To avoid this you can also directly download the c code and make file along with the diff file from the git repo.

Step-6: Creating a kernel module to run MSRs

Here, we need to create a Makefile for our kernel. To create it type 

- gedit Makefile

Here, we need to make sure that we are pointing to the object file of the c code. After creating it, paste the make code and save it in the same folder, if there is already a makefile then system will show an error of existing file, just select replace and continue.

Just like c code it will be much faster to download the make file seperately from the git repo.

https://github.com/achalrajyaguru/cmpe283-assignment-1.git

Step-7 :

Here, we need to load the specific kernel module into our kernel. To do so, type the following code

- insmod./msrscode.ko

Step-8: 

Now we need to verify the output from the kernel in the system message log. It is bassically the output for the modules that we ran through our c code. 

- dmseg

This will give us our output in the terminal window which we can then use and verify through the homework pdf that is labeled as Assignment 1.pdf in the Assignment 1 folder in our repo. 

Step-9: Creating a diff file

We create a diff file inorder to compare changes from our original file and new file. They are widely used to get difference between the original file and the updated file.

- git diff HEAD~1 > msrscode.diff
Step-10: Pusing the code to github

Here you can use an external software like GitKraken or Source tree to push the code. The easiest way I have found is to push it with terminal.

- git clone https://github.com/achalrajyaguru/cmpe283-assignment-1.git
- git init
- git add .
- git status
- git commit -m "Your Message"
- git status
- git push

If you have made any changes in the git website simultaneously, then make a pull request by using below code

- git pull

This will help you avoid any merge conflicts.	


That's all for this assignment, if you face any errors then you can contact me on my linkedin page and shoot me a text, I will try to help if I can. What I would recommend is to google the error code first. In linux, if you face an error then there is a 80% chance that the solution is already available on the internet because of how big the community is :-)

















