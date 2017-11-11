# Operating Systems Notes

These are my random notes on operating systems in general. There may be some notes more related to some systems vs others but they are meant to be ideas related to operating systems in general. If I create notes that are more related and detailed to a specific system then I will create a seperate folder for them inside of the `OperatingSystems` folder.

## Contents

* [What is an operating system?](#what-is-an-operating-system)
* [Pipeline approach](#pipeline-approach)
* [Memory hierarchy - registers, cache, RAM, and disks](#memory-registers-cache-ram-and-disks)
    * [Memory registers](#memory-registers)
    * [Cache](#cache)
    * [RAM](#ram)
    * [Disks](#disks)
* [Interrupts](#interrupts)
* [References and resources](#references-and-resources)

## What is an operating system?

An operating system is a layer of software that manages the hardware resources in a computer and provides a base for all of the user software that runs on top of it.

> An important distinction between the operating system and normal (usermode) software is that if a user does not like a particular email reader, he† is free to get a different one or write his own if he so chooses; he is not free to write his own clock interrupt handler, which is part of the operating system and is protected by hardware against attempts by users to modify it.

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

### Interrupts

> An **interrupt** is initiated by an I/O device. A device on the bus (a printer, for instance) asserts on the CPU's interrupt line and places the interrupt vector number on the data bus. Using this information the CPU can get the printers interrupt service routine stops its current process, save its context, jumps to the signaled interrupt service routine, completes that routine, restores the saved context and then continues on with program execution.

> Interrupts can happen at inconvenient times (another interrupt handler is running). The CPU can disable interrupts temporarily complete and operation, and re-enable interrupts to prevent confusion. If multiple devices signal interrupts, static priorities are often assigned to devices and higher priority devices win.

*Start back on 1.5.1 Processes*

## References and resources

* [Modern Operating Systems (4th Edition)](https://www.amazon.com/Modern-Operating-Systems-Andrew-Tanenbaum/dp/013359162X)
* [Operating System Tutorial](http://www.tutorialspoint.com/operating_system/)
* [Computer Operating Systems](https://www.computerhope.com/os.htm)
* [Operating system - Wikipedia](https://en.wikipedia.org/wiki/Operating_system)

---------------------------------------------------------------------------------
[Back to top](#operating-systems-notes)