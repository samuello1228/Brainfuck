//remove line comment (remove any character between / and newline)
//output all characters between quotes (if it is not line comment)

//include NOT_gate
//include binary_initialize
//include binary_add_one
//include binary_clear
//include binary_copy_half
//include binary_is_same

//cell 0 to 24: is_same; 7 bit
">>>+>>>+>>>+>>>+>>>+>>>+>>>+>>>"

//cell 25 to 49: input; 7 bit
">"
">>>>>>>>>>>>>>>>>>>>>>>+>"

//cell 50: input cell (copy)
//cell 51: input cell (zero after copying)
">>"

//cell 52: bool for the case that the input character is not line comment and outside quote
//cell 53: aux cell for cell 52 (continues; not redo any 52 bool if block)
//cell 54: aux cell for cell 52 (do other 52 bool if block)
">+"

//cell 55: bool for the case that the input character is not line comment and inside quote
//cell 56: aux cell for cell 55 (continues; not redo any 55 bool if block)
//cell 57: aux cell for cell 55 (do other 55 bool if block)

//cell 58: bool for the case that the input character is line comment
//cell 59: aux cell for cell 58 (continues; not redo any 58 bool if block)
//cell 60: aux cell for cell 58 (do other 58 bool if block)

//fill the value of input
{
    //go to cell 51
    "<"
    //get input
    ","
}

//while(input)
{
    //At cell 51
    //if input is not zero
    "["
    
    //copy it to cell 50 and binary number (cell 49)
    {
        "[-<+"
        //go to input (cell 49)
        "<"
        //add one
        "<<[<<<]>-<<[->+>+<<]+>[-<->]<[->>+<<<+>]>>[-<<+>>]<+>>[>->+>]"
        
        //go to cell 51
        ">>"
        "]"
    }
    
    //For the case that the input character is not line comment and outside quote
    {
        //go to cell 52
        ">"
        //if cell 52 is true
        "[-"
        
        //check whether the input is /
        {
            {
                //go to input (cell 49)
                "<<<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "<<<[->[-<+>>>"
                
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<"
                
                "+"
                
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>"
                
                "<<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                //set to 47 for / (00101111)
                "+"
                ">>>"
                ">>>+"
                ">>>+"
                ">>>+"
                ">>>+"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                //run is_same
                ">+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "<<"
            //copy it to cell 23 and 24
            "[->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "+>[-<->]<"
            
            {
                //For the case that input is /
                //go to if bool cell (cell 24)
                ">>"
                "[-"
                
                //go to aux bool cell 59 (add 35)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>"
                
                //set aux bool cell 59 to true
                "+"
                //change to the case that the input character is line comment
                
                //go to cell 24 (minus 35)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<"
                "]"
            }
            
            {
                //For the case that input is not /
                //go to else bool cell 22
                "<<"
                "[-"
                
                //go to aux bool cell 54 (add 32)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>"
                
                //set aux bool cell 54 to true
                "+"
                //For running the following case that the input character is not line comment
                //Further check whether the input character is quote
                
                //go to cell 22 (minus 32)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                "]"
            }
        }
        
        //go to cell 52 (add 30)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        "]"
    }
    
    //For further checking whether the input character is quote, if cell 54 is true
    {
        //go to aux bool cell 54
        ">>"
        //if cell 54 is true
        "["
        //set aux bool cell 54 to false
        "-"
        
        //go to aux bool cell 52
        "<<"
        //set aux bool cell 52 to true
        "+"
        
        //go to aux bool cell 54
        ">>"
        "]"
    }
    
    //For further checking whether the input character is quote
    {
        //go to cell 52
        "<<"
        //if cell 52 is true
        "[-"
        
        //check whether the input is quote
        {
            {
                //go to input (cell 49)
                "<<<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "<<<[->[-<+>>>"
                
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<"
                
                "+"
                
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>"
                
                "<<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                //set to 34 for quote (00100010)
                "+"
                ">>>"
                ">>>"
                ">>>"
                ">>>+"
                ">>>"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                //run is_same
                ">+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "<<"
            //copy it to cell 23 and 24
            "[->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "+>[-<->]<"
            
            {
                //For the case that input is quote
                //go to if bool cell (cell 24)
                ">>"
                "[-"
                
                //go to aux bool cell 56 (add 32)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>"
                
                //set aux bool cell 56 to true
                "+"
                //change to the case that the input character is not line comment and inside quote
                
                //go to cell 24 (minus 32)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                "]"
            }
            
            {
                //For the case that input is not quote
                //go to else bool cell 22
                "<<"
                "[-"
                
                //go to aux bool cell 53 (add 31)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">"
                
                //set aux bool cell 53 to true
                "+"
                //change to the case that the input character is not line comment and outside quote
                
                //go to cell 22 (minus 31)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<"
                "]"
            }
        }
        
        //go to cell 52 (add 30)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        "]"
    }
    
    //For the case that the input character is line comment
    {
        //go to cell 58
        ">>>>>>"
        //if cell 58 is true
        "[-"
        
        //check whether the input is newline
        {
            {
                //go to input (cell 49)
                "<<<<<<<<<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "<<<[->[-<+>>>"
                
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<"
                
                "+"
                
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>"
                
                "<<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 13 (minus 36)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<"
                
                //set to 10 for newline (00001010)
                "+"
                ">>>"
                ">>>+"
                ">>>"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                //run is_same
                ">+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "<<"
            //copy it to cell 23 and 24
            "[->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "+>[-<->]<"
            
            {
                //For the case that input is newline
                //go to if bool cell (cell 24)
                ">>"
                "[-"
                
                //go to aux bool cell 53 (add 29)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>"
                
                //set aux bool cell 53 to true
                "+"
                //change to the case that the input character is not line comment and outside quote
                
                //go to cell 24 (minus 29)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<"
                "]"
            }
            
            {
                //For the case that input is not newline
                //go to else bool cell 22
                "<<"
                "[-"
                
                //go to aux bool cell 59 (add 37)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>"
                
                //set aux bool cell 59 to true
                "+"
                //change to the case that the input character is line comment
                
                //go to cell 22 (minus 37)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<"
                "]"
            }
        }
        
        //go to cell 58 (add 36)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>"
        "]"
    }
    
    //For the case that the input character is not line comment and inside quote
    {
        //go to cell 55
        "<<<"
        //if cell 55 is true
        "[-"
        
        //check whether the input is quote
        {
            {
                //go to input (cell 49)
                "<<<<<<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "<<<[->[-<+>>>"
                
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<"
                
                "+"
                
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>"
                
                "<<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                //set to 34 for quote (00100010)
                "+"
                ">>>"
                ">>>"
                ">>>"
                ">>>+"
                ">>>"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                //run is_same
                ">+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
            
        }
        
        {
            //go to the compare result (cell 22)
            "<<"
            //copy it to cell 23 and 24
            "[->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "+>[-<->]<"
            
            {
                //For the case that input is quote
                //go to if bool cell (cell 24)
                ">>"
                "[-"
                
                //go to aux bool cell 53 (add 29)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>"
                
                //set aux bool cell 53 to true
                "+"
                //change to the case that the input character is not line comment and outside quote
                
                //go to cell 24 (minus 29)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<"
                "]"
            }
            
            {
                //For the case that input is not quote
                //go to else bool cell 22
                "<<"
                "[-"
                
                //go to constant value cell for input (cell 50) (add 28)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>"
                //output
                "."
                
                //go to aux bool cell 56
                ">>>>>>"
                //set aux bool cell 56 to true
                "+"
                //change to the case that the input character is not line comment and inside quote
                
                //go to cell 22 (minus 34)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<"
                "]"
            }
        }
        
        //go to cell 55 (add 33)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>"
        "]"
    }
    
    //reset all bool cells
    {
        //go to aux cell 53
        "<<"
        //if cell 53 is true; set cell 53 to false; set cell 52 to true
        "[-<+>]"
        
        //go to aux cell 56
        ">>>"
        //if cell 56 is true; set cell 56 to false; set cell 55 to true
        "[-<+>]"
        
        //go to aux cell 59
        ">>>"
        //if cell 59 is true; set cell 59 to false; set cell 58 to true
        "[-<+>]"
    }
    
    //update the value of input
    {
        //go to input (cell 49) (minus 10)
        "<<<<<<<<<<"
        //clear
        "<<<[<<<]>>[-]>[->[-]>[-]>]<+>"
        
        //go to cell 50
        ">"
        //clear
        "[-]"
        
        //go to cell 51
        ">"
        //get input
        ","
    }
    
    //end while loop
    "]"
}
