//remove line comment (remove any character between / and newline)
//remove all characters except the 8 special characters (if it is not line comment)

//include is_same
//include mapping_initialize
//include mapping_run
//include generator_initialize
//include generator_update
//include generator_copy

//cell 0 to 6: generator for input
//go to cell 0
//initialize generator
"+"
//update value by input
"[->+>>>[-]>>[-]<,[-<+>>+<]<<<<<]>>[->+>>[-]>[-]<<,[->+>+<<]><<<]<[-<+>]>>[-<+>]<<<"

//cell 7 to 13: generator for counter
//go to cell 7
">>>>>>>"
//initialize generator
"+"

//cell 14 to 19: mapping for the 8 special characters
//go to cell 14
">>>>>>>"
//initialize mapping
">+<"

//cell 20 to 28: is_same
//cell 23: copy for input characters
//cell 26: copy for special characters

//cell 29: bool for the case that the input character is line comment
//cell 30: aux cell for cell 29 (continues; not redo any 29 bool if block)
//cell 31: aux cell for cell 29 (do other 29 bool if block)

//cell 32: bool for the case that the input character is not line comment
//cell 33: aux cell for cell 32 (continues; not redo any 32 bool if block)
//cell 34: aux cell for cell 32 (do other 32 bool if block)
//go to cell 32 (add 18)
">>>>>>>>>>"
">>>>>>>>"
//set to true
"+"

//cell 35: general if bool
//cell 36: general else bool

//while(input)
{
    //go to constant value cell for input (cell 6) (minus 26)
    "<<<<<<<<<<"
    "<<<<<<<<<<"
    "<<<<<<"
    //if input is not zero
    "["
    "c" //p146
    
    //For the case that the input character is not line comment
    {
        //go to cell 32 (add 26)
        ">>>>>>>>>>"
        ">>>>>>>>>>"
        ">>>>>>"
        //if cell 32 is true
        "["
        //set cell 32 to false; set cell 33 to true
        "->+"
        
        //check whether the first input is /
        {
            {
                //go to input (cell 0)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<"
                "c" //p209
                
                //copy to cell 23
                //n = x - 6 = 23 - 6 = 17
                "[->+>>>[->+>"
                ">>>>>>>>>>>>>>>>>"
                "+"
                "<<<<<<<<<<<<<<<<<"
                "<<]<<<<]>>[->+>>[-<+>>"
                ">>>>>>>>>>>>>>>>>"
                "+"
                "<<<<<<<<<<<<<<<<<"
                "<]<<<]<[->+<]>>[-<<<+>>>]<<<"
                "c" //p341
            }
            
            {
                //go to cell 26
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>"
                //set to 47 for /
                "++++++++++"
                "++++++++++"
                "++++++++++"
                "++++++++++"
                "+++++++"
                "c" //p414
            }
            
            {
                //go to is_same (cell 20)
                "<<<<<<"
                //run is_same
                ">+[->>->>>-<<<<>[>+>]<[<]>>>>[>+>]<[<]>>[-<<<[-<<<+>>>]>>>]<<<[-]<<<]>>[>+>]<[<]>[-]>>>[>+>]<[<]>[-]<+<[->-<]>>>>+<[->-<]>[-<<<[-<<<<<+>>>>>]>>>]<<<[-]<<<<<"
                "c" //p576
                //At cell 20
            }
        }
        
        {
            //At cell 20
            //go to else bool cell (cell 36)
            ">>>>>>>>>>"
            ">>>>>>"
            //set else bool to true
            "+"
            
            {
                //go to cell 20
                "<<<<<<<<<<"
                "<<<<<<"
                "c" //p609
                
                //if compare resuit is true
                "[-"
                
                //go to if bool cell (cell 35)
                ">>>>>>>>>>"
                ">>>>>"
                //set to true
                "+"
                //go to else bool cell (cell 36)
                ">"
                //set to false
                "-"
                
                //go to cell 20 (minus 16)
                "<<<<<<<<<<"
                "<<<<<<"
                "]"
                "c" //p646
            }
            
            {
                //input is /
                //go to if bool cell (cell 35)
                ">>>>>>>>>>"
                ">>>>>"
                "[-"
                
                //go to aux bool cell 33
                "<<"
                //set aux bool cell 33 to false
                "-"
                
                //go to aux bool cell 30
                "<<<"
                //set aux bool cell 30 to true
                "+"
                //change to the case that the input character is line comment
                
                //go to cell 35
                ">>>>>"
                "]"
                "c" //p676
            }
            
            {
                //input is not /
                //go to else bool cell (cell 36)
                ">"
                "[-"
                
                //go to aux bool cell 33
                "<<<"
                //set aux bool cell 33 to false
                "-"
                
                //go to aux bool cell 34
                ">"
                //set aux bool cell 34 to true
                "+"
                //For running the following case that the input character is not line comment
                
                //go to cell 36
                ">>"
                "]"
                "c" //p688
            }
        }
        
        //go to cell 32
        "<<<<"
        "]"
    }
    
    //For running the following case that the input character is not line comment; if cell 34 is true
    {
        //go to aux bool cell 34
        ">>"
        //if cell 34 is true
        "["
        //set aux bool cell 34 to false
        "-"
        
        //go to aux bool cell 32
        "<<"
        //set aux bool cell 32 to true
        "+"
        
        //go to aux bool cell 34
        ">>"
        "]"
        "c" //p703
    }
    
    //For the case that the input character is not line comment
    {
        //go to cell 32
        "<<"
        //if cell 32 is true
        "["
        //set cell 32 to false; set cell 33 to true
        "->+"
        
        //go to counter (cell 7) (minus 26)
        "<<<<<<<<<<"
        "<<<<<<<<<<"
        "<<<<<<"
        //update value by adding 8
        "[->+>>>++++++++>>++++++++<<<<<<]>>[->+>>++++++++>++++++++<<<<]<[-<+>]>>[-<+>]<<<"
        
        //for loop
        {
            //go to constant value cell for counter (cell 13)
            ">>>>>>"
            //if cell 13 is not zero
            "["
            "c" //p822
            
            {
                //go to input (cell 0)
                "<<<<<<<<<<<<<"
                
                //copy to cell 23
                //n = x - 6 = 23 - 6 = 17
                "[->+>>>[->+>"
                ">>>>>>>>>>>>>>>>>"
                "+"
                "<<<<<<<<<<<<<<<<<"
                "<<]<<<<]>>[->+>>[-<+>>"
                ">>>>>>>>>>>>>>>>>"
                "+"
                "<<<<<<<<<<<<<<<<<"
                "<]<<<]<[->+<]>>[-<<<+>>>]<<<"
            }
            
            {
                //go to counter (cell 7)
                ">>>>>>>"
                "c" //p974
                
                //copy to input for mapping (cell 16)
                //n = x - 13 = 16 - 13 = 3
                "[->+>>>[->+>"
                ">>>"
                "+"
                "<<<"
                "<<]<<<<]>>[->+>>[-<+>>"
                ">>>"
                "+"
                "<<<"
                "<]<<<]<[->+<]>>[-<<<+>>>]<<<"
            }
            
            {
                //go to mapping (cell 14)
                ">>>>>>>"
                "c" //p1057
                
                //do mapping
                ">>[->>+<]<<[<]>>>>[->+++++++++++++++++++++++++++++++++++++++++++<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->++++++++++++++<]<<[->>+<]<<[<]>>>>[->++<]<<[->>+<]<<[<]>>>>[->+++++++++++++++++++++++++++++<]<<[->>+<]<<[<]>>>>[->++<]<<"
                "c" //p1336
                //At cell 16
            }
            
            {
                //go to result of mapping (cell 19)
                ">>>"
                
                //destructive copy from cell 19 to cell 26
                "[-"
                ">>>>>>>"
                "+"
                "<<<<<<<"
                "]"
                "c" //p1357
            }
            
            {
                //go to is_same (cell 20)
                ">"
                //run is_same
                ">+[->>->>>-<<<<>[>+>]<[<]>>>>[>+>]<[<]>>[-<<<[-<<<+>>>]>>>]<<<[-]<<<]>>[>+>]<[<]>[-]>>>[>+>]<[<]>[-]<+<[->-<]>>>>+<[->-<]>[-<<<[-<<<<<+>>>>>]>>>]<<<[-]<<<<<"
                "c" //p1514
                //At cell 20
                
                {
                    //At cell 20
                    //if compare resuit is true
                    "[-"
                    
                    {
                        //go to constant value cell for input (cell 6)
                        "<<<<<<<<<<<<<<"
                        //output
                        "."
                        "c" //p1531
                    }
                    
                    //break
                    {
                        //go to counter (cell 7)
                        ">"
                        //update value to 1
                        "[->+>>>[-]+>>[-]+<<<<<<]>>[->+>>[-]+>[-]+<<<<]<[-<+>]>>[-<+>]<<<"
                    }
                    
                    //go to cell 20
                    ">>>>>>>>>>>>>"
                    "]"
                    "c" //p1610
                }
            }
            
            //go to counter (cell 7)
            "<<<<<<<<<<<<<"
            //update value by subtract 1
            "[->+>>>->>-<<<<<<]>>[->+>>->-<<<<]<[-<+>]>>[-<+>]<<<"
            
            //go to constant value cell for counter (cell 13)
            ">>>>>>"
            //end for loop
            "]"
            "c" //p1682
        }
        
        //go to cell 32 (add 19)
        ">>>>>>>>>>"
        ">>>>>>>>>"
        "]"
    }
    
    //For the case that the input character is line comment
    {
        //go to cell 29
        "<<<"
        //if cell 29 is true
        "["
        "c" //p1706
        
        //set cell 29 to false; set cell 30 to true
        "->+"
        
        //check whether the first input is newline
        {
            {
                //go to input (cell 0)
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "<<<<<<<<<<"
                "c" //p1739
                
                //copy to cell 23
                //n = x - 6 = 23 - 6 = 17
                "[->+>>>[->+>"
                ">>>>>>>>>>>>>>>>>"
                "+"
                "<<<<<<<<<<<<<<<<<"
                "<<]<<<<]>>[->+>>[-<+>>"
                ">>>>>>>>>>>>>>>>>"
                "+"
                "<<<<<<<<<<<<<<<<<"
                "<]<<<]<[->+<]>>[-<<<+>>>]<<<"
                "c" //p1871
            }
            
            {
                //go to cell 26
                ">>>>>>>>>>"
                ">>>>>>>>>>"
                ">>>>>>"
                //set to 10 for newline
                "++++++++++"
                "c" //p1907
            }
            
            {
                //go to is_same (cell 20)
                "<<<<<<"
                //run is_same
                ">+[->>->>>-<<<<>[>+>]<[<]>>>>[>+>]<[<]>>[-<<<[-<<<+>>>]>>>]<<<[-]<<<]>>[>+>]<[<]>[-]>>>[>+>]<[<]>[-]<+<[->-<]>>>>+<[->-<]>[-<<<[-<<<<<+>>>>>]>>>]<<<[-]<<<<<"
                "c" //p2069
                //At cell 20
            }
        }
        
        {
            //At cell 20
            //if compare resuit is true
            "[-"
            
            //go to aux bool cell 30
            ">>>>>>>>>>"
            //set aux bool cell 30 to false
            "-"
            
            //go to aux bool cell 33
            ">>>"
            //set aux bool cell 33 to true
            "+"
            //change to the case that the input character is not line comment
            
            //go to cell 20
            "<<<<<<<<<<"
            "<<<"
            "]"
            "c" //p2100
        }
        
        //go to cell 29
        ">>>>>>>>>"
        "]"
        "c" //p2110
    }
    
    {
        //go to aux cell 30
        ">"
        //if cell 30 is true; set cell 30 to false; set cell 29 to true
        "[-<+>]"
        
        //go to aux cell 33
        ">>>"
        //if cell 33 is true; set cell 33 to false; set cell 32 to true
        "[-<+>]"
    }
    
    //go to input (cell 0)
    "<<<<<<<<<<"
    "<<<<<<<<<<"
    "<<<<<<<<<<"
    "<<<"
    "c" //p2159
    
    //update value by input
    "[->+>>>[-]>>[-]<,[-<+>>+<]<<<<<]>>[->+>>[-]>[-]<<,[->+>+<<]><<<]<[-<+>]>>[-<+>]<<<"
    //go to constant value cell for input (cell 6)
    ">>>>>>"
    //end while loop
    "]"
    "c" //p2248
}
