//remove all characters except the 8 special characters
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

//go to constant value cell for input (cell 6)
"<<<<<<<<"

//while(input)
{
    //At cell 6
    //if input is not zero
    "["
    
    //go to counter (cell 7)
    ">"
    //update value by adding 8
    "[->+>>>++++++++>>++++++++<<<<<<]>>[->+>>++++++++>++++++++<<<<]<[-<+>]>>[-<+>]<<<"
    //go to constant value cell for counter (cell 13)
    ">>>>>>"
    
    //for loop
    {
        //At cell 13
        "[" //p197
        
        {
            //go to input (cell 0)
            "<<<<<<<<<<<<<"
            
            //copy to cell 23
            //n = x minus 6 = 23 minus 6 = 17
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
            ">>>>>>>" //p349
            
            //copy to input for mapping (cell 16)
            //n = x minus 13 = 16 minus 13 = 3
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
            ">>>>>>>" //p432
            //do mapping
            ">>[->>+<]<<[<]>>>>[->+++++++++++++++++++++++++++++++++++++++++++<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->++++++++++++++<]<<[->>+<]<<[<]>>>>[->++<]<<[->>+<]<<[<]>>>>[->+++++++++++++++++++++++++++++<]<<[->>+<]<<[<]>>>>[->++<]<<" //p711
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
            "]" //p732
        }
        
        {
            //go to is_same (cell 20)
            ">"
            //run is_same
            ">+[->>->>>-<<<<>[>+>]<[<]>>>>[>+>]<[<]>>[-<<<[-<<<+>>>]>>>]<<<[-]<<<]>>[>+>]<[<]>[-]>>>[>+>]<[<]>[-]<+<[->-<]>>>>+<[->-<]>[-<<<[-<<<<<+>>>>>]>>>]<<<[-]<<<<<" //p889
            //go to compare resuit (cell 20)
            
            {
                //At cell 20
                //if compare resuit is true
                "[-"
                
                {
                    //go to constant value cell for input (cell 6)
                    "<<<<<<<<<<<<<<"
                    //output
                    "." //p906
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
                "]" //p985
            }
        }
        
        //go to counter (cell 7)
        "<<<<<<<<<<<<<"
        //update value by subtract 1
        "[->+>>>->>-<<<<<<]>>[->+>>->-<<<<]<[-<+>]>>[-<+>]<<<"
        
        //go to constant value cell for counter (cell 13)
        ">>>>>>"
        //end for loop
        "]" //p1057
    }
    
    //go to input (cell 0)
    "<<<<<<<<<<<<<" //p1070
    //update value by input
    "[->+>>>[-]>>[-]<,[-<+>>+<]<<<<<]>>[->+>>[-]>[-]<<,[->+>+<<]><<<]<[-<+>]>>[-<+>]<<<"
    //go to constant value cell for input (cell 6)
    ">>>>>>"
    //end while loop
    "]" //p1159
}
