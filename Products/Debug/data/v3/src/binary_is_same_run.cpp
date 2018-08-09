//binary_is_same_run
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
{
    //go to cell 1
    ">"
    //set it to one
    "+"
    //this one will move from the left end to the right end
    //one means two binary numbers are the same
    //zero means two binary numbers are not the same
    
    //go to cell 3
    ">>"
    //for each bit
    //if it is not the right end
    "["
    
    //remove the boundary
    "-"
    
    //if the first bit is one, the boundary cell is NOT gate of itself
    {
        //go to the first bit
        ">"
        //if it is one
        "[-"
        
        //go to the second bit of the left bit
        "<<"
        //the second bit of the left bit is NOT gate of the boundary cell
        "+>[-<->]<"
        //move the second bit of the left bit to the boundary cell
        "[->+<]"
        
        //go to the first bit
        ">>"
        "]"
    }
    
    //if the seocnd bit is one, the boundary cell is NOT gate of itself
    {
        //go to the second bit
        ">"
        //if it is one
        "[-"
        
        //go to the second bit of the left bit
        "<<<"
        //the second bit of the left bit is NOT gate of the boundary cell
        "+>[-<->]<"
        //move the second bit of the left bit to the boundary cell
        "[->+<]"
        
        //go to the second bit
        ">>>"
        "]"
    }
    
    {
        //go to the boundary cell
        "<<"
        //if it is true, this means the two bit are different
        "[-"
        
        //go to the first bit of the left bit
        "<<"
        //remove it
        "[-]"
        
        //go to the boundary cell
        ">>"
        "]"
    }
    
    {
        //go to the first bit of the left bit
        "<<"
        //move the first bit of the left bit to the first bit
        "[->>>+<<<]"
    }
    
    //go to the boundary cell
    ">>"
    //add the boundary
    "+"
    
    // go to next right bit
    ">>>"
    "]"
    //At cell 3n+3
}

//final result:
//initial at cell 0
//final at cell 3n+3
//cell 3n+1 is output

//">+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
