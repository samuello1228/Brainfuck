//binary_add_one
//add the binary number by one

//n is the number of bit
//n = 7 in this code
//require 3n+1 cells

//cell 0 to 3n-1: for each bit,
//cell 0, boundary cell, always 1 for looping
//cell 1, the bit value
//cell 2, aux cell for the value, the NOT gate of cell 1

//cell 3n: always 0 for looping

//initialize the binary
"+>>+>+>>+>+>>+>+>>+>+>>+>+>>+>+>>+>"
//At cell 3n = 21

{
    //find the rightmost zero
    {
        //go to cell 3n-2 = 19
        "<<"
        //if it is not zero
        "["
        // go to next left bit
        "<<<"
        "]"
    }
    
    //set the rightmost zero to one
    "+>-"
    
    {
        //go the right boundary cell
        ">"
        //if it is not the right end
        "["
        //set it to zero
        ">->+>"
        "]"
        //At cell 3n = 21
    }
}

//final result:
//At cell 3n

//"<<[<<<]+>->[>->+>]"
