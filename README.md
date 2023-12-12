'''
Description: 
Memory Management:
Memory management is the management of the contents of processor memory (or storage). 
Applications and data must be in processor memory before they can be used. As the workload on 
a system increases, memory use also increases. Memory management is concerned with 
optimizing the use of processor memory to try to keep the applications and data that are being 
used in memory. Memory is divided into sections, called frames and allocated contiguously. 
When the process needs them, they must be allocated to the process. Memory is allocated to the 
processes that are in the ready queue. 
We need memory management for following reasons: 
 Memory is a scarce resource. 
 Management of memory hierarchy o Ease of programming 
 Efficient use of memory 
 Multiprogramming
 Security
Memory Allocation: 
Main memory usually divided into two partitions: One for operating system which is usually held 
in lower memory with interrupt vector and user processes held in higher memory. When a process 
requests memory, the process scheduler allocates memory from a block of available memory 
called HOLE which are scattered throughout memory. The algorithms that are used for memory 
allocation are: 
 First Fit: Allocates the first available memory block that is big enough. 
 Best Fit: Allocates the smallest available memory block that is big enough. 
 Worst Fit: Allocates the largest available memory block. 
We have used the first fit algorithm to allocate memory.
De fragmentation: 
Memory is de fragmented by Shuffling processes around to eliminate “holes” in memory space, in 
order to allow new process to be loaded into memory. Defragger itself is a process which takes 
up system resources. It has the whole memory space mutually exclusively, when it’s de 
fragmenting
'''
![EXP-11 Flow Chart](https://github.com/PAWAN-KUMAR-BHAVANASI/OS-SISTK/assets/147645954/a5979669-e282-4521-8583-57b0dfd11a67)
