//binary_initialize
//initialize binary number
//n is the number of bit
//n = 7 in this code
//require 3n+1 cells

//cell 0 to 3n-1: for each bit,
//cell 0, boundary cell, always 1 for looping
//cell 1, the value bit
//cell 2, aux cell for the value, the NOT gate of cell 1

//cell 3n: always 0 for looping

//n times
+>>+>
+>>+>
+>>+>
+>>+>
+>>+>
+>>+>
+>>+>

//final result:
//require 3n+1 cells (continuous)
//initial at cell 0
//final at cell 3n

//"+>>+>+>>+>+>>+>+>>+>+>>+>+>>+>+>>+>"
