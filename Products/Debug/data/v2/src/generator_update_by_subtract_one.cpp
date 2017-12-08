//generator_update_by_subtract_one
//update generator by subtract 1
//require 7 cells

//cell 0: bool for cell 4 is filled
//cell 1: aux bool for cell 4 is filled
//cell 2: bool for cell 5 is filled
//cell 3: aux bool for cell 5 is filled

//cell 4: value cell
//cell 5: another value cell for copying
//cell 6: constant value cell: bool for loop ;or output

//For the case that cell 4 is filled
{
    //if cell 0 is true;
    "["
    //set cell 0 to false; set aux cell 1 to true
    "->+"
    //go to cell 4
    ">>>"
    
    //update the value
    //subtract 1
    {
        //subtract cell 4 by 1
        "-"
        //go to cell 6
        ">>"
        //subtract cell 6 by 1
        "-"
        
        //go to cell 4
        "<<"
    }
    
    //go to cell 0
    "<<<<"
    "]"
}

//For the case that cell 5 is filled
{
    //if cell 2 is true;
    ">>["
    //set cell 2 to false; set aux cell 3 to true
    "->+"
    //go to cell 5
    ">>"
    
    //update the value
    //subtract 1
    {
        //subtract cell 5 by 1
        "-"
        //go to cell 6
        ">"
        //subtract cell 6 by 1
        "-"
        
        //go to cell 5
        "<"
    }
    
    //go to cell 2
    "<<<"
    "]"
}

{
    //go to aux cell 1
    "<"
    //if cell 1 is true; set cell 1 to false; set cell 0 to true
    "[-<+>]"
    
    //go to aux cell 3
    ">>"
    //if cell 3 is true; set cell 3 to false; set cell 2 to true
    "[-<+>]"
    
    //go to cell 0
    "<<<"
}

//final result:
//At cell 0
