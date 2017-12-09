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
        "["
        "c" //p197
        
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
            ">>>>>>>"
            "c" //p349
            
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
            ">>>>>>>"
            "c" //p432
            
            //do mapping
            ">>[->>+<]<<[<]>>>>[->+++++++++++++++++++++++++++++++++++++++++++<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->++++++++++++++<]<<[->>+<]<<[<]>>>>[->++<]<<[->>+<]<<[<]>>>>[->+++++++++++++++++++++++++++++<]<<[->>+<]<<[<]>>>>[->++<]<<"
            "c" //p711
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
            "c" //p732
        }
        
        {
            //go to is_same (cell 20)
            ">"
            //run is_same
            ">+[->>->>>-<<<<>[>+>]<[<]>>>>[>+>]<[<]>>[-<<<[-<<<+>>>]>>>]<<<[-]<<<]>>[>+>]<[<]>[-]>>>[>+>]<[<]>[-]<+<[->-<]>>>>+<[->-<]>[-<<<[-<<<<<+>>>>>]>>>]<<<[-]<<<<<"
            "c" //p889
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
                    "c" //p906
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
                "c" //p985
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
        "c" //p1057
    }
    
    //go to input (cell 0)
    "<<<<<<<<<<<<<"
    "c" //p1070
    
    //update value by input
    "[->+>>>[-]>>[-]<,[-<+>>+<]<<<<<]>>[->+>>[-]>[-]<<,[->+>+<<]><<<]<[-<+>]>>[-<+>]<<<"
    //go to constant value cell for input (cell 6)
    ">>>>>>"
    //end while loop
    "]"
    "c" //p1159
}
