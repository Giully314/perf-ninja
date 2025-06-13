# Exercise 3
On my machine, prefetching ahead with 32 gives the best results while starting from 64 the performance get worst. This could be beacuse we load
values on memory too early and probably get discarded during the other iterations of the loop.

# Exercise 4
The memory pattern should be "predictable". Usually contigous data is the most predictable but also other patterns can be 
cache friendly. Two of the majors problems for cache is to not use the entire cacheline and to load data from ram in a random way.  