//binary_clear
//set the binary number to zero

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
    //go to the leftmost bit
    {
        //go to cell 3n
        "<<<"
        //if it is true
        "["
        // go to next left bit
        "<<<"
        "]"
    }
    
    //go to cell 2
    ">>"
    //set it to zero
    "[-]"
    
    {
        //go to the boundary cell of the next right bit
        ">"
        //for each bit
        //if it is not the right end
        "[-"
        
        //go to the bit cell
        ">"
        //set it to zero
        "[-]"
        
        //go to the aux bit cell
        ">"
        //set it to zero
        "[-]"
        
        // go to next right bit
        ">"
        "]"
        //At cell 3n+3
    }
    
    //set it to zero
    {
        //go to cell 3n+2
        "<"
        //set it to one
        "+"
        //go to cell 3n+3
        ">"
    }
}
