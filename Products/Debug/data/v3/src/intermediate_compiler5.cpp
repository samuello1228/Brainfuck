//remove line comment (remove any character between / and newline)
//output all characters between quotes (if it is not line comment)

//changes: add the code for the function 1 (cannot run)

//include NOT_gate
//include binary_initialize
//include binary_add_one
//include binary_subtract_one
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
">+>>"

//cell 55: bool for the case that the input character is line comment
//cell 56: similar to cell 53
//cell 57: similar to cell 54
">>>"

//cell 58: bool for the case that the function name is read
//cell 59: similar to cell 53
//cell 60: similar to cell 54
">>>"

//cell 61: bool for the case that the first argument is read
//cell 62: similar to cell 53
//cell 63: similar to cell 54
">>>"

//cell 64: bool for the case that the second argument is read
//cell 65: similar to cell 53
//cell 66: similar to cell 54
">>>"

//cell 67: bool for the case that the function is running
//cell 68: similar to cell 53
//cell 69: similar to cell 54
">>>"

//cell 70 to 94: temp 1; 7 bit
//input for function name
">"
">>>>>>>>>>>>>>>>>>>>>>>+>"

//cell 95: always 0 (for stopping the loop)
//cell 96: no use
">>"

//cell 97: no use
//cell 98: initial value 0
//cell 99: initial value 1
">>>+"

//cell 100: bool for function 1: run the code in the first argument
//cell 101: aux bool cell, the NOT gate of cell 100
//cell 102: aux cell for cell 100 (continues; not redo any 100 bool if block)
">>+>"

//cell 103: bool for function 01:
//cell 104: similar to cell 101
//cell 105: similar to cell 102
">>+>"

//cell 106: bool for function 11:
//cell 107: similar to cell 101
//cell 108: similar to cell 102
">>+>"

//fill the value of input
{
    //go to cell 51 (minus 57)
    "<<<<<<<<<<"
    "<<<<<<<<<<"
    "<<<<<<<<<<"
    "<<<<<<<<<<"
    "<<<<<<<<<<"
    "<<<<<<<"
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
    
    ////////////////////////////////////////////////////////////////////////////////////////
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
                
                //go to aux bool cell 56 (add 32)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>"
                
                //set aux bool cell 56 to true
                "+"
                //change to the case that the input character is line comment
                
                //go to cell 24 (minus 32)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
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
                
                //go to aux bool cell 59 (add 35)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>"
                
                //set aux bool cell 59 to true
                "+"
                //change to the case that the function name is read
                
                //go to cell 24 (minus 35)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<"
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
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For the case that the input character is line comment
    {
        //go to cell 55
        ">>>"
        //if cell 55 is true
        "[-"
        
        //check whether the input is newline
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
                
                //go to aux bool cell 56 (add 34)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>"
                
                //set aux bool cell 56 to true
                "+"
                //change to the case that the input character is line comment
                
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
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For the case that the function name is read
    //check whether the input is 0
    {
        //go to cell 58
        ">>>"
        //if cell 58 is true
        "[-"
        
        //check whether the input is 0
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
                //go to cell 7 (minus 42)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                
                //set to 34 for 0 (00110000)
                "+"
                ">>>+"
                ">>>"
                ">>>"
                ">>>"
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
                //For the case that input is 0
                //go to if bool cell (cell 24)
                ">>"
                "[-"
                
                //set the temp variable (add bit 0)
                {
                    //go to aux bool cell 91 (add 67)
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>"
                    
                    //go to leftmost boundary of temp variable
                    "[<<<]"
                    
                    //add boundary
                    "+"
                    //set zero for leftmost bit
                    "<+"
                    
                    //go to boundary
                    ">"
                    //go to rightmost boundary (cell 94)
                    "[>>>]"
                }
                
                //change to the case that the function name is read
                {
                    //go to aux bool cell 59 (minus 35)
                    "<<<<<<<<<<"
                    "<<<<<<<<<<"
                    "<<<<<<<<<<"
                    "<<<<<"
                    
                    //set aux bool cell 59 to true
                    "+"
                }
                
                //go to cell 24 (minus 35)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<"
                "]"
            }
            
            {
                //For the case that input is not 0
                //go to else bool cell 22
                "<<"
                "[-"
                
                //go to aux bool cell 60 (add 38)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>"
                //set aux bool cell 60 to true
                "+"
                //change to the case that the function name is read
                //further checking
                
                //go to cell 22 (minus 38)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<"
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
    
    //For further checking whether the input character is 1, if cell 60 is true
    {
        //go to aux bool cell 60
        ">>"
        //if cell 60 is true
        "["
        //set aux bool cell 60 to false
        "-"
        
        //go to aux bool cell 58
        "<<"
        //set aux bool cell 58 to true
        "+"
        
        //go to aux bool cell 60
        ">>"
        "]"
    }
    
    //For the case that the function name is read
    //Further check whether the input is 1
    {
        //go to cell 58
        "<<"
        //if cell 58 is true
        "[-"
        
        //check whether the input is 0
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
                //go to cell 7 (minus 42)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                
                //set to 34 for 1 (00110001)
                "+"
                ">>>+"
                ">>>"
                ">>>"
                ">>>"
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
                //For the case that input is 1
                //go to if bool cell (cell 24)
                ">>"
                "[-"
                
                //set the temp variable (add bit 1)
                {
                    //go to aux bool cell 91 (add 67)
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>"
                    
                    //go to leftmost boundary of temp variable
                    "[<<<]"
                    
                    //add boundary
                    "+"
                    
                    //add one for leftmost bit
                    ">+>-<<"
                    
                    //set zero for sub-leftmost bit
                    "<+"
                    
                    //go to boundary
                    ">"
                    //go to rightmost boundary (cell 94)
                    "[>>>]"
                }
                
                //change to the case that the function name is read
                {
                    //go to aux bool cell 59 (minus 35)
                    "<<<<<<<<<<"
                    "<<<<<<<<<<"
                    "<<<<<<<<<<"
                    "<<<<<"
                    
                    //set aux bool cell 59 to true
                    "+"
                }
                
                //go to cell 24 (minus 35)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<"
                "]"
            }
            
            {
                //For the case that input is not 1
                //go to else bool cell 22
                "<<"
                "[-"
                
                //go to aux bool cell 60 (add 38)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>"
                //set aux bool cell 60 to true
                "+"
                //change to the case that the function name is read
                //further checking
                
                //go to cell 22 (minus 38)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<"
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
    
    //For identifying the file name, if cell 60 is true
    {
        //go to aux bool cell 60
        ">>"
        //if cell 60 is true
        "["
        //set aux bool cell 60 to false
        "-"
        
        //go to aux bool cell 58
        "<<"
        //set aux bool cell 58 to true
        "+"
        
        //go to aux bool cell 60
        ">>"
        "]"
    }
    
    //For the case that the function name is read
    //identify the file name
    {
        //go to cell 58
        "<<"
        //if cell 58 is true
        "[-"
        
        //set the bool for function index
        {
            //go to bool cell of temp variable (cell 91) (add 33)
            ">>>>>>>>>>"
            ">>>>>>>>>>"
            ">>>>>>>>>>"
            ">>>"
            
            //for loop
            "["
            
            //go to temp variable (cell 94)
            ">>>"
            //subtract one
            "<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]"
            
            //add one for function index
            //go to cell 98
            ">>>>"
            
            //go to the function index
            "[>>>]"
            
            //set zero
            "+>-"
            
            //set one
            ">>->+<<<<"
            
            //go to cell 95
            "[<<<]"
            
            //go to bool cell of temp variable (cell 91)
            "<<<<"
            "]"
        }
        
        //check whether the input is quote
        {
            {
                //go to input (cell 49) (minus 42)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                
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
                
                {
                    //go to aux bool cell 67 (add 43)
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>"
                    
                    //set aux bool cell 67 to true
                    "+"
                    //change to the case that the function is running
                    //run it immediately
                }
                
                {
                    //change the function index to run it immediately
                    //For the case that the function has no argument
                    //go to cell 98 (add 31)
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">"
                    
                    //go to the current function index
                    "[>>>]"
                    
                    //set it run immediately
                    ">-<<+>"
                    
                    //go to cell 95
                    "<<<"
                    "[<<<]"
                }
                
                //go to cell 24 (minus 71)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<"
                "]"
            }
            
            {
                //For the case that input is not quote
                //Assume the input is whitespace
                //go to else bool cell 22
                "<<"
                "[-"
                
                //go to aux bool cell 62 (add 40)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                //set aux bool cell 62 to true
                "+"
                //change to the case that the first argument is read
                
                //go to cell 22 (minus 40)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
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
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For the case that the first argument is read
    {
        //go to cell 61
        ">>>"
        //if cell 61 is true
        "[-"
        
        //check whether the input is quote
        {
            {
                //go to input (cell 49) (minus 12)
                "<<<<<<<<<<"
                "<<"
                
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
                
                //go to aux bool cell 67 (add 43)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>"
                
                //set aux bool cell 67 to true
                "+"
                //change to the case that the function is running
                //run it immediately
                
                //go to cell 24 (minus 43)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<"
                "]"
            }
            
            {
                //For the case that input is not quote
                //go to else bool cell 22
                "<<"
                "[-"
                
                //go to aux bool cell 63 (add 41)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">"
                //set aux bool cell 63 to true
                "+"
                //change to the case that the first argument is read
                //further checking whether the input character is whitespace
                
                //go to cell 22 (minus 41)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<"
                "]"
            }
        }
        
        //go to cell 61 (add 39)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>"
        "]"
    }
    
    //For further checking whether the input character is whitespace, if cell 63 is true
    {
        //go to aux bool cell 63
        ">>"
        //if cell 63 is true
        "["
        //set aux bool cell 63 to false
        "-"
        
        //go to aux bool cell 61
        "<<"
        //set aux bool cell 61 to true
        "+"
        
        //go to aux bool cell 63
        ">>"
        "]"
    }
    
    //For the case that the first argument is read
    //further check whether the input character is whitespace
    {
        //go to cell 61
        "<<"
        //if cell 61 is true
        "[-"
        
        //check whether the input is whitespace
        {
            {
                //go to input (cell 49) (minus 12)
                "<<<<<<<<<<"
                "<<"
                
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
                
                //set to 32 for whitespace (00100000)
                "+"
                ">>>"
                ">>>"
                ">>>"
                ">>>"
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
                //For the case that input is whitespace
                //go to if bool cell (cell 24)
                ">>"
                "[-"
                
                //continue; not run the following function block
                {
                    //go to cell 98 (add 74)
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>"
                    
                    //go to the function index
                    "[>>>]"
                    
                    //set the aux bool cell
                    "<->>+<"
                    "<<<"
                    
                    //go to cell 95
                    "[<<<]"
                }
                
                {
                    //go to aux bool cell 65 (minus 30)
                    "<<<<<<<<<<"
                    "<<<<<<<<<<"
                    "<<<<<<<<<<"
                    
                    //set aux bool cell 65 to true
                    "+"
                    //change to the case that the second argument is read
                }
                
                //go to cell 24 (minus 41)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<"
                "]"
            }
            
            {
                //For the case that input is not whitespace
                //go to else bool cell 22
                "<<"
                "[-"
                
                //go to aux bool cell 63 (add 41)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">"
                //set aux bool cell 63 to true
                "+"
                //change to the case that the first argument is read
                //further get the first argument immediately
                
                //go to cell 22 (minus 41)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<"
                "]"
            }
        }
        
        //go to cell 61 (add 39)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>"
        "]"
    }
    
    //For further get the first argument, if cell 63 is true
    {
        //go to aux bool cell 63
        ">>"
        //if cell 63 is true
        "["
        //set aux bool cell 63 to false
        "-"
        
        //go to aux bool cell 61
        "<<"
        //set aux bool cell 61 to true
        "+"
        
        //go to aux bool cell 63
        ">>"
        "]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For function 1: run the code in the first argument
    {
        //go to function index (cell 100) (add 37)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>"
        
        //if cell 100 is true
        "[-"
        
        //For the case that the first argument is read
        {
            //go to cell 61 (minus 39)
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<"
            
            //if cell 61 is true
            "[-"
            
            //go to constant value cell for input (cell 50) (minus 11)
            "<<<<<<<<<<"
            "<"
            //output
            "."
            
            //go to aux bool cell 102 (add 52)
            ">>>>>>>>>>"
            ">>>>>>>>>>"
            ">>>>>>>>>>"
            ">>>>>>>>>>"
            ">>>>>>>>>>"
            ">>"
            
            //set to true
            "+"
            
            //go to aux bool cell 62 (minus 40)
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            //set it to true
            "+"
            
            //go to cell 61
            "<"
            "]"
        }
        
        //For running; do nothing
        
        //go to cell 100 (add 39)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>"
        "]"
    }
    
    //For further finalize the running, if cell 69 is true
    {
        //go to aux bool cell 69 (minus 31)
        "<<<<<<<<<<"
        "<<<<<<<<<<"
        "<<<<<<<<<<"
        "<"
        //if cell 69 is true
        "["
        //set aux bool cell 69 to false
        "-"
        
        //go to aux bool cell 67
        "<<"
        //set aux bool cell 67 to true
        "+"
        
        //go to aux bool cell 69
        ">>"
        "]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //reset all bool cells
    {
        //go to aux cell 53 (minus 16)
        "<<<<<<<<<<"
        "<<<<<<"
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
        
        //go to aux cell 62
        ">>>"
        //if cell 62 is true; set cell 62 to false; set cell 61 to true
        "[-<+>]"
        
        //go to aux cell 65
        ">>>"
        //if cell 65 is true; set cell 65 to false; set cell 64 to true
        "[-<+>]"
        
        //go to aux cell 68
        ">>>"
        //if cell 68 is true; set cell 68 to false; set cell 67 to true
        "[-<+>]"
        
        //For function
        //go to aux cell 102 (add 34)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>"
        //if cell 102 is true; set cell 102 to false; set cell 100 to true
        "[-<<+>>]"
        
        //go to aux cell 105
        ">>>"
        //if cell 105 is true; set cell 105 to false; set cell 103 to true
        "[-<<+>>]"
        
        //go to aux cell 108
        ">>>"
        //if cell 108 is true; set cell 108 to false; set cell 106 to true
        "[-<<+>>]"
    }
    
    //update the value of input
    {
        //go to input (cell 49) (minus 59)
        "<<<<<<<<<<"
        "<<<<<<<<<<"
        "<<<<<<<<<<"
        "<<<<<<<<<<"
        "<<<<<<<<<<"
        "<<<<<<<<<"
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
