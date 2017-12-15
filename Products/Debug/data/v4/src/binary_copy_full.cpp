//binary_copy_full
//copy itself to cell x

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
        
        //remove the boundary cell temporarily
        "-"
        
        //for the bit is one
        {
            {
                //go to the bit cell
                ">"
                //if it is one
                "["
                //set the value to zero, set the boundary cell to true
                "-<+>"
                
                //move right, k = x - (3n+3)
                ">" //k times
                //copy the value
                "+"
                //add boundary
                "<+>"
                
                //move left, k = x - (3n+3)
                "<" //k times
                
                //go to the bit cell
                "]"
            }
            
            {
                //go the boundary cell
                "<"
                //if it is true
                "["
                //set it to false, set the bit cell to one
                "->+<"
                
                //go the boundary cell
                "]"
            }
        }
        
        //for the bit is zero
        {
            {
                //go to the aux bit cell
                ">>"
                //if it is one
                "["
                //set the value to zero, set the boundary cell to true
                "-<<+>>"
                
                //move right, k = x - (3n+3)
                ">" //k times
                //copy the value
                "+"
                //add boundary
                "<<+>>"
                
                //move left, k = x - (3n+3)
                "<" //k times
                
                //go to the aux bit cell
                "]"
            }
            
            {
                //go the boundary cell
                "<<"
                //if it is true
                "["
                //set it to false, set the aux bit cell to one
                "->>+<<"
                
                //go the boundary cell
                "]"
            }
        }
        
        //add back the boundary cell
        "+"
        
        
        // go to next left bit
        "<<<"
        "]"
    }
    //At cell 0
    
    //copy left end 001
    {
        //move right, k = x - (3n+3)
        ">" //k times
        
        //copy
        ">>+<<"
        
        //move left, k = x - (3n+3)
        "<" //k times
    }
    
    //go to 3n+3
    {
        //go to cell 3
        ">>>"
        //if it is not right end
        "["
        //go to the next right bit
        ">>>"
        "]"
    }
}

//final result:
//At cell 3n+3
//k = x - (3n+3)

//"<<<[->[-<+>"
//">" //k times
//"+<+>"
//"<" //k times
//"]<[->+<]>>[-<<+>>"
//">" //k times
//"+<<+>>"
//"<" //k times
//"]<<[->>+<<]+<<<]"
//">" //k times
//">>+<<"
//"<" //k times
//">>>[>>>]"
