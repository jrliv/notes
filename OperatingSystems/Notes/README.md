# Operating Systems Notes

These are my random notes on operating systems in general. There may be some notes more related to some systems vs others but they are meant to be ideas related to operating systems in general. If I create notes that are more related and detailed to a specific system then I will create a seperate folder for them inside of the `OperatingSystems` folder.

## Contents

* [What is an operating system?](#what-is-an-operating-system)
* [Pipeline approach](#pipeline-approach)
* [Memory registers, cache, RAM, and disks](#memory-registers-cache-ram-and-disks)
    * [Memory registers](#memory-registers)
    * [Cache](#cache)
    * [RAM](#ram)
    * [Disks](#disks)

## What is an operating system?

An operating system is a layer of software that manages the hardware resources in a computer and provides a base for all of the user software that runs on top of it.

> An important distinction between the operating system and normal (usermode) software is that if a user does not like a particular email reader, he† is free to get a different one or write his own if he so chooses; he is not free to write his own clock interrupt handler, which is part of the operating system and is protected by hardware against attempts by users to modify it.

## Pipeline approach

In order to improve performance, the older CPU architecture that performed fetching, decoding, and executing one instruction at a time (sequential processing) was replaced. Modern CPUs use the **pipeline** approach for executing the three functions (fetch, decode, execute) in parallel.

## Memory registers, cache, RAM, and disks

Since current technology can't satisfy the goals of have memory that is extremely fast, abundant, and cheap, most systems use a layered hierarchy approach.

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

**RAM (Random Access Memory)** is usually considered the main memory in a system.

>  All CPU requests that cannot be satisfied out of the cache go to main memory.

> In addition to the main memory, many computers have a small amount of nonvolatile random-access memory. Unlike RAM, nonvolatile memory does not lose
its contents when the power is switched off. ROM (Read Only Memory) is programmed at the factory and cannot be changed afterward. It is fast and inexpensive. On some computers, the bootstrap loader used to start the computer is contained in ROM. Also, some I/O cards come with ROM for handling low-level device control.

> EEPROM (Electrically Erasable PROM) and flash memory are also nonvolatile, but in contrast to ROM can be erased and rewritten. However, writing
them takes orders of magnitude more time than writing RAM, so they are used in
the same way ROM is, only with the additional feature that it is now possible to
correct bugs in programs they hold by rewriting them in the field.

> Flash memory is also commonly used as the storage medium in portable electronic devices. It serves as film in digital cameras and as the disk in portable music
players, to name just two uses. Flash memory is intermediate in speed between
RAM and disk. Also, unlike disk memory, if it is erased too many times, it wears
out.

> Yet another kind of memory is CMOS, which is volatile. Many computers use
CMOS memory to hold the current time and date. The CMOS memory and the
clock circuit that increments the time in it are powered by a small battery, so the
time is correctly updated, even when the computer is unplugged. The CMOS memory can also hold the configuration parameters, such as which disk to boot from.
CMOS is used because it draws so little power that the original factory-installed
battery often lasts for several years. However, when it begins to fail, the computer
can appear to have Alzheimer’s disease, forgetting things that it has known for
years, like which hard disk to boot from.

### Disks



## References and resources

* [Modern Operating Systems (4th Edition)](https://www.amazon.com/Modern-Operating-Systems-Andrew-Tanenbaum/dp/013359162X)