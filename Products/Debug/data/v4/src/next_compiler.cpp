//remove line comment (remove any character between / and newline)
//remove all characters except the 8 special characters and c (if it is not line comment)
//using binary number

//include binary_initialize
//include binary_add_one
//include binary_subtract_one
//include binary_clear
//include binary_copy_half
//include binary_copy_full
//include binary_move_half
//include binary_is_same
//include mapping_initialize
//include mapping_run

//cell 0 to 15: counter; 4 bit
">>>>>>>>>>>>>>+>"

//cell 16 to 31: input for mapping; 4 bit
">"
">>>>>>>>>>>>>>>"
//cell 32: bool for mapping
">"
//cell 33 to 57: output for mapping; 7 bit
">"
">>>>>>>>>>>>>>>>>>>>>>>+>"

//cell 58 to 82: is_same; 7 bit
">"
">>>+>>>+>>>+>>>+>>>+>>>+>>>+>>>"

//cell 83 to 107: input; 7 bit
">"
">>>>>>>>>>>>>>>>>>>>>>>+>"

//cell 108: input cell (copy)
//cell 109: input cell (zero after copying)
">>"

//cell 110: bool for the case that the input character is line comment
//cell 111: aux cell for cell 110 (continues; not redo any 110 bool if block)
//cell 112: aux cell for cell 110 (do other 110 bool if block)
">>>"

//cell 113: bool for the case that the input character is not line comment
//cell 114: aux cell for cell 113 (continues; not redo any 113 bool if block)
//cell 115: aux cell for cell 113 (do other 113 bool if block)
">+>>"

//fill the value of input
{
    //go to cell 109
    "<<<<<<"
    //get input
    ","
    
    //copy it to cell 108 and binary number
    "[-<+"
    //go to cell 107
    "<"
    //add one
    "<<[<<<]>-<<[->+>+<<]+>[-<->]<[->>+<<<+>]>>[-<<+>>]<+>>[>->+>]"
    
    //go to cell 109
    ">>"
    "]"
}

//while(input)
{
    //go to cell 104 (bool whether the input is not zero)
    "<<<<<"
    //if input is not zero
    "["

    //For the case that the input character is not line comment
    {
        //go to cell 113 (add 9)
        ">>>>>>>>>"
        //if cell 113 is true
        "["
        //set cell 113 to false; set cell 114 to true
        "->+"

        //check whether the first input is /
        {
            {
                //go to input (cell 107)
                "<<<<<<<"

                //copy to cell 81
                //k = 81 - 107 = -26
                "<<<[->[-<+>>>"
                
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<"
                
                "+"
                
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>"
                
                "<<]<[->+<]+<<<]>>>[>>>]"
            }
            
            {
                //go to cell 65 (minus 42)
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
                //At cell 80
            }

            {
                //go to is_same (cell 58) (minus 22)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                //run is_same
                ">+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 82
            }
        }

        {
            //go to the compare result (cell 80)
            "<<"
            //copy it to cell 81 and 82
            "[->+>+<<]"
            
            //go to cell 80
            //cell 80 is NOT gate of cell 81
            "+>[-<->]<"

            {
                //input is /
                //go to if bool cell (cell 82)
                ">>"
                "[-"

                //go to aux bool cell 114 (add 32)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>"
                //set aux bool cell 114 to false
                "-"

                //go to aux bool cell 111
                "<<<"
                //set aux bool cell 111 to true
                "+"
                //change to the case that the input character is line comment

                //go to cell 82 (minus 29)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<"
                "]"
            }

            {
                //input is not /
                //go to else bool cell 80
                "<<"
                "[-"

                //go to aux bool cell 114 (add 34)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>"
                //set aux bool cell 114 to false
                "-"

                //go to aux bool cell 115
                ">"
                //set aux bool cell 115 to true
                "+"
                //For running the following case that the input character is not line comment

                //go to cell 80 (minus 35)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<"
                "]"
            }
        }

        //go to cell 113 (add 33)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>"
        "]"
    }

    //For running the following case that the input character is not line comment; if cell 115 is true
    {
        //go to aux bool cell 115
        ">>"
        //if cell 115 is true
        "["
        //set aux bool cell 115 to false
        "-"

        //go to aux bool cell 113
        "<<"
        //set aux bool cell 113 to true
        "+"

        //go to aux bool cell 115
        ">>"
        "]"
    }

    //For the case that the input character is not line comment
    {
        //go to cell 113
        "<<"
        //if cell 113 is true
        "["
        //set cell 113 to false; set cell 114 to true
        "->+"
        
        //set the counter to 9
        {
            //go to cell 2 (minus 112)
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            
            "<<<<<<<<<<"
            "<<"
            
            //set from 0 (nnnne) to 9 (e1001)
            "+>"
            "+>+>>"
            "+>>+>"
            "+>>+>"
            "+>+>->"
            //At cell 15
        }
        
        //for loop
        {
            //go to cell 12 (bool whether the counter is not zero)
            "<<<"
            //if cell 12 is not zero
            "["

            {
                //go to counter (cell 15)
                ">>>"

                //copy to input for mapping (cell 31)
                //k = 31 - 15 = 16
                //binary_copy_full
                "<<<[->[-<+>"
                ">>>>>>>>>>>>>>>>" //k times
                "+<+>"
                "<<<<<<<<<<<<<<<<" //k times
                "]<[->+<]>>[-<<+>>"
                ">>>>>>>>>>>>>>>>" //k times
                "+<<+>>"
                "<<<<<<<<<<<<<<<<" //k times
                "]<<[->>+<<]+<<<]"
                ">>>>>>>>>>>>>>>>" //k times
                ">>+<<"
                "<<<<<<<<<<<<<<<<" //k times
                ">>>[>>>]"
            }

            {
                //go to mapping (cell 28) (add 13)
                ">>>>>>>>>>"
                ">>>"

                //do mapping
                "[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>+>+>+>>+>>+>+>+>>+>>+>+>+>>+>+>-><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>+>->>->+>>->+><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>>>>>>>+>-><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>>>>+>->>->+><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>+>->>>>>>>>->+>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>>>>+>->>>><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>+>+>+>->>->+>>>>>>>>->+>>>>>+>-><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>+>->>->+>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>+>->>->+>>->+>>->+>>+>->>>><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<>>-<<"
                //At cell 28
            }

            {
                //go to the output of mapping (cell 57) (add 29)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>"

                //destructive copy from cell 57 to cell 80
                //binary_move_half
                //k = 80 - 57 = 23
                "<<<[>[->>"
                
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>"
                
                "+"
                
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<"
                
                "<<]>[-]<<<<<]>>->[->>>]<+>"
                //At cell 57
            }
            
            {
                //go to input (cell 107) (add 50)
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                
                //copy to cell 81
                //k = 81 - 107 = -26
                "<<<[->[-<+>>>"
                
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<"
                
                "+"
                
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>"
                
                "<<]<[->+<]+<<<]>>>[>>>]"
                //At cell 107
            }
            
            {
                //go to is_same (cell 58) (minus 49)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<"
                //run is_same
                ">+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 82

                {
                    //go to the compare result (cell 80)
                    "<<"
                    //if compare resuit is true
                    "[-"

                    {
                        //go to constant value cell for input (cell 108) (add 28)
                        ">>>>>>>>>>"
                        ">>>>>>>>>>"
                        ">>>>>>>>"
                        //output
                        "."
                    }

                    //break
                    {
                        //go to counter (cell 15) (minus 93)
                        "<<<<<<<<<<"
                        "<<<<<<<<<<"
                        "<<<<<<<<<<"
                        "<<<<<<<<<<"
                        "<<<<<<<<<<"
                        "<<<<<<<<<<"
                        "<<<<<<<<<<"
                        "<<<<<<<<<<"
                        "<<<<<<<<<<"
                        "<<<"
                        
                        //update value to 1
                        "<<<[<<<]>>[-]>[->[-]>[-]>]<<<<+>+>+>>"
                        //At cell 15
                    }

                    //go to cell 80 (add 65)
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>>>>>>"
                    ">>>>>"
                    "]"
                }
            }

            //go to counter (cell 15) (minus 65)
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<"
            
            //subtract the counter by 1
            "<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]"
            
            //go to cell 12 (bool whether the counter is not zero)
            "<<<"
            //end for loop
            "]"
        }

        //go to cell 113 (add 101)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        
        ">"
        "]"
    }

    //For the case that the input character is line comment
    {
        //go to cell 110
        "<<<"
        //if cell 110 is true
        "["

        //set cell 110 to false; set cell 111 to true
        "->+"

        //check whether the first input is newline
        {
            {
                //go to input (cell 107)
                "<<<<"
                
                //copy to cell 81
                //k = 81 - 107 = -26
                "<<<[->[-<+>>>"
                
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<"
                
                "+"
                
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>"
                
                "<<]<[->+<]+<<<]>>>[>>>]"
                //At cell 107
            }

            {
                //go to cell 71 (minus 36)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<"
                
                //set to 10 for newline (00001010)
                "+"
                ">>>"
                ">>>+"
                ">>>"
                //At cell 80
            }

            {
                //go to is_same (cell 58) (minus 22)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<"
                //run is_same
                ">+>>[->[-<<+>[-<->]<[->+<]>>]>[-<<<+>[-<->]<[->+<]>>>]<<[-<<[-]>>]<<[->>>+<<<]>>+>>>]"
                //At cell 82
            }
        }

        {
            //go to cell 80
            "<<"
            //if compare resuit is true
            "[-"

            //go to aux bool cell 111 (add 31)
            ">>>>>>>>>>"
            ">>>>>>>>>>"
            ">>>>>>>>>>"
            ">"
            //set aux bool cell 111 to false
            "-"

            //go to aux bool cell 114
            ">>>"
            //set aux bool cell 114 to true
            "+"
            //change to the case that the input character is not line comment

            //go to cell 80 (minus 34)
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<<<<<<<"
            "<<<<"
            "]"
        }

        //go to cell 110 (add 30)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        "]"
    }

    {
        //go to aux cell 111
        ">"
        //if cell 111 is true; set cell 111 to false; set cell 110 to true
        "[-<+>]"

        //go to aux cell 114
        ">>>"
        //if cell 114 is true; set cell 114 to false; set cell 113 to true
        "[-<+>]"
    }

    //go to input (cell 107)
    "<<<<<<<"
    //clear
    "<<<[<<<]>>[-]>[->[-]>[-]>]<+>"
    
    //go to cell 108
    ">"
    //clear
    "[-]"

    //update the value of input
    {
        //go to cell 109
        ">"
        //get input
        ","
        
        //copy it to cell 108 and binary number
        "[-<+"
        //go to cell 107
        "<"
        //add one
        "<<[<<<]>-<<[->+>+<<]+>[-<->]<[->>+<<<+>]>>[-<<+>>]<+>>[>->+>]"
        
        //go to cell 109
        ">>"
        "]"
    }
    
    //go to cell 104 (bool whether the input is not zero)
    "<<<<<"
    //end while loop
    "]"
}
