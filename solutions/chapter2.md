# Exercise 1
No, it's not safe to take a mean to determine the running time of a program
because we can have high variance, outliers and so on. The box plot is the optimal
strategy to have a clear picture of the distribution of the running time.

# Exercise 2
I would do some warmup of the system while also trying to minimize the number
of processes that run (potentially to 0). In this way we can reduce the number 
of memory swaps, cache stuff and context switch.

# Exercise 3
No, unit test must be used to ensure correctness of the program and are not
related to performance. 
