# Exercise 1
## Inline function
Passing an object instead of a pointer to a function for the comparator, allow the compiler to see the code
and inline the comparator function. This reduce the overhead caused by prologue and epilogue of function call and 
allow to perform other optimization in the code itself. Also the C++ library is in header files so the code is available to the compiler
(opposite to linking with external binary library).  


## Loop blocking
Higher utilization of first level cache improves performance. With the loop tiling approach, we divide the main computation in smaller blocks to fit in L1 cache.  From my analysis the optimal block size is 16.  
We can also use a cache oblivious algorithm as described [here](https://en.wikipedia.org/wiki/Cache-oblivious_algorithm#Examples).  