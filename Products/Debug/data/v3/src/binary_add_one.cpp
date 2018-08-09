//binary_add_one
//add the binary number by one

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
    //find the rightmost zero
    {
        //go to cell 3n+1
        "<<"
        //if it is not zero
        "["
        // go to next left bit
        "<<<"
        "]"
    }
    
    //go to the aux bit cell, set it to zero
    ">-"
    
    //if the zero is left end, create one bit at the left
    {
        //go to the boundary cell
        "<<"
        //copy it the bit cell and aux bit cell
        "[->+>+<<]"
        
        //go to the boundary cell
        //the boundary cell is NOT gate of the bit cell
        "+>[-<->]<"
        
        {
            //if the boundary cell is true, this means it is left end
            "[-"
            
            //add boundary
            //go to the aux bit cell (the copy of the original boundary cell)
            ">>"
            //set it to true
            "+"
            
            //go to the aux bit cell of the left bit
            "<<<"
            //set it to one
            "+"
            
            //go to the boundary cell
            ">"
            "]"
        }
        
        //go to the aux bit cell (the copy of the original boundary cell)
        ">>"
        //copy it to the boundary cell
        "[-<<+>>]"
    }
    
    //go to bit cell
    "<"
    //set it to one
    "+"
    
    {
        //go the boundary cell of the right bit
        ">>"
        //if it is not the right end
        "["
        
        //set it to zero
        ">->+>"
        
        //go to the boundary cell of the next right bit
        "]"
        //At cell 3n+3
    }
}

//final result:
//At cell 3n+3
//"<<[<<<]>-<<[->+>+<<]+>[-<->]<[->>+<<<+>]>>[-<<+>>]<+>>[>->+>]"
