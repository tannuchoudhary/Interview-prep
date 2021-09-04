# 1. What is the main purpose of an operating system? Discuss different types? 

## Purpose:
![Screenshot from 2021-09-04 21-48-49](https://user-images.githubusercontent.com/42698268/132101450-4e4e27d1-2873-4e25-9b66-133a4ae9576e.png)


In any computer, the operating system:

* Controls the backing store and peripherals such as scanners and printers.
* Deals with the transfer of programs in and out of memory.
* Organises the use of memory between programs.
* Organises processing time between programs and users.
* Maintains security and access rights of users.
* Deals with errors and user instructions.
* Allows the user to save files to a backing store.
* Provides the interface between the user and the computer - for example, Windows Vista and Apple OSX. For more information, see the User Interfaces study guide.
* Issues simple error messages.

In short:
An Operating System performs all the basic tasks like managing files, processes, and memory. Thus operating system acts as the manager of all the resources, i.e. resource manager. Thus, the operating system becomes an interface between user and machine
Basically, an Operating System has three main responsibilities:
* Perform basic tasks such as recognizing input from the keyboard, sending output to the display screen, keeping track of files and directories on the disk,
and controlling peripheral devices such as disk drives and printers.
* Ensure that different programs and users running at the same time do no interfere with each other.
* Provide a software platform on top of which other programs can run. 
* The Operating System is also responsible for security and ensuring that unauthorized users do not access the system

## [Types](https://www.geeksforgeeks.org/types-of-operating-systems/)

// upload copy notes and watch the lectures of sanchit jain



# What is a socket, kernel and monolithic kernel ?

## [Socket](https://www.geeksforgeeks.org/socket-in-computer-network/)
A socket is a software object that acts as an end point establishing a bidirectional network communication link between a server-side and a client-side program. In UNIX, a socket can also be referred to as an endpoint for interprocess communication(IPC) within the operating system(OS).

or A socket is one endpoint of a two-way communication link between two programs running on the network. 
## [Kernel](https://www.geeksforgeeks.org/kernel-in-operating-system/)
Kernel is central component of an operating system that manages operations of computer and hardware. It basically manages operations of memory and CPU time. It is core component of an operating system. Kernel acts as a bridge between applications and data processing performed at hardware level using inter-process communication and system calls.

##  [Monolithic Kernel](https://www.geeksforgeeks.org/monolithic-kernel-and-key-differences-from-microkernel/)
It is one of types of kernel where all operating system services operate in kernel space. It has dependencies between systems components. It has huge lines of code which is complex.

Example :

Unix, Linux, Open VMS, XTS-400 etc.
* Advantage :
    * It has good performance.
* Disadvantage :
    * It has dependencies between system component and lines of code in millions.



# 3. Difference between process and program and thread? Different types of process.

## Program
Program is an executable file containing the set of instructions written to perform a specific job on your computer. For example, chrome.exe is an executable file containing the set of instructions written so that we can view web pages. notepad.exe is an executable file containing the set of instructions which help us to edit and print the text files.

Programs are not stored on the primary memory in your computer. They are stored on a disk or a secondary memory on your computer. They are read into the primary memory and executed by the kernel. A program is sometimes referred as passive entity as it resides on a secondary memory.

## Process
Process is an executing instance of a program. For example, When you double click on the Google Chrome icon on your computer, you start a process which will run the Google Chrome program. When you double click on a notepad icon on your computer, a process is started that will run the notepad program.

A process is sometimes referred as active entity as it resides on the primary memory and leaves the memory if the system is rebooted. Several processes may related to same program. For example, you can run multiple instances of a notepad program. Each instance is referred as a process.

## Thread
Thread is the smallest executable unit of a process. For example, when you run a notepad program, operating system creates a process and starts the execution of main thread of that process.

A process can have multiple threads. Each thread will have their own task and own path of execution in a process. For example, in a notepad program, one thread will be taking user inputs and another thread will be printing a document.

All threads of the same process share memory of that process. As threads of the same process share the same memory, communication between the threads is fast.

![Screenshot from 2021-09-04 22-51-41](https://user-images.githubusercontent.com/42698268/132103191-c371f27a-72f3-496e-b494-428fe99c4f08.png)

![Screenshot from 2021-09-04 22-52-41](https://user-images.githubusercontent.com/42698268/132103216-ddb7dbe7-702e-4854-8317-6f9045b31d23.png)

![Screenshot from 2021-09-04 22-53-33](https://user-images.githubusercontent.com/42698268/132103239-f718abac-151c-4264-b1ac-bbd18c398621.png)

# 4. Define virtual memory, thrashing, threads.

## [Virtual memory](https://www.geeksforgeeks.org/virtual-memory-in-operating-system/)
Virtual Memory is a storage allocation scheme in which secondary memory can be addressed as though it were part of main memory. The addresses a program may use to reference memory are distinguished from the addresses the memory system uses to identify physical storage sites, and program generated addresses are translated automatically to the corresponding machine addresses.

## [Thrashing](https://www.geeksforgeeks.org/techniques-to-handle-thrashing/)
Thrashing is a condition or a situation when the system is spending a major portion of its time in servicing the page faults, but the actual processing done is very negligible. 

# 5. What is RAID ? Different types.
RAID, or “Redundant Arrays of Independent Disks” is a technique which makes use of a combination of multiple disks instead of using a single disk for increased performance, data redundancy or both.
They are linked together to prevent data loss and/or speed up performance. Having multiple disks allows the employment of various techniques like disk striping, disk mirroring, and parity

## Why data redundancy? 

Data redundancy, although taking up extra space, adds to disk reliability. This means, in case of disk failure, if the same data is also backed up onto another disk, we can retrieve the data and go on with the operation. On the other hand, if the data is spread across just multiple disks without the RAID technique, the loss of a single disk can affect the entire data. 

## [Types](https://www.geeksforgeeks.org/raid-redundant-arrays-of-independent-disks/)


# 6. What is a deadlock ? Different conditions to achieve a deadlock
In copy 

# 7. What is fragmentation? Types of fragmentation. 

# 8. What is spooling ? 

# 9. What is semaphore and mutex (Differences might be asked)? Define Binary semaphore. 

# 10. Belady’s Anomaly




























