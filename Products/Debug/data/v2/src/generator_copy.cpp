//generator_copy
//copy the value in generator to another cell x (x is 7 in this case)
//n = x minus 6

//require 7 cells
//cell 0: bool for cell 4 is filled
//cell 1: aux bool for cell 4 is filled
//cell 2: bool for cell 5 is filled
//cell 3: aux bool for cell 5 is filled

//cell 4: value cell
//cell 5: another value cell for copying
//cell 6: constant value cell: bool for loop ;or output

//initialize the value in the generator to 3
"+>>>>+++>>+++<<<<<<"

//For the case that cell 4 is filled
{
    //if cell 0 is true; copy cell 4 to cell 5 and cell x = 7
    "["
    //set cell 0 to false; set aux cell 1 to true
    "->+"
    //go to cell 4
    ">>>"
    
    //copy cell 4 to cell 5 and cell x = 7
    {
        //copy cell 4 to cell 5
        "[->+"
        //go to cell 6
        ">"
        //go to cell x = 7; n = 1
        ">"
        //copy cell 4 to cell 7
        "+"
        //go to cell 6; n = 1
        "<"
        //go to cell 4
        "<<"
        "]"
    }
    
    //go to cell 0
    "<<<<"
    "]"
}

//For the case that cell 5 is filled
{
    //if cell 2 is true; copy cell 5 to cell 4 and cell x = 7
    ">>["
    //set cell 2 to false; set aux cell 3 to true
    "->+"
    //go to cell 5
    ">>"
    
    //copy cell 5 to cell 4 and cell x = 7
    {
        //copy cell 5 to cell 4
        "[-<+"
        //go to cell 6
        ">>"
        //go to cell x = 7; n = 1
        ">"
        //copy cell 5 to cell 7
        "+"
        //go to cell 6; n = 1
        "<"
        //go to cell 5
        "<"
        "]"
    }
    
    //go to cell 2
    "<<<"
    "]"
}

{
    //go to aux cell 1
    "<"
    //if cell 1 is true; set cell 1 to false; set cell 2 to true
    "[->+<]"
    
    //go to aux cell 3
    ">>"
    //if cell 3 is true; set cell 3 to false; set cell 0 to true
    "[-<<<+>>>]"
    
    //go to cell 0
    "<<<"
}

//final result:
//At cell 0
//n = 1 for next to the generator (right to the generator)
//n = x minus 6
