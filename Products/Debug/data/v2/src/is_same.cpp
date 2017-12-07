//compare whether two cell are the same
//include int_to_bool
//include NOT_gate
//include AND_gate

//require 9 cells  (continuous)
//cell 0: bool result
//cell 1: bool for while loop
//cell 2 and 5 and 8 are 0
//cell 3 and 6 are input (destructive)
>>>+++++>>>+++++>><<<<<<<<

//subtraction
{
    //go to cell 1
    >
    
    //while loop
    +[-
    
    //go to cell 3
    >>
    //subtract by 1
    -
    
    //go to cell 6
    >>>
    //subtract by 1
    -
    
    //check whether cell 3 and 6 both are not zero
    {
        //go to cell 2
        <<<<
        //int to bool for cell 3
        >[>+>]<[<]
      
        //go to cell 5
        >>>
        //int to bool for cell 6
        >[>+>]<[<]
      
        //go to cell 7
        >>
        //cell 1 is AND gate of cell 4 and 7
        [-<<<[-<<<+>>>]>>>]<<<[-]<<<
        //At cell 1
    }
    
    //end while loop
    ]
}

//int to bool for cell 3 and 5
{
    //go to cell 2
    >
    //int to bool for cell 3
    >[>+>]<[<]
    //clear cell 3
    >[-]
    
    //go to cell 5
    >>
    //int to bool for cell 6
    >[>+>]<[<]
    //clear cell 6
    >[-]
}

//NOT gate
{
    //go to cell 5
    <
    //cell 5 is NOT gate of cell 4
    +<[->-<]>
    
    //go to cell 8
    >>>
    //cell 8 is NOT gate of cell 7
    +<[->-<]>
}

//go to cell 8
//cell 0 is AND Gate of cell 5 and 8
[-<<<[-<<<<<+>>>>>]>>>]<<<[-]<<<<<

//final result:
//require 9 cells (continuous)
//At cell 0
//cell 0: bool result
//cell 1: bool for while loop
//cell 2 and 5 and 8 are 0
//cell 3 and 6 are input (destructive)
