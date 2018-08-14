//remove line comment (remove any character between / and newline)
//output all characters between quotes (if it is not line comment)

//changes: add the code for the case that the second argument is read

//include NOT_gate
//include binary_initialize
//include binary_add_one
//include binary_subtract_one
//include binary_clear
//include binary_copy_half
//include binary_is_same

//cell 0 to 24: is_same; 7 bit
"1 >>>+>>>+>>>+>>>+>>>+>>>+>>>+>>>"

//cell 25 to 49: input; 7 bit
"1 >"
"1 >>>>>>>>>>>>>>>>>>>>>>>+>"

//cell 50: input cell (copy)
//cell 51: input cell (zero after copying)
"1 >>"

//cell 52: bool for the case that the input character is not line comment and outside quote
//cell 53: aux cell for cell 52 (continues; not redo any 52 bool if block)
//cell 54: aux cell for cell 52 (do other 52 bool if block)
"1 >+>>"

//cell 55: bool for the case that the input character is line comment
//cell 56: similar to cell 53
//cell 57: similar to cell 54
"1 >>>"

//cell 58: bool for the case that the function name is read
//cell 59: similar to cell 53
//cell 60: similar to cell 54
"1 >>>"

//cell 61: bool for the case that the first argument is read
//cell 62: similar to cell 53
//cell 63: similar to cell 54
"1 >>>"

//cell 64: bool for the case that the second argument is read
//cell 65: similar to cell 53
//cell 66: similar to cell 54
"1 >>>"

//cell 67: bool for the case that the function is running
//cell 68: similar to cell 53
//cell 69: similar to cell 54
"1 >>>"

//cell 70 to 94: temp 1; 7 bit
//input for function name
"1 >"
"1 >>>>>>>>>>>>>>>>>>>>>>>+>"

//cell 95: always 0 (for stopping the loop)
//cell 96: no use
"1 >>"

//cell 97: no use
//cell 98: initial value 0
//cell 99: initial value 1
"1 >>>+"

//cell 100: bool for function 1: run the code in the first argument
//cell 101: aux bool cell, the NOT gate of cell 100
//cell 102: aux cell for cell 100 (continues; not redo any 100 bool if block)
"1 >>+>"

//cell 103: bool for function 01:
//cell 104: similar to cell 101
//cell 105: similar to cell 102
"1 >>+>"

//cell 106: bool for function 11:
//cell 107: similar to cell 101
//cell 108: similar to cell 102
"1 >>+>"

//fill the value of input
{
    //go to cell 51 (minus 57)
    "1 <<<<<<<<<<"
    "1 <<<<<<<<<<"
    "1 <<<<<<<<<<"
    "1 <<<<<<<<<<"
    "1 <<<<<<<<<<"
    "1 <<<<<<<"
    //get input
    "1 ,"
}

//while(input)
{
    //At cell 51
    //if input is not zero
    "1 ["
    
    //copy it to cell 50 and binary number (cell 49)
    {
        "1 [-<+"
        //go to input (cell 49)
        "1 <"
        //add one
        "1 <<[<<<]>-<<[->+>+<<]+>[-<->]<[->>+<<<+>]>>[-<<+>>]<+>>[>->+>]"
        
        //go to cell 51
        "1 >>"
        "1 ]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For the case that the input character is not line comment and outside quote
    {
        //go to cell 52
        "1 >"
        //if cell 52 is true
        "1 [-"
        
        //check whether the input is /
        {
            {
                //go to input (cell 49)
                "1 <<<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<"
                
                "1 +"
                
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>"
                
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                
                //set to 47 for / (00101111)
                "1 +"
                "1 >>>"
                "1 >>>+"
                "1 >>>+"
                "1 >>>+"
                "1 >>>+"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                //run is_same
                "1 >+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "1 <<"
            //copy it to cell 23 and 24
            "1 [->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "1 +>[-<->]<"
            
            {
                //For the case that input is /
                //go to if bool cell (cell 24)
                "1 >>"
                "1 [-"
                
                //go to aux bool cell 56 (add 32)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>"
                
                //set aux bool cell 56 to true
                "1 +"
                //change to the case that the input character is line comment
                
                //go to cell 24 (minus 32)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                "1 ]"
            }
            
            {
                //For the case that input is not /
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 54 (add 32)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>"
                
                //set aux bool cell 54 to true
                "1 +"
                //For running the following case that the input character is not line comment
                //Further check whether the input character is quote
                
                //go to cell 22 (minus 32)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                "1 ]"
            }
        }
        
        //go to cell 52 (add 30)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 ]"
    }
    
    //For further checking whether the input character is quote, if cell 54 is true
    {
        //go to aux bool cell 54
        "1 >>"
        //if cell 54 is true
        "1 ["
        //set aux bool cell 54 to false
        "1 -"
        
        //go to aux bool cell 52
        "1 <<"
        //set aux bool cell 52 to true
        "1 +"
        
        //go to aux bool cell 54
        "1 >>"
        "1 ]"
    }
    
    //For further checking whether the input character is quote
    {
        //go to cell 52
        "1 <<"
        //if cell 52 is true
        "1 [-"
        
        //check whether the input is quote
        {
            {
                //go to input (cell 49)
                "1 <<<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<"
                
                "1 +"
                
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>"
                
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                
                //set to 34 for quote (00100010)
                "1 +"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                "1 >>>+"
                "1 >>>"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                //run is_same
                "1 >+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "1 <<"
            //copy it to cell 23 and 24
            "1 [->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "1 +>[-<->]<"
            
            {
                //For the case that input is quote
                //go to if bool cell (cell 24)
                "1 >>"
                "1 [-"
                
                //go to aux bool cell 59 (add 35)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>"
                
                //set aux bool cell 59 to true
                "1 +"
                //change to the case that the function name is read
                
                //go to cell 24 (minus 35)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<"
                "1 ]"
            }
            
            {
                //For the case that input is not quote
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 53 (add 31)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >"
                
                //set aux bool cell 53 to true
                "1 +"
                //change to the case that the input character is not line comment and outside quote
                
                //go to cell 22 (minus 31)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <"
                "1 ]"
            }
        }
        
        //go to cell 52 (add 30)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 ]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For the case that the input character is line comment
    {
        //go to cell 55
        "1 >>>"
        //if cell 55 is true
        "1 [-"
        
        //check whether the input is newline
        {
            {
                //go to input (cell 49)
                "1 <<<<<<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<"
                
                "1 +"
                
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>"
                
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 13 (minus 36)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<"
                
                //set to 10 for newline (00001010)
                "1 +"
                "1 >>>"
                "1 >>>+"
                "1 >>>"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                //run is_same
                "1 >+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "1 <<"
            //copy it to cell 23 and 24
            "1 [->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "1 +>[-<->]<"
            
            {
                //For the case that input is newline
                //go to if bool cell (cell 24)
                "1 >>"
                "1 [-"
                
                //go to aux bool cell 53 (add 29)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>"
                
                //set aux bool cell 53 to true
                "1 +"
                //change to the case that the input character is not line comment and outside quote
                
                //go to cell 24 (minus 29)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<"
                "1 ]"
            }
            
            {
                //For the case that input is not newline
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 56 (add 34)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>"
                
                //set aux bool cell 56 to true
                "1 +"
                //change to the case that the input character is line comment
                
                //go to cell 22 (minus 34)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<"
                "1 ]"
            }
        }
        
        //go to cell 55 (add 33)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>"
        "1 ]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For the case that the function name is read
    //check whether the input is 0
    {
        //go to cell 58
        "1 >>>"
        //if cell 58 is true
        "1 [-"
        
        //check whether the input is 0
        {
            {
                //go to input (cell 49)
                "1 <<<<<<<<<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<"
                
                "1 +"
                
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>"
                
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                
                //set to 34 for 0 (00110000)
                "1 +"
                "1 >>>+"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                //run is_same
                "1 >+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "1 <<"
            //copy it to cell 23 and 24
            "1 [->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "1 +>[-<->]<"
            
            {
                //For the case that input is 0
                //go to if bool cell (cell 24)
                "1 >>"
                "1 [-"
                
                //set the temp variable (add bit 0)
                {
                    //go to aux bool cell 91 (add 67)
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>"
                    
                    //go to leftmost boundary of temp variable
                    "1 [<<<]"
                    
                    //add boundary
                    "1 +"
                    //set zero for leftmost bit
                    "1 <+"
                    
                    //go to boundary
                    "1 >"
                    //go to rightmost boundary (cell 94)
                    "1 [>>>]"
                }
                
                //change to the case that the function name is read
                {
                    //go to aux bool cell 59 (minus 35)
                    "1 <<<<<<<<<<"
                    "1 <<<<<<<<<<"
                    "1 <<<<<<<<<<"
                    "1 <<<<<"
                    
                    //set aux bool cell 59 to true
                    "1 +"
                }
                
                //go to cell 24 (minus 35)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<"
                "1 ]"
            }
            
            {
                //For the case that input is not 0
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 60 (add 38)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>"
                //set aux bool cell 60 to true
                "1 +"
                //change to the case that the function name is read
                //further checking
                
                //go to cell 22 (minus 38)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<"
                "1 ]"
            }
        }
        
        //go to cell 58 (add 36)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>"
        "1 ]"
    }
    
    //For further checking whether the input character is 1, if cell 60 is true
    {
        //go to aux bool cell 60
        "1 >>"
        //if cell 60 is true
        "1 ["
        //set aux bool cell 60 to false
        "1 -"
        
        //go to aux bool cell 58
        "1 <<"
        //set aux bool cell 58 to true
        "1 +"
        
        //go to aux bool cell 60
        "1 >>"
        "1 ]"
    }
    
    //For the case that the function name is read
    //Further check whether the input is 1
    {
        //go to cell 58
        "1 <<"
        //if cell 58 is true
        "1 [-"
        
        //check whether the input is 0
        {
            {
                //go to input (cell 49)
                "1 <<<<<<<<<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<"
                
                "1 +"
                
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>"
                
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                
                //set to 34 for 1 (00110001)
                "1 +"
                "1 >>>+"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                "1 >>>+"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                //run is_same
                "1 >+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "1 <<"
            //copy it to cell 23 and 24
            "1 [->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "1 +>[-<->]<"
            
            {
                //For the case that input is 1
                //go to if bool cell (cell 24)
                "1 >>"
                "1 [-"
                
                //set the temp variable (add bit 1)
                {
                    //go to aux bool cell 91 (add 67)
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>"
                    
                    //go to leftmost boundary of temp variable
                    "1 [<<<]"
                    
                    //add boundary
                    "1 +"
                    
                    //add one for leftmost bit
                    "1 >+>-<<"
                    
                    //set zero for sub-leftmost bit
                    "1 <+"
                    
                    //go to boundary
                    "1 >"
                    //go to rightmost boundary (cell 94)
                    "1 [>>>]"
                }
                
                //change to the case that the function name is read
                {
                    //go to aux bool cell 59 (minus 35)
                    "1 <<<<<<<<<<"
                    "1 <<<<<<<<<<"
                    "1 <<<<<<<<<<"
                    "1 <<<<<"
                    
                    //set aux bool cell 59 to true
                    "1 +"
                }
                
                //go to cell 24 (minus 35)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<"
                "1 ]"
            }
            
            {
                //For the case that input is not 1
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 60 (add 38)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>"
                //set aux bool cell 60 to true
                "1 +"
                //change to the case that the function name is read
                //further checking
                
                //go to cell 22 (minus 38)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<"
                "1 ]"
            }
        }
        
        //go to cell 58 (add 36)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>"
        "1 ]"
    }
    
    //For identifying the file name, if cell 60 is true
    {
        //go to aux bool cell 60
        "1 >>"
        //if cell 60 is true
        "1 ["
        //set aux bool cell 60 to false
        "1 -"
        
        //go to aux bool cell 58
        "1 <<"
        //set aux bool cell 58 to true
        "1 +"
        
        //go to aux bool cell 60
        "1 >>"
        "1 ]"
    }
    
    //For the case that the function name is read
    //identify the file name
    {
        //go to cell 58
        "1 <<"
        //if cell 58 is true
        "1 [-"
        
        //set the bool for function index
        {
            //go to bool cell of temp variable (cell 91) (add 33)
            "1 >>>>>>>>>>"
            "1 >>>>>>>>>>"
            "1 >>>>>>>>>>"
            "1 >>>"
            
            //for loop
            "1 ["
            
            //go to temp variable (cell 94)
            "1 >>>"
            //subtract one
            "1 <[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]"
            
            //add one for function index
            //go to cell 98
            "1 >>>>"
            
            //go to the function index
            "1 [>>>]"
            
            //set zero
            "1 +>-"
            
            //set one
            "1 >>->+<<<<"
            
            //go to cell 95
            "1 [<<<]"
            
            //go to bool cell of temp variable (cell 91)
            "1 <<<<"
            "1 ]"
        }
        
        //check whether the input is quote
        {
            {
                //go to input (cell 49) (minus 42)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<"
                
                "1 +"
                
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>"
                
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                
                //set to 34 for quote (00100010)
                "1 +"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                "1 >>>+"
                "1 >>>"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                //run is_same
                "1 >+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "1 <<"
            //copy it to cell 23 and 24
            "1 [->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "1 +>[-<->]<"
            
            {
                //For the case that input is quote
                //go to if bool cell (cell 24)
                "1 >>"
                "1 [-"
                
                {
                    //go to aux bool cell 67 (add 43)
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>"
                    
                    //set aux bool cell 67 to true
                    "1 +"
                    //change to the case that the function is running
                    //run it immediately
                }
                
                {
                    //change the function index to run it immediately
                    //For the case that the function has no argument
                    //go to cell 98 (add 31)
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >"
                    
                    //go to the current function index
                    "1 [>>>]"
                    
                    //set it run immediately
                    "1 >-<<+>"
                    
                    //go to cell 95
                    "1 <<<"
                    "1 [<<<]"
                }
                
                //go to cell 24 (minus 71)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <"
                "1 ]"
            }
            
            {
                //For the case that input is not quote
                //Assume the input is whitespace
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 62 (add 40)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                //set aux bool cell 62 to true
                "1 +"
                //change to the case that the first argument is read
                
                //go to cell 22 (minus 40)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 ]"
            }
        }
        
        //go to cell 58 (add 36)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>"
        "1 ]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For the case that the first argument is read
    {
        //go to cell 61
        "1 >>>"
        //if cell 61 is true
        "1 [-"
        
        //check whether the input is quote
        {
            {
                //go to input (cell 49) (minus 12)
                "1 <<<<<<<<<<"
                "1 <<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<"
                
                "1 +"
                
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>"
                
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                
                //set to 34 for quote (00100010)
                "1 +"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                "1 >>>+"
                "1 >>>"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                //run is_same
                "1 >+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "1 <<"
            //copy it to cell 23 and 24
            "1 [->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "1 +>[-<->]<"
            
            {
                //For the case that input is quote
                //go to if bool cell (cell 24)
                "1 >>"
                "1 [-"
                
                //go to aux bool cell 67 (add 43)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>"
                
                //set aux bool cell 67 to true
                "1 +"
                //change to the case that the function is running
                //run it immediately
                
                //go to cell 24 (minus 43)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<"
                "1 ]"
            }
            
            {
                //For the case that input is not quote
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 63 (add 41)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >"
                //set aux bool cell 63 to true
                "1 +"
                //change to the case that the first argument is read
                //further checking whether the input character is whitespace
                
                //go to cell 22 (minus 41)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <"
                "1 ]"
            }
        }
        
        //go to cell 61 (add 39)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>"
        "1 ]"
    }
    
    //For further checking whether the input character is whitespace, if cell 63 is true
    {
        //go to aux bool cell 63
        "1 >>"
        //if cell 63 is true
        "1 ["
        //set aux bool cell 63 to false
        "1 -"
        
        //go to aux bool cell 61
        "1 <<"
        //set aux bool cell 61 to true
        "1 +"
        
        //go to aux bool cell 63
        "1 >>"
        "1 ]"
    }
    
    //For the case that the first argument is read
    //further check whether the input character is whitespace
    {
        //go to cell 61
        "1 <<"
        //if cell 61 is true
        "1 [-"
        
        //check whether the input is whitespace
        {
            {
                //go to input (cell 49) (minus 12)
                "1 <<<<<<<<<<"
                "1 <<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<"
                
                "1 +"
                
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>"
                
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                
                //set to 32 for whitespace (00100000)
                "1 +"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                //run is_same
                "1 >+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "1 <<"
            //copy it to cell 23 and 24
            "1 [->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "1 +>[-<->]<"
            
            {
                //For the case that input is whitespace
                //go to if bool cell (cell 24)
                "1 >>"
                "1 [-"
                
                //continue; not run the following function block
                {
                    //go to cell 98 (add 74)
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>"
                    
                    //go to the function index
                    "1 [>>>]"
                    
                    //set the aux bool cell
                    "1 <->>+<"
                    "1 <<<"
                    
                    //go to cell 95
                    "1 [<<<]"
                }
                
                {
                    //go to aux bool cell 65 (minus 30)
                    "1 <<<<<<<<<<"
                    "1 <<<<<<<<<<"
                    "1 <<<<<<<<<<"
                    
                    //set aux bool cell 65 to true
                    "1 +"
                    //change to the case that the second argument is read
                }
                
                //go to cell 24 (minus 41)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <"
                "1 ]"
            }
            
            {
                //For the case that input is not whitespace
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 63 (add 41)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >"
                //set aux bool cell 63 to true
                "1 +"
                //change to the case that the first argument is read
                //further get the first argument immediately
                
                //go to cell 22 (minus 41)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <"
                "1 ]"
            }
        }
        
        //go to cell 61 (add 39)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>"
        "1 ]"
    }
    
    //For further get the first argument, if cell 63 is true
    {
        //go to aux bool cell 63
        "1 >>"
        //if cell 63 is true
        "1 ["
        //set aux bool cell 63 to false
        "1 -"
        
        //go to aux bool cell 61
        "1 <<"
        //set aux bool cell 61 to true
        "1 +"
        
        //go to aux bool cell 63
        "1 >>"
        "1 ]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For the case that the second argument is read
    {
        //go to cell 64
        "1 >"
        //if cell 64 is true
        "1 [-"
        
        //check whether the input is quote
        {
            {
                //go to input (cell 49) (minus 15)
                "1 <<<<<<<<<<"
                "1 <<<<<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<"
                
                "1 +"
                
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>"
                
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                
                //set to 34 for quote (00100010)
                "1 +"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                "1 >>>+"
                "1 >>>"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                //run is_same
                "1 >+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "1 <<"
            //copy it to cell 23 and 24
            "1 [->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "1 +>[-<->]<"
            
            {
                //For the case that input is quote
                //go to if bool cell (cell 24)
                "1 >>"
                "1 [-"
                
                //go to aux bool cell 67 (add 43)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>"
                
                //set aux bool cell 67 to true
                "1 +"
                //change to the case that the function is running
                //run it immediately
                
                //go to cell 24 (minus 43)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<"
                "1 ]"
            }
            
            {
                //For the case that input is not quote
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 66 (add 44)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>"
                //set aux bool cell 66 to true
                "1 +"
                //change to the case that the second argument is read
                //further checking whether the input character is whitespace
                
                //go to cell 22 (minus 44)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<"
                "1 ]"
            }
        }
        
        //go to cell 64 (add 42)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>"
        "1 ]"
    }
    
    //For further checking whether the input character is whitespace, if cell 66 is true
    {
        //go to aux bool cell 66
        "1 >>"
        //if cell 66 is true
        "1 ["
        //set aux bool cell 66 to false
        "1 -"
        
        //go to aux bool cell 64
        "1 <<"
        //set aux bool cell 64 to true
        "1 +"
        
        //go to aux bool cell 66
        "1 >>"
        "1 ]"
    }
    
    //For the case that the second argument is read
    //further check whether the input character is whitespace
    {
        //go to cell 64
        "1 <<"
        //if cell 64 is true
        "1 [-"
        
        //check whether the input is whitespace
        {
            {
                //go to input (cell 49) (minus 15)
                "1 <<<<<<<<<<"
                "1 <<<<<"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<"
                
                "1 +"
                
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>"
                
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                
                //set to 32 for whitespace (00100000)
                "1 +"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                "1 >>>"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<"
                //run is_same
                "1 >+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 24
            }
        }
        
        {
            //go to the compare result (cell 22)
            "1 <<"
            //copy it to cell 23 and 24
            "1 [->+>+<<]"
            
            //go to cell 22
            //cell 22 is NOT gate of cell 23
            "1 +>[-<->]<"
            
            {
                //For the case that input is whitespace
                //go to if bool cell (cell 24)
                "1 >>"
                "1 [-"
                
                //continue; not run the following function block
                {
                    //go to cell 98 (add 74)
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>>>>>>>"
                    "1 >>>>"
                    
                    //go to the function index
                    "1 [>>>]"
                    
                    //set the aux bool cell
                    "1 <->>+<"
                    "1 <<<"
                    
                    //go to cell 95
                    "1 [<<<]"
                }
                
                {
                    //go to aux bool cell 68 (minus 27)
                    "1 <<<<<<<<<<"
                    "1 <<<<<<<<<<"
                    "1 <<<<<<<"
                    
                    //set aux bool cell 68 to true
                    "1 +"
                    //change to the case that the third argument is read
                }
                
                //go to cell 24 (minus 44)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<"
                "1 ]"
            }
            
            {
                //For the case that input is not whitespace
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 66 (add 44)
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>>>>>>>"
                "1 >>>>"
                //set aux bool cell 66 to true
                "1 +"
                //change to the case that the second argument is read
                //further get the second argument immediately
                
                //go to cell 22 (minus 44)
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<<<<<<<"
                "1 <<<<"
                "1 ]"
            }
        }
        
        //go to cell 64 (add 42)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>"
        "1 ]"
    }
    
    //For further get the second argument, if cell 66 is true
    {
        //go to aux bool cell 66
        "1 >>"
        //if cell 66 is true
        "1 ["
        //set aux bool cell 66 to false
        "1 -"
        
        //go to aux bool cell 64
        "1 <<"
        //set aux bool cell 64 to true
        "1 +"
        
        //go to aux bool cell 66
        "1 >>"
        "1 ]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For function 1: run the code in the first argument
    {
        //go to function index (cell 100) (add 34)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>"
        
        //if cell 100 is true
        "1 [-"
        
        //For the case that the first argument is read
        {
            //go to cell 61 (minus 39)
            "1 <<<<<<<<<<"
            "1 <<<<<<<<<<"
            "1 <<<<<<<<<<"
            "1 <<<<<<<<<"
            
            //if cell 61 is true
            "1 [-"
            
            //go to constant value cell for input (cell 50) (minus 11)
            "1 <<<<<<<<<<"
            "1 <"
            //output
            "1 ."
            
            //go to aux bool cell 102 (add 52)
            "1 >>>>>>>>>>"
            "1 >>>>>>>>>>"
            "1 >>>>>>>>>>"
            "1 >>>>>>>>>>"
            "1 >>>>>>>>>>"
            "1 >>"
            
            //set to true
            "1 +"
            
            //go to aux bool cell 62 (minus 40)
            "1 <<<<<<<<<<"
            "1 <<<<<<<<<<"
            "1 <<<<<<<<<<"
            "1 <<<<<<<<<<"
            //set it to true
            "1 +"
            
            //go to cell 61
            "1 <"
            "1 ]"
        }
        
        //For running; do nothing
        
        //go to cell 100 (add 39)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>"
        "1 ]"
    }
    
    //For further finalize the running, if cell 69 is true
    {
        //go to aux bool cell 69 (minus 31)
        "1 <<<<<<<<<<"
        "1 <<<<<<<<<<"
        "1 <<<<<<<<<<"
        "1 <"
        //if cell 69 is true
        "1 ["
        //set aux bool cell 69 to false
        "1 -"
        
        //go to aux bool cell 67
        "1 <<"
        //set aux bool cell 67 to true
        "1 +"
        
        //go to aux bool cell 69
        "1 >>"
        "1 ]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For the case that the function is running
    //finalize the running
    {
        //go to cell 67
        "1 <<"
        
        //if cell 67 is true
        "1 [-"
        
        //reset function index
        //go to cell 98 (add 31)
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >>>>>>>>>>"
        "1 >"
        
        //go to the current function index
        "1 [>>>]"
        
        //reset the aux bool cell
        "1 +"
        
        //go to cell 95
        "1 [<<<]"
        
        //reset the aux bool cell
        "1 >>>->+"
        //At cell 99
        
        //go to aux bool cell 53 (minus 46)
        "1 <<<<<<<<<<"
        "1 <<<<<<<<<<"
        "1 <<<<<<<<<<"
        "1 <<<<<<<<<<"
        "1 <<<<<<"
        
        //set aux bool cell 53 to true
        "1 +"
        //change to the case that the input character is not line comment and outside quote
        
        //go to cell 67 (add 14)
        "1 >>>>>>>>>>"
        "1 >>>>"
        "1 ]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //reset all bool cells
    {
        {
            //go to aux cell 53 (minus 14)
            "1 <<<<<<<<<<"
            "1 <<<<"
            //if cell 53 is true; set cell 53 to false; set cell 52 to true
            "1 [-<+>]"
            
            //go to aux cell 56
            "1 >>>"
            //if cell 56 is true; set cell 56 to false; set cell 55 to true
            "1 [-<+>]"
            
            //go to aux cell 59
            "1 >>>"
            //if cell 59 is true; set cell 59 to false; set cell 58 to true
            "1 [-<+>]"
            
            //go to aux cell 62
            "1 >>>"
            //if cell 62 is true; set cell 62 to false; set cell 61 to true
            "1 [-<+>]"
            
            //go to aux cell 65
            "1 >>>"
            //if cell 65 is true; set cell 65 to false; set cell 64 to true
            "1 [-<+>]"
            
            //go to aux cell 68
            "1 >>>"
            //if cell 68 is true; set cell 68 to false; set cell 67 to true
            "1 [-<+>]"
        }
        
        {
            //For function
            //go to aux cell 102 (add 34)
            "1 >>>>>>>>>>"
            "1 >>>>>>>>>>"
            "1 >>>>>>>>>>"
            "1 >>>>"
            //if cell 102 is true; set cell 102 to false; set cell 100 to true
            "1 [-<<+>>]"
            
            //go to aux cell 105
            "1 >>>"
            //if cell 105 is true; set cell 105 to false; set cell 103 to true
            "1 [-<<+>>]"
            
            //go to aux cell 108
            "1 >>>"
            //if cell 108 is true; set cell 108 to false; set cell 106 to true
            "1 [-<<+>>]"
        }
    }
    
    //update the value of input
    {
        //go to input (cell 49) (minus 59)
        "1 <<<<<<<<<<"
        "1 <<<<<<<<<<"
        "1 <<<<<<<<<<"
        "1 <<<<<<<<<<"
        "1 <<<<<<<<<<"
        "1 <<<<<<<<<"
        //clear
        "1 <<<[<<<]>>[-]>[->[-]>[-]>]<+>"
        
        //go to cell 50
        "1 >"
        //clear
        "1 [-]"
        
        //go to cell 51
        "1 >"
        //get input
        "1 ,"
    }
    
    //end while loop
    "1 ]"
}
