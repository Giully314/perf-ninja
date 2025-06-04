# Exercise 1
The core clock counts the real number of clocks of the CPU (dynamic frequency 
scaling). The reference clock counts at the base frequency.   

# Exercise 2
A retired instruction is commited to the memory after its execution.  
The difference is that after computing (execution) an instruction, based on
its origin (speculative or normal), the CPU sometime must wait other results
before commit to the memory (retire).  

# Exercise 3
The IPC stays the same. The frequency is related to the number of cycles executed
in a unit of time, while the Instruction Per Cycle (IPC) is the number of 
instruction retired each cycle (which depends on the width of the pipeline).  

# Exercise 4
The 64 in the formula should be for addressing the cacheline size.

# Capacity planning
I'm not going to do the full exercise with hardware pieces and cost; I'm going
to show only how I would approach this problem.  

