# Operating Systems Notes

These are my random notes on operating systems in general. There may be some notes more related to some systems vs others but they are meant to be ideas related to operating systems in general. If I create notes that are more related and detailed to a specific system then I will create a seperate folder for them inside of the `OperatingSystems` folder.

## Contents

* [What is an operating system?](#what-is-an-operating-system)
* [Pipeline approach](#pipeline-approach)
* [Memory registers, cache, RAM, and disks](#memory-registers-cache-ram-and-disks)
    * [Memory registers](#memory-registers)
    * [Cache](#cache)

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

Special purpose registers are useful for programmers. One register is the **program counter** which holds the address of the next instruction to be fetched. The **stack pointer** holds the address of the next memory location that is at the top of the stack. The **Program Status Word** register holds the state or condition of a program. It plays an important role in system calls and I/O.

### Cache



## References and resources

* [Modern Operating Systems (4th Edition)](https://www.amazon.com/Modern-Operating-Systems-Andrew-Tanenbaum/dp/013359162X)