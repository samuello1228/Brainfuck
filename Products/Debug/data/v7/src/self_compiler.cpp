//remove line comment (remove any character between / and newline)
//output all characters between quotes (if it is not line comment)

//changes: no changes

//include NOT_gate
//include binary_initialize
//include binary_add_one
//include binary_subtract_one
//include binary_clear
//include binary_copy_half
//include binary_copy_full
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

//cell 70: temp cell 1
"1 >"

//cell 71: temp cell 2
"1 >"

//cell 72: temp cell 3
//the first argument for function 01
//output cell for function 11 and 001
"1 >"

//cell 73 to 103: temp binary 1; 9 bit
//second argument for function 01
//copy for the first argument in function 11 and 001
//second argument for function 001
"1 >"
"1 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>+>"

//cell 104 to 134: temp binary 2; 9 bit
"1 >"
"1 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>+>"

//cell 135 to 165: temp binary 3; 9 bit
//input for function name
"1 >"
"1 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>+>"

//cell 166: always 0 (for stopping the loop)
//cell 167: no use
"1 >>"

//cell 168: initial value 1
//cell 169: initial value 0
//cell 170: no use
"1 >+>>"

//cell 171: bool for function 1: run the code in the first argument
//cell 172: aux bool cell, the NOT gate of cell 171
//cell 173: aux cell for cell 171 (continues; not redo any 171 bool if block)
"1 >>+>"

//cell 174: bool for function 01: run a single code, for n times, e.g. "01 + 111"
//cell 175: similar to cell 172
//cell 176: similar to cell 173
"1 >>+>"

//cell 177: bool for function 11: output the code in the first argument
//using the current empty cell to output at runtime
//cell 178: similar to cell 172
//cell 179: similar to cell 173
"1 >>+>"

//cell 180: bool for function 001: output a single code, for n times
//using the current empty cell to output at runtime
//cell 181: similar to cell 172
//cell 182: similar to cell 173
"1 >>+>"

//fill the value of input
{
    //go to cell 51 (minus 131) (10000011)
    "01 < 11000001"
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
                "01 < 11"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                "01 < 01011"
                "1 +"
                "01 > 01011"
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42) (101010)
                "01 < 010101"
                
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
                //go to is_same (cell 0) (minus 22) (10110)
                "01 < 01101"
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
                
                //go to aux bool cell 56 (add 32) (100000)
                "01 > 000001"
                
                //set aux bool cell 56 to true
                "1 +"
                //change to the case that the input character is line comment
                
                //go to cell 24 (minus 32) (100000)
                "01 < 000001"
                "1 ]"
            }
            
            {
                //For the case that input is not /
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 54 (add 32) (100000)
                "01 > 000001"
                
                //set aux bool cell 54 to true
                "1 +"
                //For running the following case that the input character is not line comment
                //Further check whether the input character is quote
                
                //go to cell 22 (minus 32) (100000)
                "01 < 000001"
                "1 ]"
            }
        }
        
        //go to cell 52 (add 30) (11110)
        "01 > 01111"
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
                "01 < 11"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                "01 < 01011"
                "1 +"
                "01 > 01011"
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42) (101010)
                "01 < 010101"
                
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
                //go to is_same (cell 0) (minus 22) (10110)
                "01 < 01101"
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
                
                //go to aux bool cell 59 (add 35) (100011)
                "01 > 110001"
                
                //set aux bool cell 59 to true
                "1 +"
                //change to the case that the function name is read
                
                //go to cell 24 (minus 35) (100011)
                "01 < 110001"
                "1 ]"
            }
            
            {
                //For the case that input is not quote
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 53 (add 31) (11111)
                "01 > 11111"
                
                //set aux bool cell 53 to true
                "1 +"
                //change to the case that the input character is not line comment and outside quote
                
                //go to cell 22 (minus 31) (11111)
                "01 < 11111"
                "1 ]"
            }
        }
        
        //go to cell 52 (add 30) (11110)
        "01 > 01111"
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
                "01 < 011"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                "01 < 01011"
                "1 +"
                "01 > 01011"
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 13 (minus 36) (100100)
                "01 < 001001"
                
                //set to 10 for newline (00001010)
                "1 +"
                "1 >>>"
                "1 >>>+"
                "1 >>>"
                //At cell 22
            }
            
            {
                //go to is_same (cell 0) (minus 22) (10110)
                "01 < 01101"
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
                
                //go to aux bool cell 53 (add 29) (11101)
                "01 > 10111"
                
                //set aux bool cell 53 to true
                "1 +"
                //change to the case that the input character is not line comment and outside quote
                
                //go to cell 24 (minus 29) (11101)
                "01 < 10111"
                "1 ]"
            }
            
            {
                //For the case that input is not newline
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 56 (add 34) (100010)
                "01 > 010001"
                
                //set aux bool cell 56 to true
                "1 +"
                //change to the case that the input character is line comment
                
                //go to cell 22 (minus 34) (100010)
                "01 < 010001"
                "1 ]"
            }
        }
        
        //go to cell 55 (add 33) (100001)
        "01 > 100001"
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
                "01 < 1001"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                "01 < 01011"
                "1 +"
                "01 > 01011"
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42) (101010)
                "01 < 010101"
                
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
                //go to is_same (cell 0) (minus 22) (10110)
                "01 < 01101"
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
                
                //set the temp binary 3 (add bit 0)
                {
                    //go to aux bool cell 162 (add 138) (10001010)
                    "01 > 01010001"
                    
                    //go to leftmost boundary of temp binary 3
                    "1 [<<<]"
                    
                    //add boundary
                    "1 +"
                    //set zero for leftmost bit
                    "1 <+"
                    
                    //go to boundary
                    "1 >"
                    //go to rightmost boundary (cell 165)
                    "1 [>>>]"
                }
                
                //change to the case that the function name is read
                {
                    //go to aux bool cell 59 (minus 106) (1101010)
                    "01 < 0101011"
                    
                    //set aux bool cell 59 to true
                    "1 +"
                }
                
                //go to cell 24 (minus 35) (100011)
                "01 < 110001"
                "1 ]"
            }
            
            {
                //For the case that input is not 0
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 60 (add 38) (100110)
                "01 > 011001"
                //set aux bool cell 60 to true
                "1 +"
                //change to the case that the function name is read
                //further checking
                
                //go to cell 22 (minus 38) (100110)
                "01 < 011001"
                "1 ]"
            }
        }
        
        //go to cell 58 (add 36) (100100)
        "01 > 001001"
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
                "01 < 1001"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                "01 < 01011"
                "1 +"
                "01 > 01011"
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42) (101010)
                "01 < 010101"
                
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
                //go to is_same (cell 0) (minus 22) (10110)
                "01 < 01101"
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
                
                //set the temp binary 3 (add bit 1)
                {
                    //go to aux bool cell 162 (add 138) (10001010)
                    "01 > 01010001"
                    
                    //go to leftmost boundary of temp binary 3
                    "1 [<<<]"
                    
                    //add boundary
                    "1 +"
                    
                    //add one for leftmost bit
                    "1 >+>-<<"
                    
                    //set zero for sub-leftmost bit
                    "1 <+"
                    
                    //go to boundary
                    "1 >"
                    //go to rightmost boundary (cell 165)
                    "1 [>>>]"
                }
                
                //change to the case that the function name is read
                {
                    //go to aux bool cell 59 (minus 106) (1101010)
                    "01 < 0101011"
                    
                    //set aux bool cell 59 to true
                    "1 +"
                }
                
                //go to cell 24 (minus 35) (100011)
                "01 < 110001"
                "1 ]"
            }
            
            {
                //For the case that input is not 1
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 60 (add 38) (100110)
                "01 > 011001"
                //set aux bool cell 60 to true
                "1 +"
                //change to the case that the function name is read
                //further checking
                
                //go to cell 22 (minus 38) (100110)
                "01 < 011001"
                "1 ]"
            }
        }
        
        //go to cell 58 (add 36) (100100)
        "01 > 001001"
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
            //go to bool cell of temp binary 3 (cell 162) (add 104) (1101000)
            "01 > 0001011"
            
            //for loop
            "1 ["
            
            //go to temp binary 3 (cell 165)
            "1 >>>"
            //subtract one
            "1 <[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]"
            
            //add one for function index
            //go to cell 169
            "1 >>>>"
            
            //go to the function index
            "1 [>>>]"
            
            //set zero
            "1 +<->"
            
            //set one
            "1 >>+>-<<<"
            
            //go to cell 166
            "1 [<<<]"
            
            //go to bool cell of temp binary 3 (cell 162)
            "1 <<<<"
            "1 ]"
        }
        
        //check whether the input is quote
        {
            {
                //go to input (cell 49) (minus 113) (1110001)
                "01 < 1000111"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                "01 < 01011"
                "1 +"
                "01 > 01011"
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42) (101010)
                "01 < 010101"
                
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
                //go to is_same (cell 0) (minus 22) (10110)
                "01 < 01101"
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
                
                //go to aux bool cell 67 (add 43) (101011)
                "01 > 110101"
                
                //set aux bool cell 67 to true
                "1 +"
                //change to the case that the function is running
                //run it immediately
                
                //go to cell 24 (minus 43) (101011)
                "01 < 110101"
                "1 ]"
            }
            
            {
                //For the case that input is not quote
                //Assume the input is whitespace
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 62 (add 40) (101000)
                "01 > 000101"
                //set aux bool cell 62 to true
                "1 +"
                //change to the case that the first argument is read
                
                //go to cell 22 (minus 40) (101000)
                "01 < 000101"
                "1 ]"
            }
        }
        
        //go to cell 58 (add 36) (100100)
        "01 > 001001"
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
                //go to input (cell 49) (minus 12) (1100)
                "01 < 0011"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                "01 < 01011"
                "1 +"
                "01 > 01011"
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42) (101010)
                "01 < 010101"
                
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
                //go to is_same (cell 0) (minus 22) (10110)
                "01 < 01101"
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
                
                //go to aux bool cell 67 (add 43) (101011)
                "01 > 110101"
                
                //set aux bool cell 67 to true
                "1 +"
                //change to the case that the function is running
                //run it immediately
                
                //go to cell 24 (minus 43) (101011)
                "01 < 110101"
                "1 ]"
            }
            
            {
                //For the case that input is not quote
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 63 (add 41) (101001)
                "01 > 100101"
                //set aux bool cell 63 to true
                "1 +"
                //change to the case that the first argument is read
                //further checking whether the input character is whitespace
                
                //go to cell 22 (minus 41) (101001)
                "01 < 100101"
                "1 ]"
            }
        }
        
        //go to cell 61 (add 39) (100111)
        "01 > 111001"
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
                //go to input (cell 49) (minus 12) (1100)
                "01 < 0011"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                "01 < 01011"
                "1 +"
                "01 > 01011"
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42) (101010)
                "01 < 010101"
                
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
                //go to is_same (cell 0) (minus 22) (10110)
                "01 < 01101"
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
                
                //go to aux bool cell 65 (add 41) (101001)
                "01 > 100101"
                //set aux bool cell 65 to true
                "1 +"
                //change to the case that the second argument is read
                
                //go to cell 24 (minus 41) (101001)
                "01 < 100101"
                "1 ]"
            }
            
            {
                //For the case that input is not whitespace
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 63 (add 41) (101001)
                "01 > 100101"
                //set aux bool cell 63 to true
                "1 +"
                //change to the case that the first argument is read
                //further get the first argument immediately
                
                //go to cell 22 (minus 41) (101001)
                "01 < 100101"
                "1 ]"
            }
        }
        
        //go to cell 61 (add 39) (100111)
        "01 > 111001"
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
                //go to input (cell 49) (minus 15) (1111)
                "01 < 1111"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                "01 < 01011"
                "1 +"
                "01 > 01011"
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42) (101010)
                "01 < 010101"
                
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
                //go to is_same (cell 0) (minus 22) (10110)
                "01 < 01101"
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
                
                //go to aux bool cell 67 (add 43) (101011)
                "01 > 110101"
                //set aux bool cell 67 to true
                "1 +"
                //change to the case that the function is running
                //run it immediately
                
                //go to cell 24 (minus 43) (101011)
                "01 < 110101"
                "1 ]"
            }
            
            {
                //For the case that input is not quote
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 66 (add 44) (101100)
                "01 > 001101"
                //set aux bool cell 66 to true
                "1 +"
                //change to the case that the second argument is read
                //further checking whether the input character is whitespace
                
                //go to cell 22 (minus 44) (101100)
                "01 < 001101"
                "1 ]"
            }
        }
        
        //go to cell 64 (add 42) (101010)
        "01 > 010101"
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
                //go to input (cell 49) (minus 15) (1111)
                "01 < 1111"
                
                //copy to cell 23
                //k = 23 - 49 = -26
                "1 <<<[->[-<+>>>"
                "01 < 01011"
                "1 +"
                "01 > 01011"
                "1 <<]<[->+<]+<<<]>>>[>>>]"
                //At cell 49
            }
            
            {
                //go to cell 7 (minus 42) (101010)
                "01 < 010101"
                
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
                //go to is_same (cell 0) (minus 22) (10110)
                "01 < 01101"
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
                
                //go to aux bool cell 68 (add 44) (101100)
                "01 > 001101"
                //set aux bool cell 68 to true
                "1 +"
                //change to the case that the third argument is read
                
                //go to cell 24 (minus 44) (101100)
                "01 < 001101"
                "1 ]"
            }
            
            {
                //For the case that input is not whitespace
                //go to else bool cell 22
                "1 <<"
                "1 [-"
                
                //go to aux bool cell 66 (add 44) (101100)
                "01 > 001101"
                //set aux bool cell 66 to true
                "1 +"
                //change to the case that the second argument is read
                //further get the second argument immediately
                
                //go to cell 22 (minus 44) (101100)
                "01 < 001101"
                "1 ]"
            }
        }
        
        //go to cell 64 (add 42) (101010)
        "01 > 010101"
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
        //go to function 1 (cell 171) (add 105) (1101001)
        "01 > 1001011"
        
        //if cell 171 is true
        "1 [-"
        
        //For the case that the first argument is read
        {
            //go to cell 61 (minus 110) (1101110)
            "01 < 0111011"
            
            //if cell 61 is true
            "1 [-"
            
            //go to constant value cell for input (cell 50) (minus 11) (1011)
            "01 < 1101"
            //output
            "1 ."
            
            //go to aux bool cell 62 (add 12) (1100)
            "01 > 0011"
            //set it to true
            "1 +"
            //change to the case that the first argument is read
            
            //go to cell 61
            "1 <"
            "1 ]"
        }
        
        //For running; do nothing
        
        //go to aux bool cell 173 (add 112) (1110000)
        "01 > 0000111"
        //set it to true
        "1 +"
        
        //go to cell 171
        "1 <<"
        "1 ]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For function 01: run a single code, for n times, e.g. "01 + 111"
    {
        //go to function 01 (cell 174)
        "1 >>>"
        
        //if cell 174 is true
        "1 [-"
        
        //For the case that the first argument is read
        {
            //go to cell 61 (minus 113) (1110001)
            "01 < 1000111"
            
            //if cell 61 is true
            "1 [-"
            
            //copy cell 50 to temp cell 3 (cell 72)
            {
                //go to cell 50 (minus 11) (1011)
                "01 < 1101"
                
                //copy cell 50 to cell 51 and 72
                "1 [->+"
                
                //go to cell 72 (add 21) (10101)
                "01 > 10101"
                "1 +"
                
                //go to cell 50 (minus 22) (10110)
                "01 < 01101"
                "1 ]"
                
                //copy cell 51 to cell 50
                "1 >"
                "1 [-<+>]"
                //At cell 51
            }
            
            //go to aux bool cell 62 (add 11) (1011)
            "01 > 1101"
            //set it to true
            "1 +"
            //change to the case that the first argument is read
            
            //go to cell 61 (minus 38)
            "1 <"
            "1 ]"
        }
        
        //For the case that the second argument is read
        //check whether the input is 0
        {
            //go to cell 64
            "1 >>>"
            //if cell 64 is true
            "1 [-"
            
            //check whether the input is 0
            {
                {
                    //go to input (cell 49) (minus 15) (1111)
                    "01 < 1111"
                    
                    //copy to cell 23
                    //k = 23 - 49 = -26
                    "1 <<<[->[-<+>>>"
                    "01 < 01011"
                    "1 +"
                    "01 > 01011"
                    "1 <<]<[->+<]+<<<]>>>[>>>]"
                    //At cell 49
                }
                
                {
                    //go to cell 7 (minus 42) (101010)
                    "01 < 010101"
                    
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
                    //go to is_same (cell 0) (minus 22) (10110)
                    "01 < 01101"
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
                    
                    //set the temp binary 1 (add bit 0)
                    {
                        //go to aux bool cell 100 (add 76) (1001100)
                        "01 > 0011001"
                        
                        //go to leftmost boundary of temp binary 1
                        "1 [<<<]"
                        
                        //add boundary
                        "1 +"
                        //set zero for leftmost bit
                        "1 <+"
                        
                        //go to boundary
                        "1 >"
                        //go to rightmost boundary (cell 103)
                        "1 [>>>]"
                    }
                    
                    //change to the case that the second argument is read
                    {
                        //go to aux bool cell 65 (minus 38) (100110)
                        "01 < 011001"
                        //set it to true
                        "1 +"
                        //change to the case that the second argument is read
                    }
                    
                    //go to cell 24 (minus 41) (101001)
                    "01 < 100101"
                    "1 ]"
                }
                
                {
                    //For the case that input is not 0
                    //go to else bool cell 22
                    "1 <<"
                    "1 [-"
                    
                    //go to aux bool cell 66 (add 44) (101100)
                    "01 > 001101"
                    //set aux bool cell 66 to true
                    "1 +"
                    //change to the case that the second argument is read
                    //further checking
                    
                    //go to cell 22 (minus 44) (101100)
                    "01 < 001101"
                    "1 ]"
                }
            }
            
            //go to cell 64 (add 42) (101010)
            "01 > 010101"
            "1 ]"
        }
        
        //For further checking whether the input character is 1, if cell 66 is true
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
        //Further check whether the input is 1
        {
            //go to cell 64
            "1 <<"
            //if cell 64 is true
            "1 [-"
            
            //check whether the input is 1
            {
                {
                    //go to input (cell 49) (minus 15) (1111)
                    "01 < 1111"
                    
                    //copy to cell 23
                    //k = 23 - 49 = -26
                    "1 <<<[->[-<+>>>"
                    "01 < 01011"
                    "1 +"
                    "01 > 01011"
                    "1 <<]<[->+<]+<<<]>>>[>>>]"
                    //At cell 49
                }
                
                {
                    //go to cell 7 (minus 42) (101010)
                    "01 < 010101"
                    
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
                    //go to is_same (cell 0) (minus 22) (10110)
                    "01 < 01101"
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
                    
                    //set the temp binary 1 (add bit 1)
                    {
                        //go to aux bool cell 100 (add 76) (1001100)
                        "01 > 0011001"
                        
                        //go to leftmost boundary of temp binary 1
                        "1 [<<<]"
                        
                        //add boundary
                        "1 +"
                        
                        //add one for leftmost bit
                        "1 >+>-<<"
                        
                        //set zero for sub-leftmost bit
                        "1 <+"
                        
                        //go to boundary
                        "1 >"
                        //go to rightmost boundary (cell 103)
                        "1 [>>>]"
                    }
                    
                    //change to the case that the second argument is read
                    {
                        //go to aux bool cell 65 (minus 38) (100110)
                        "01 < 011001"
                        //set it to true
                        "1 +"
                        //change to the case that the second argument is read
                    }
                    
                    //go to cell 24 (minus 41) (101001)
                    "01 < 100101"
                    "1 ]"
                }
                
                {
                    //For the case that input is not 1
                    //go to else bool cell 22
                    "1 <<"
                    "1 [-"
                    "1 ]"
                }
            }
            
            //go to cell 64 (add 42) (101010)
            "01 > 010101"
            "1 ]"
        }
        
        //For running
        {
            //go to cell 67
            "1 >>>"
            
            //if cell 67 is true
            "1 [-"
            
            //output n times
            {
                //go to bool cell of temp binary 1 (cell 100) (add 33) (100001)
                "01 > 100001"
                
                //for loop
                "1 ["
                
                //go to temp binary 1 (cell 103)
                "1 >>>"
                //subtract one
                "1 <[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]"
                
                //go to temp cell 3 (cell 72) (minus 31) (11111)
                "01 < 11111"
                
                //output
                "1 ."
                
                //go to bool cell of temp binary 1 (cell 100) (add 28) (11100)
                "01 > 00111"
                "1 ]"
                
                //go to temp cell 3 (cell 72) (minus 28) (11100)
                "01 < 00111"
                //clear
                "1 [-]"
            }
            
            {
                //go to aux bool cell 69
                "1 <<<"
                
                //set aux bool cell 69 to true
                "1 +"
                //change to the case that the function is running
                //further finalize the running
            }
            
            //go to cell 67
            "1 <<"
            "1 ]"
        }
        
        //go to aux bool cell 176 (add 109) (1101101)
        "01 > 1011011"
        //set it to true
        "1 +"
        
        //go to cell 174
        "1 <<"
        "1 ]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For function 11: output the code in the first argument
    {
        //go to function 11 (cell 177)
        "1 >>>"
        
        //if cell 177 is true
        "1 [-"
        
        //For the case that the first argument is read
        {
            //go to cell 61 (minus 116) (1110100)
            "01 < 0010111"
            
            //if cell 61 is true
            "1 [-"
            
            //copy input to temp binary 1
            {
                //go to cell 102 (add 41) (101001)
                "01 > 100101"
                //set it to zero
                "1 -"
                
                //go to input (cell 49) (minus 53) (110101)
                "01 < 101011"
                
                //full copy to temp binary 1 (cell 103)
                //k = 103 - 49 = 54 (110110)
                "1 <<<[->[-<+>"
                "01 > 011011"
                "1 +<+>"
                "01 < 011011"
                "1 ]<[->+<]>>[-<<+>>"
                "01 > 011011"
                "1 +<<+>>"
                "01 < 011011"
                "1 ]<<[->>+<<]+<<<]"
                "01 > 011011"
                "1 >>+<<"
                "01 < 011011"
                "1 >>>[>>>]"
                //At cell 49
            }
            
            {
                //go to temp cell 3 (cell 72) (add 23) (10111)
                "01 > 11101"
                //set it to + (43) (101011)
                "01 + 110101"
            }
            
            {
                //go to bool cell of temp binary 1 (cell 100) (add 28) (11100)
                "01 > 00111"
                
                //for loop
                "1 ["
                
                //go to temp binary 1 (cell 103)
                "1 >>>"
                //subtract one
                "1 <[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]"
                
                //go to temp cell 3 (cell 72) (minus 31) (11111)
                "01 < 11111"
                //output +
                "1 ."
                
                //go to bool cell of temp binary 1 (cell 100) (add 28) (11100)
                "01 > 00111"
                "1 ]"
            }
            
            {
                //go to temp cell 3 (cell 72) (minus 28) (10111)
                "01 < 00111"
                //set it to . (46) (add 101011)
                "1 +++"
                //output .
                "1 ."
                
                //set it to [ (91) (add 101101)
                "01 + 101101"
                //output [
                "1 ."
                
                //set it to - (45) (miuns 101110)
                "01 - 011101"
                //output -
                "1 ."
                
                //set it to ] (93) (add 110000)
                "01 + 000011"
                //output ]
                "1 ."
                
                //clear
                "1 [-]"
            }
            
            //go to aux bool cell 62 (minus 10) (1010)
            "01 < 0101"
            //set it to true
            "1 +"
            //change to the case that the first argument is read
            
            //go to cell 61
            "1 <"
            "1 ]"
        }
        
        //For running; do nothing
        
        //go to aux bool cell 179 (add 118) (1110110)
        "01 > 0110111"
        //set it to true
        "1 +"
        
        //go to cell 177
        "1 <<"
        "1 ]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //For function 001: output a single code, for n times
    {
        //go to function 001 (cell 180)
        "1 >>>"
        
        //if cell 180 is true
        "1 [-"
        
        //For the case that the first argument is read
        {
            //go to cell 61 (minus 119) (1110111)
            "01 < 1110111"
            
            //if cell 61 is true
            "1 [-"
            
            //copy input to temp binary 1
            {
                //go to cell 102 (add 41) (101001)
                "01 > 100101"
                //set it to zero
                "1 -"
                
                //go to input (cell 49) (minus 53) (110101)
                "01 < 101011"
                
                //full copy to temp binary 1 (cell 103)
                //k = 103 - 49 = 54 (110110)
                "1 <<<[->[-<+>"
                "01 > 011011"
                "1 +<+>"
                "01 < 011011"
                "1 ]<[->+<]>>[-<<+>>"
                "01 > 011011"
                "1 +<<+>>"
                "01 < 011011"
                "1 ]<<[->>+<<]+<<<]"
                "01 > 011011"
                "1 >>+<<"
                "01 < 011011"
                "1 >>>[>>>]"
                //At cell 49
            }
            
            {
                //go to temp cell 3 (cell 72) (add 23) (10111)
                "01 > 11101"
                //set it to + (43) (101011)
                "01 + 110101"
            }
            
            {
                //go to bool cell of temp binary 1 (cell 100) (add 28) (11100)
                "01 > 00111"
                
                //for loop
                "1 ["
                
                //go to temp binary 1 (cell 103)
                "1 >>>"
                //subtract one
                "1 <[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]"
                
                //go to temp cell 3 (cell 72) (minus 31) (11111)
                "01 < 11111"
                //output +
                "1 ."
                
                //go to bool cell of temp binary 1 (cell 100) (add 28) (11100)
                "01 > 00111"
                "1 ]"
            }
            
            //go to aux bool cell 62 (minus 38) (100110)
            "01 < 011001"
            //set it to true
            "1 +"
            //change to the case that the first argument is read
            
            //go to cell 61
            "1 <"
            "1 ]"
        }
        
        //For the case that the second argument is read
        //check whether the input is 0
        {
            //go to cell 64
            "1 >>>"
            //if cell 64 is true
            "1 [-"
            
            //check whether the input is 0
            {
                {
                    //go to input (cell 49) (minus 15) (1111)
                    "01 < 1111"
                    
                    //copy to cell 23
                    //k = 23 - 49 = -26
                    "1 <<<[->[-<+>>>"
                    "01 < 01011"
                    "1 +"
                    "01 > 01011"
                    "1 <<]<[->+<]+<<<]>>>[>>>]"
                    //At cell 49
                }
                
                {
                    //go to cell 7 (minus 42) (101010)
                    "01 < 010101"
                    
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
                    //go to is_same (cell 0) (minus 22) (10110)
                    "01 < 01101"
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
                    
                    //set the temp binary 1 (add bit 0)
                    {
                        //go to aux bool cell 100 (add 76) (1001100)
                        "01 > 0011001"
                        
                        //go to leftmost boundary of temp binary 1
                        "1 [<<<]"
                        
                        //add boundary
                        "1 +"
                        //set zero for leftmost bit
                        "1 <+"
                        
                        //go to boundary
                        "1 >"
                        //go to rightmost boundary (cell 103)
                        "1 [>>>]"
                    }
                    
                    //change to the case that the second argument is read
                    {
                        //go to aux bool cell 65 (minus 38) (100110)
                        "01 < 011001"
                        //set it to true
                        "1 +"
                        //change to the case that the second argument is read
                    }
                    
                    //go to cell 24 (minus 41) (101001)
                    "01 < 100101"
                    "1 ]"
                }
                
                {
                    //For the case that input is not 0
                    //go to else bool cell 22
                    "1 <<"
                    "1 [-"
                    
                    //go to aux bool cell 66 (add 44) (101100)
                    "01 > 001101"
                    //set aux bool cell 66 to true
                    "1 +"
                    //change to the case that the second argument is read
                    //further checking
                    
                    //go to cell 22 (minus 44) (101100)
                    "01 < 001101"
                    "1 ]"
                }
            }
            
            //go to cell 64 (add 42) (101010)
            "01 > 010101"
            "1 ]"
        }
        
        //For further checking whether the input character is 1, if cell 66 is true
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
        //Further check whether the input is 1
        {
            //go to cell 64
            "1 <<"
            //if cell 64 is true
            "1 [-"
            
            //check whether the input is 1
            {
                {
                    //go to input (cell 49) (minus 15) (1111)
                    "01 < 1111"
                    
                    //copy to cell 23
                    //k = 23 - 49 = -26
                    "1 <<<[->[-<+>>>"
                    "01 < 01011"
                    "1 +"
                    "01 > 01011"
                    "1 <<]<[->+<]+<<<]>>>[>>>]"
                    //At cell 49
                }
                
                {
                    //go to cell 7 (minus 42) (101010)
                    "01 < 010101"
                    
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
                    //go to is_same (cell 0) (minus 22) (10110)
                    "01 < 01101"
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
                    
                    //set the temp binary 1 (add bit 1)
                    {
                        //go to aux bool cell 100 (add 76) (1001100)
                        "01 > 0011001"
                        
                        //go to leftmost boundary of temp binary 1
                        "1 [<<<]"
                        
                        //add boundary
                        "1 +"
                        
                        //add one for leftmost bit
                        "1 >+>-<<"
                        
                        //set zero for sub-leftmost bit
                        "1 <+"
                        
                        //go to boundary
                        "1 >"
                        //go to rightmost boundary (cell 103)
                        "1 [>>>]"
                    }
                    
                    //change to the case that the second argument is read
                    {
                        //go to aux bool cell 65 (minus 38) (100110)
                        "01 < 011001"
                        //set it to true
                        "1 +"
                        //change to the case that the second argument is read
                    }
                    
                    //go to cell 24 (minus 41) (101001)
                    "01 < 100101"
                    "1 ]"
                }
                
                {
                    //For the case that input is not 1
                    //go to else bool cell 22
                    "1 <<"
                    "1 [-"
                    "1 ]"
                }
            }
            
            //go to cell 64 (add 42) (101010)
            "01 > 010101"
            "1 ]"
        }
        
        //For running
        {
            //go to cell 67
            "1 >>>"
            
            //if cell 67 is true
            "1 [-"
            
            {
                //go to temp cell 3 (cell 72)
                "1 >>>>>"
                //set it to . (46)
                "1 +++"
                
                //go to bool cell of temp binary 1 (cell 100) (add 28) (11100)
                "01 > 00111"
                
                //for loop
                "1 ["
                
                //go to temp binary 1 (cell 103)
                "1 >>>"
                //subtract one
                "1 <[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]"
                
                //go to temp cell 3 (cell 72) (minus 31) (11111)
                "01 < 11111"
                //output .
                "1 ."
                
                //go to bool cell of temp binary 1 (cell 100) (add 28) (11100)
                "01 > 00111"
                "1 ]"
            }
            
            {
                //go to temp cell 3 (cell 72) (minus 28) (11100)
                "01 < 00111"
                //set it to [ (91) (add 101101)
                "01 + 101101"
                //output [
                "1 ."
                
                //set it to - (45) (miuns 101110)
                "01 - 011101"
                //output -
                "1 ."
                
                //set it to ] (93) (add 110000)
                "01 + 000011"
                //output ]
                "1 ."
                
                //clear
                "1 [-]"
            }
            
            {
                //go to aux bool cell 69
                "1 <<<"
                
                //set aux bool cell 69 to true
                "1 +"
                //change to the case that the function is running
                //further finalize the running
            }
            
            //go to cell 67
            "1 <<"
            "1 ]"
        }
        
        //go to aux bool cell 182 (add 115) (1110011)
        "01 > 1100111"
        //set it to true
        "1 +"
        
        //go to cell 180
        "1 <<"
        "1 ]"
    }
    
    //For further finalize the running, if cell 69 is true
    {
        //go to aux bool cell 69 (minus 111) (1101111)
        "01 < 1111011"
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
        //go to cell 169 (add 102) (1100110)
        "01 > 0110011"
        
        //go to the current function index
        "1 [>>>]"
        
        //reset the aux bool cell
        "1 +>-<"
        
        //go to cell 166
        "1 [<<<]"
        
        //reset the aux bool cell
        "1 >>+>-"
        //At cell 169
        
        //go to aux bool cell 53 (minus 116) (1110100)
        "01 < 0010111"
        //set aux bool cell 53 to true
        "1 +"
        //change to the case that the input character is not line comment and outside quote
        
        //go to cell 67 (add 14) (1110)
        "01 > 0111"
        "1 ]"
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////
    //reset all bool cells
    {
        {
            //go to aux cell 53 (minus 14) (1110)
            "01 < 0111"
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
            //go to aux cell 173 (add 105) (1101001)
            "01 > 1001011"
            //if cell 173 is true; set cell 173 to false; set cell 171 to true
            "1 [-<<+>>]"
            
            //go to aux cell 176
            "1 >>>"
            //if cell 176 is true; set cell 176 to false; set cell 174 to true
            "1 [-<<+>>]"
            
            //go to aux cell 179
            "1 >>>"
            //if cell 179 is true; set cell 179 to false; set cell 177 to true
            "1 [-<<+>>]"
            
            //go to aux cell 182
            "1 >>>"
            //if cell 182 is true; set cell 182 to false; set cell 180 to true
            "1 [-<<+>>]"
        }
    }
    
    //update the value of input
    {
        //go to input (cell 49) (minus 133) (10000101)
        "01 < 10100001"
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
