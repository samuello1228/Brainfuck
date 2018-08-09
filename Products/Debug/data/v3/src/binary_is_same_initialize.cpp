//binary_is_same_initialize
//check whether two binary numbers are the same

//n is the number of bit
//n = 7 in this code
//require 3n+4 cells

//cell 0: boundary cell, always 0
//cell 1: reserved for calculation
//cell 2: reserved for calculation

//cell 3 to 3n+2: for each bit,
//cell 3: boundary cell, always 1 for looping
//cell 4: the first bit value
//cell 5: the second bit value

//cell 3n+3: boundary cell, always 0
//cell 3n+1: bool output whether two binary numbers are the same

//At cell 0
">>>"
"+>>>"
"+>>>"
"+>>>"
"+>>>"
"+>>>"
"+>>>"
"+>>>"

//final result:
//initial at cell 0
//final at cell 3n+3
//">>>"
//"+>>>"
//"+>>>"
//"+>>>"
//"+>>>"
//"+>>>"
//"+>>>"
//"+>>>"
