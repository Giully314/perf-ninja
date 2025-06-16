# Exercise 1
## Inline function
Passing an object instead of a pointer to a function for the comparator, allow the compiler to see the code
and inline the comparator function. This reduce the overhead caused by prologue and epilogue of function call and 
allow to perform other optimization in the code itself. Also the C++ library is in header files so the code is available to the compiler
(opposite to linking with external binary library).  