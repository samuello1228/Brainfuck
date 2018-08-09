//binary_move_half
//only move the bit value to cell x

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
    //go to 3n
    "<<<"
    
    //for each bit, up to the leftmost bit
    {
        //if it is true
        "["
        
        {
            //go to the bit cell
            ">"
            //if it is one
            "[-"
            
            //move right 2 times
            ">>"
            
            //move right, k = x - (3n+3)
            ">" //k times
            //copy the value
            "+"
            //move left, k = x - (3n+3)
            "<" //k times
            
            //move left 2 times
            "<<"
            
            //go to the bit cell
            "]"
        }
        
        {
            //go to the aux bit cell
            ">"
            //remove it
            "[-]"
        }
        
        // go to next left bit
        "<<<<<"
        "]"
    }
    //At cell 0
    
    {
        //go to cell 2
        ">>"
        //remove it
        "-"
    }
    
    //go to 3n+3
    {
        //go to cell 3
        ">"
        //if it is not right end
        "[-"
        //go to the next right bit
        ">>>"
        "]"
    }
    
    {
        //go to cell 3n+2
        "<"
        //set it to one
        "+"
        //go to cell 3n+3
        ">"
    }
    //At cell 3n+3
}

//final result:
//At cell 3n+3
//k = x - (3n+3)

//"<<<[>[->>"
//">" //k times
//"+"
//"<" //k times
//"<<]>[-]<<<<<]>>->[->>>]<+>"
