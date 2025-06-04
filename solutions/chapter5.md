# Exercise 1
## A
First I check if the added code is something restricted to a new feature or is is 
deeply integrated into the base architecture. Analyzing what functionalities 
are implemented (new features built on top of existing code or change in the 
base infrastucture). Then I will proceed to sampling profiling restricted on the new code trying to have a top overview of the process (DAG, where are the hotspots). Repeat the process with more invasive profile both hardware and OS based.  

## B
Trying to collect data of the specific transactions and build a graph of computations
to check the path for performance problems.

## C 
For this scenario we need a more low level approach, analyzing $\mu$ ops checking 
if every pipeline slots is utilized, check stalls from frontend or backend, 
vectorization of the code (analyze assembly), check number of cache misses
and branch miss prediction.  
First run a benchmark for each algorithm and collect the metrics.   
We can start to look at the IPC, number of cache miss and branch predictions,
latency and throughput.    
After this stage, based on the results (maybe low IPC, maybe memory bound) we can
start profile the code at a lower level.  






