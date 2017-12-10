//binary_clear
//set the binary number to zero

//n is the number of bit
//n = 7 in this code
//require 3n+1 cells

//cell 0 to 3n-1: for each bit,
//cell 0, boundary cell, always 1 for looping
//cell 1, the bit value
//cell 2, aux cell for the value, the NOT gate of cell 1

//cell 3n: always 0 for looping

//At cell 0

{
    //for each bit
    //if it is not the right end
    "["
    
    {
        //go to the value cell
        ">"
        //if it is one
        "["
        //set it to zero
        "->+"
        //go to the value cell
        "<"
        //if it is one
        "]"
    }
    
    // go to next right bit
    ">>"
    "]"
}

//final result:
//At cell 3n
//initial at cell 0
//final at cell 3n
//"[>[->+<]>>]"
