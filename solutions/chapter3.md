# Exercise 1
1) Pipeline is the decomposition of an action into smaller actions. Applied 
to CPU, this implies to divide the execution of an instruction into 
multiple steps like: Fetch, Decode, Execute, Write back. This means
that while an instruction is at the decode stage, we can fetch another instruction maximizing hardware utilization and instruction throughput.  
2) Out-of-order(OOO) is the ability to execute instructions in a different 
order while keeping the same semantic.  
3) Speculatice execution execute an instruction in a speculative way
without waiting for control flow results. This improves performance
while avoid to block the pipeline.  

# Exercise 2
Register renaming speed up execution by avoiding the problem of data hazard: write after read, read after write and write after write.  

# Exercise 3
Spatial locality refers to the property of accessed data to be (usually) 
compacted in the same memory region. If a data access is done, probably the
next will be around the same address.  
Temporal locality referes to the property of accessed data to be referred 
again in the near future.  

# Exercise 4
The size of the cache line in most processors is 64 bytes.

# Exercise 5
The CPU frontend executes functionalities related to instruction fetching and 
decoding. The main components are: Pre-decode instruction fetch, instruction queue, 
instruction decoding, branch prediction unit, micro-op cache and decoded queue.  
These components feed micro-op to the backend. It's important to note that the 
front-end operats on ordered instructions while the micro-op passed to the backend
can take advantage of OOO.  
The backend is composed of 3 main area: 
1) OOO engine
2) execution engine
3) load-store unit. 

The OOO engine has Reorder Buffer (ROB) and a Reserve stations (RS) as main 
components. The ROB is a circular buffer (FIFO) of micro-op which tracks the status 
of every instruction and it is also responsible of data hazard protection.  
The RS allows register renaming and instruction input waiting. 
These hardware 2 components are essential for the implementation of the Tomasulo
algorithm for OOO execution.   

The Execution engine is composed of registers, ALU and other hardware specific
for the execution of the instructions.  

The load-store unit is responsible of every load-store memory operation 
including virtual address translation (assisted by TLB).  

# Exercise 6
A 4-level page table is organized into a tree of set of pages, one level per 
level page. For example we could have an address of 64 bits splitted into  
1 level  &nbsp; &nbsp; &nbsp; 2 level &nbsp; &nbsp; 3 level  &nbsp; offset  
63 ... 47  46 ... 30  29 ... 13  12 ... 0  

A page fault occurs when the page is not in the RAM. This can occur when the OS 
put the page into the disk.  

# Exercise 7
4KB on x86 and 16KB on ARM.  

# Exercise 8
The TLB is a cache for pages. Instead of tree walking every level of the pages 
to find the physical address, TLB caches this result directly.  
