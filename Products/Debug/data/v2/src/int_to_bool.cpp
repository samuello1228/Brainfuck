//int to bool

//require 4 cells (continuous)
//cell 0: always 0; for synchronizing the pointer after loop
//cell 1: input cell (not destructive)
">+++"
//cell 2: bool result
//cell 3: set 0 for stopping the loop

//go to cell 0
"<"

//Run
{
    //go to cell 1
    ">"
    
    {
        //if cell 1 is not zero
        "["
        //go to cell 2
        ">"
        //set cell 2 to true
        "+"
        //go to cell 3 to stop the loop
        ">]"
    }
    
    //if input is zero; go to cell 0
    //if input is not zero; avoid 0 at cell 3; go to cell 2 and its value must be 1
    "<"
    //go to cell 0 by loop; synchronization
    "[<]"
}

//final result:
//require 4 cells
//At cell 0
//cell 0 and 3 is zero
//cell 1 is input (not destructive)
//cell 2 is output
