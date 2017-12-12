//binary_initialize
//initialize binary number to zero

//n is the number of bit
//require 3n+4 cells

//cell 0: boundary cell, always 0
//cell 1: the bit value is always 0
//cell 2: the aux bit value is always 1

//cell 3 to 3n+2: for each bit,
//cell 3: boundary cell, always 1 for looping
//cell 4: the bit value
//cell 5: aux cell for the value, the NOT gate of cell 1

//cell 3n: 0 means the binary number is zero, 1 means the binary number is not zero
//cell 3n+3: boundary cell, always 0

//At cell 3n+3
{
    //go to cell 3n+2, set it to one
    "<+"
}

//go to cell 3n+3
">"

//final result:
//require 3n+4 cells (continuous)
//At cell 3n+3

//"<+>"
