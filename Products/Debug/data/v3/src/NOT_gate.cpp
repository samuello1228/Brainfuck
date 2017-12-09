//NOT gate
//require 2 cells (discrete)
//cell 0 is input
"+"
//go to cell 1
">"

{
    //set 1 at cell 1
    "+"
    //go to cell 0
    "<"
    //subtract cell 0 by cell 1
    "[->-<]"
    //go to cell 1;
    ">"
}

//final result:
//require 2 cells
//At cell 1
//cell 0 is input (destructive)
//cell 1 is output
//"+<[->-<]>"
