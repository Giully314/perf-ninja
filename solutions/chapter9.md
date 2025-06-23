# Exercise 1
## Inline function
Passing an object instead of a pointer to a function for the comparator, allow the compiler to see the code
and inline the comparator function. This reduce the overhead caused by prologue and epilogue of function call and 
allow to perform other optimization in the code itself. Also the C++ library is in header files so the code is available to the compiler
(opposite to linking with external binary library).  


## Loop blocking
Higher utilization of first level cache improves performance. With the loop tiling approach, we divide the main computation in smaller blocks to fit in L1 cache.  From my analysis the optimal block size is 16.  
We can also use a cache oblivious algorithm as described [here](https://en.wikipedia.org/wiki/Cache-oblivious_algorithm#Examples).  


## Loop interchange 1
Sequantial memory access by swapping nested loops allows to use the whole cache and 
to prefetch data from RAM more easily.  

## Loop interchange 2
The solution is basically given in the introduction video. We can call the 
technique used "lift and memoize". The idea is to lift the accumulation variable
into the upper loop and make it an array. Then we can apply the init, accumulate and save
steps by dividing them into independent loop. We can repeat these step for more nested 
loop and finally we can switch the order of the loops.



# Exercise 2
Use the compiler optimization report to check if vectorization were performed or not (and why). Also tools like Intel VTune reports if the vectorization it's being used or not. 

# Exercise 4
Function inlining. This will allow to remove the overhead of function prologue/epilogue
and enhance optimization opportunities for the compiler.  
