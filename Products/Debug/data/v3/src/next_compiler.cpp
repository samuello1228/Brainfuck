//remove line comment (remove any character between / and newline)
//output all characters between quotes (if it is not line comment)

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

//cell 97: bool for function 1: run the code in the first argument
//cell 98: aux bool cell, the NOT gate of cell 100
//cell 99: aux cell for cell 100 (continues; not redo any 100 bool if block)
">+>>"

//cell 100: bool for function 2:
//cell 101: similar to cell 101
//cell 102: similar to cell 102
">>+>"

//cell 103: bool for function 3:
//cell 104: similar to cell 101
//cell 105: similar to cell 102
">>+>"

//cell 106: bool for function 4:
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
                    
                    //go to left boundary of temp variable
                    "[<<<]"
                    
                    //add boundary
                    "+"
                    //set zero for left boundary
                    "<+"
                    
                    //go to boundary
                    ">"
                    //go to right boundary (cell 94)
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
                    
                    //go to left boundary of temp variable
                    "[<<<]"
                    
                    //add boundary
                    "+"
                    
                    //add one
                    ">+>-<<"
                    
                    //set zero for left boundary
                    "<+"
                    
                    //go to boundary
                    ">"
                    //go to right boundary (cell 94)
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
            //go to temp variable (cell 94) (add 36)
            ">>>>>>>>>>"
            ">>>>>>>>>>"
            ">>>>>>>>>>"
            ">>>>>>"
            //subtract one
            "<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]"
            
            //go to bool cell of temp variable (cell 91)
            "<<<"
            
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
            "+<->"
            
            //set one
            ">>+>-<<<"
            
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
                
                //go to aux bool cell 68 (add 44)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>"
                
                //set aux bool cell 68 to true
                "+"
                //change to the case that the function is running
                
                //go to cell 24 (minus 44)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<"
                "]"
            }
            
            {
                //For the case that input is not quote
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
    
    //reset all bool cells
    {
        //go to aux cell 53
        "<<<<<"
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
    }
    
    //update the value of input
    {
        //go to input (cell 49) (minus 19)
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
