# Operating Systems Notes

## Contents

* [What is an operating system?](#what-is-an-operating-system)
* [Pipeline approach](#pipeline-approach)
* [Memory hierarchy - registers, cache, RAM, and disks](#memory-registers-cache-ram-and-disks)
    * [Memory registers](#memory-registers)
    * [Cache](#cache)
    * [RAM](#ram)
    * [Disks](#disks)
* [Interrupts](#interrupts)
* [Processes](#processes)
   * [Creation](#creation)
   * [Termination](#termination)
   * [States](#states)
   * [Implementation](#implementation)
* [System calls](#system-calls)
    * [Fork System Call](#fork-system-call)
    * [Process management](#process-management)
* [Operating system structures](#operating-system-structures)
    * [Client-Server model](#client-server-model)
    * [Virtual machines](#virtual-machines)
* [References and resources](#references-and-resources)

## What is an operating system?

An operating system is a layer of software that manages the hardware resources in a computer and provides a base for all of the user software that runs on top of it.

> The main purposes of the operating system is to provide abstractions (create, read, write, delete files) for user programs and manage computer resources.

> An important distinction between the operating system and normal (usermode) software is that if a user does not like a particular email reader, they are free to get a different one or write their own if they choose; they are not free to write their own clock interrupt handler, which is part of the operating system and is protected by hardware against attempts by users to modify it.

## Pipeline approach

In order to improve performance, the older CPU architecture that performed fetching, decoding, and executing one instruction at a time (sequential processing) was replaced. Modern CPUs use the **pipeline** approach for executing the three functions (fetch, decode, execute) in parallel.

## Memory hierarchy - registers, cache, RAM, and disks

Since current technology can't satisfy the goals of having memory that is extremely fast, abundant, and cheap, most systems use a layered hierarchy approach.

![Memory hierarchy](https://github.com/jrliv/notes/blob/master/OperatingSystems/Images/MemoryHierarchy.JPG)

The top layers of the hierarchy are usually the fastest memory with the highest cost and lowest capacity. The bottom layers consist of slower memory that have higher capacity and lower costs.

### Memory registers

Memory registers are individual addressable memory locations within the CPU. The number of registers in a CPU can vary but most general purpose microcomputer CPUs have 18 32-bit registers. 

General registers are reserved and used for storage to hold instructions and results. 

Special purpose registers are useful for programmers. One register is the **program counter** which holds the address of the next instruction to be fetched. The **stack pointer** holds the address of the next memory location that is at the top of the stack. The **Program Status Word** register holds the state or condition of a program. It plays an important role in system calls and I/O operations.

### Cache

> Main memory is divided up into **cache lines**, typically 64 bytes, with addresses 0 to 63 in cache line 0, 64 to 127 in cache line 1, and so on. The most heavily used cache lines are kept in a high-speed cache located inside or very close to the CPU. When the program needs to read a memory word, the cache hardware checks to see if the line needed is in the cache. If it is, called a **cache hit**, the request is satisfied from the cache and no memory request is sent over the bus to the main memory. Cache hits normally take about two clock cycles. 

Cache memory is extremely small and fast. It's usually built into the CPU or on a seperate chip that is beside the CPU. The CPU uses cache memory to store instructions that are repeatedly required so it doesn't have to use the motherboard’s system bus for data transfer. This eliminates the chances of bottlenecks and improves the overall speed of the system.

> In any caching system, several questions come up fairly soon, including:
> 1. When to put a new item into the cache.
> 2. Which cache line to put the new item in.
> 3. Which item to remove from the cache when a slot is needed.
> 4. Where to put a newly evicted item in the larger memory.

Modern CPUs usually consist of two caches; level one cache (L1) and level two cache (L2). **L1 cache** is located inside of the CPU. It sends decoded instructions to the location in the CPU that will execute them. Some CPUs contain two L1 caches so one can send decoded instructions and the other can store recently used memory words. **L2 cache** also stores recently used memory words but it can store several megabytes worth where L1 cache is usually measured in kilobytes. In multicore CPUs, L2 cache can shared or separate among the cores. It's usually shared by all of the cores. Accessing L1 cache can usually be done without any delay. Accessing L2 cache usually consists of a delay of one or two clock cycles.

### RAM

**RAM (Random Access Memory)** is usually considered the *main* memory in a system. It's also known as core memory to some. Most modern computers contain several gigabytes of RAM. Instructions in the CPU that can't be stored or satisfied from the cache will go to main memory.

Along with RAM, most computers also have a small amount of memory called **ROM (Read Only Memory)**. ROM is *non-volatile* memory, meaning it won't lose data when the power to the computer is turned off. On some computers and devices, the bootstrap loader used to start the computer, is contained in the ROM. This design was created by Gary Kildall. ROMs are typically developed at the factory where the device they will be used in is manufactured. They usually can't be changed afterward.

**EEPROM (Electrically Erasable Programmable ROM)** and **flash memory** are other forms of non-volatile memory. Unlike ROMs, they can be changed but writing these changes takes a lot more time than writing RAM, so they are typically used the same way as ROMs. To change EPROMs, they have to be completely erased and rewritten to make changes. Flash memory costs less than EPROMs and it can be changed faster. However, a main disadvantage of flash memory is that it can only be erased and written to a finite amount of times. Flash memory is also used as extended storage. They can be found in personal computers, mobile phones, audio players, digital cameras, video games, etc.

**CMOS (Complimentary Metal-Oxide Semi-conductor)** memory is volatile memory that is used to hold the current time and date in a computer. It's powered by a small battery meant to last several years to give it a non-volatile effect by keeping the time and date updated when the computer is powered off. 

### Disks

A disk is a metal platter that is used in disk drives for storing data. A disk rotates along side other disks in the disk drive while a mechanical arm with a "head" attached on the end goes over the platters (similar to a record player) to read and write data.

> Information is written onto the disk in a series of concentric circles. At any given arm position, each of the heads can read an annular region called a **track**. Together, all the tracks for a given arm position form a **cylinder**. Each track is divided into some number of **sectors**, typically 512 bytes per sector.

## Interrupts

An **interrupt** is a signal that's initiated by an I/O device to signal the completion of an I/O instruction. 

> A device on the bus (a printer, for instance) asserts on the CPU's interrupt line and places the interrupt vector number on the data bus. Using this information, the CPU then gets the printers interrupt service routine and stops its current process, saves its context, jumps to the signaled interrupt service routine, completes that routine, then restores the saved context and continues on with program execution.

> Interrupts can happen at inconvenient times (like when another interrupt handler is running). The CPU can disable interrupts temporarily complete an operation, and then re-enable interrupts to prevent confusion. If multiple devices signal interrupts, static priorities are often assigned to devices allowing the higher priority devices to win.

![I/O Process](https://github.com/jrliv/notes/blob/master/OperatingSystems/Images/IO-Process.JPG)

## Processes

A **process** is essentially a task or a program that is still currently running or executing. It works as a container that holds all of the data needed to run a program. In order to run several applications at once, most operating systems have to manage their processes by stopping, suspending, and restarting them periodically.

> The user may have started a video editing program and instructed it to convert a one-hour video to a certain format (something that can take hours) and then gone off to surf the Web. Meanwhile, a background process that wakes up periodically to check for incoming email may have started running. Thus we have (at least) three active processes: the video editor, the Web browser, and the email receiver. Periodically, the operating system decides to stop running one process and start running another, perhaps because the first one has used up more than its share of CPU time in the past second or two.

> When a process is suspended temporarily like this, it must later be restarted in exactly the same state it had when it was stopped. This means that all information about the process must be explicitly saved somewhere during the suspension. For example, the process may have sev eral files open for reading at once. Associated with each of these files is a pointer giving the current position (i.e., the number of the byte or record to be read next). When a process is temporarily suspended, all these pointers must be saved so that a read call executed after the process is restarted will read the proper data. In many operating systems, all the information about each process, other than the contents of its own address space, is stored in an operating system table called the **process table**, which is an array of structures, one for each process currently in existence.

> Thus, a (suspended) process consists of its address space, usually called the **core image** (in honor of the magnetic core memories used in days of yore), and its process table entry, which contains the contents of its registers and many other items needed to restart the process later.

> The key process-management system calls are those dealing with the creation and termination of processes. Consider a typical example. A process called the **command interpreter** or shell reads commands from a terminal. The user has just typed a command requesting that a program be compiled. The shell must now create a new process that will run the compiler. When that process has finished the compilation, it executes a system call to terminate itself.

Processes can create one or more processes that are called **child processes**. Child processes can create their own child classes as well and so forth. A lot of these related processes will need to work together to get a task done therefore they use **interprocess communication** to communicate with one another.

### Creation

> Four principal events cause processes to be created:
> 1. System initialization. The system boots up and initializes the *init* process.
> 2. Execution of a process-creation system call by a running process.
> 3. A user request to create a new process. Users can create a new process from within a program.
> 4. Initiation and execution of a batch job.

### Termination

> Sooner or later the new process will terminate, usually due to one of the following conditions:
> 1. Normal exit (voluntary).
> 2. Error exit (voluntary).
> 3. Fatal error (involuntary).
> 4. Killed by another process (involuntary).

### States

> Processes are in one of three possible states:
> 1. Running – has the focus of the CPU
> 2. Ready – runnable but temporarily stopped while another process has the focus of the CPU
> 3. Blocked – unable to run until some external event completes

> Logically, the first two states are similar. In both cases the process is willing to run, only in the second one, there is temporarily no CPU available for it. The third state is fundamentally different from the first two in that the process cannot run, even if the CPU is idle and has nothing else to do.

> There are four possible transitions among these three states:

![Process states](https://github.com/jrliv/notes/blob/master/OperatingSystems/Images/ProcessStates.JPG)

### Implementation

> To implement the process model, the OS maintains a data structure called a **process table** with one entry per process. This process table entry contains all the relevant information about the state of the process including its program counter, stack pointer, memory allocation, and anything that must be saved to allow the process to resume if it's switched from running to either ready or blocked state.

Here are some of the fields of a typical process table entry:

![Process table](https://github.com/jrliv/notes/blob/master/OperatingSystems/Images/ProcessTable.JPG)

## System Calls

A system call is a special function or procedure called by the operating system when a user program needs a system service. System calls enter the kernel and provide an interface between a process and the operating system.

> Any single-CPU computer can execute only one instruction at a time. If a process is running a user program in user mode and needs a system service, such as reading data from a file, it has to execute a trap instruction to transfer control to the operating system. The operating system then figures out what the calling process wants by inspecting the parameters. Then it carries out the system call and returns control to the instruction following the system call. In a sense, making a system call is like making a special kind of procedure call, only system calls enter the kernel and procedure calls do not.

### Fork System Call

The **fork()** call is an important system call for process management. It's used to create a new process in UNIX and any other system that used POSIX standards. When called, it creates (*forks*) a copy (child process) of the original process (parent). The processes are seperate. Any changes made to the processes will not affect each other.

As an example, using a similar idea projects in GitHub are often forked in order for one user to get a copy of another user's project and work on it locally.

> The fork call returns a value, which is zero in the child and equal to the child’s **PID (Process IDentifier)** in the parent. Using the returned PID, the two processes can see which one is the parent process and which one is the child process.

> x = fork() 
> 1. What will the value of x be after the fork? **It will either be 0 or the id of the child that got forked.**
> 2. What is the value returned to the parent? **The id of the child.** 
> 3. What is the value returned to the child process that gets created by the fork? **0**

![Process management system calls](https://github.com/jrliv/notes/blob/master/OperatingSystems/Images/ProcessManagementSystemCalls.JPG)

> In most cases, after a fork, the child will need to execute different code from the parent. Consider the case of the shell. It reads a command from the terminal, forks off a child process, waits for the child to execute the command, and then reads the next command when the child terminates. To wait for the child to finish, the parent executes a **waitpid(pid, &statloc, options)** system call, which just waits until the child terminates (any child if more than one exists). Waitpid can wait for a specific child, or for any old child by setting the first parameter to −1. When waitpid completes, the address pointed to by the second parameter, statloc, will be set to the child process’ exit status (normal or abnormal termination and exit value). Various options are also provided, specified by the third parameter. For example, returning immediately if no child has already exited.

> Now consider how fork is used by the shell. When a command is typed, the shell forks off a new process. This child process must execute the user command. It does this by using the **execve(name, argv, environp)** (also called exec) system call, which causes its entire core image to be replaced by the file named in its first parameter. The execve system call can be used to have a compiled program run in the place of the child process that gets forked.

> 1. Why should there always be a wait statement in the parent of a fork? **The parent has to wait for the child to send a signal when it terminates to the parent. If the parent is not alive to receive the signal the child will become a zombie process.**

### Process management

> Processes in UNIX have their memory divided up into three segments: 
> 1. The **text segment** (the program *code*)
> 2. The **data segment** (the variables)
> 3. The **stack segment**

> The data segment grows upward and the stack grows downward. Between them is a gap of unused address space. The stack grows into the gap automatically, as needed, but expansion of the data segment is done explicitly by using a system call **brk**, which specifies the new address where the data segment is to end. This call, however, is not defined by the POSIX standard, since programmers are encouraged to use the **malloc** library procedure in C for dynamically allocating storage, and the underlying implementation of malloc was not thought to be a suitable subject for standardization since few programmers use it directly and it is doubtful that anyone even notices that brk is not in POSIX.

![Process memory segments](https://github.com/jrliv/notes/blob/master/OperatingSystems/Images/ProcessMemorySegments.JPG)

## Operating system structures

### Client-Server Model

The client-server model involves using **servers** to provide services and **clients** that use the services. To use the services clients connect to the servers to send messages (data and requests) back and forth. The model can be used for a single computer or for multiple computers that can act as clients and servers on a network.

### Virtual machines

A virtual machine is an emulation of a computer running an operating system within another computer. It provides the functionality of a physical computer.

> Virtualization has been around since the 1970’s and IBM pioneered its use on mainframe systems.

> The VM/370 from IBM provides multiple exact copies of bare hardware machines including kernel/user mode, I/O, interrupts and everything else resident on a physical “real” machine. Each of these “virtual machines” being identical in hardware can run any operating system that can run directly on “real” hardware.

![Virtual machine model](https://github.com/jrliv/notes/blob/master/OperatingSystems/Images/VM-Model.JPG)

> Virtualization permits running multiple separate virtual machines on a single physical core machine, each virtual appears to be a complete machine. Virtualization also allows multiple OS’s to run on the same physical machine simultaneously (Linux, Windows, etc.).

> Early implementations on Pentium CPU’s ran into issues because of the requirement for hardware trapping could not be supplied. VMware originated at Stanford and was developed to address this issue. It was eventually commercialized.

## References and resources

* [Modern Operating Systems (4th Edition)](https://www.amazon.com/Modern-Operating-Systems-Andrew-Tanenbaum/dp/013359162X)
* [Operating System Tutorial](http://www.tutorialspoint.com/operating_system/)
* [Computer Operating Systems](https://www.computerhope.com/os.htm)
* [Operating system - Wikipedia](https://en.wikipedia.org/wiki/Operating_system)

---------------------------------------------------------------------------------
[Back to top](#operating-systems-notes)