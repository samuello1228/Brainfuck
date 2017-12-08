//AND gate
//require 3 cells (discrete)
//cell 0 and 1 are input (destructive)
"+>+"
//go to cell 0
"<"

{
    //if cell 0 is true
    "[-"
    //go to cell 1
    ">"
    //copy cell 1 to cell 2
    "[->+<]"
    //go to cell 0
    "<"
    "]"
    
    //clear cell 1
    ">[-]"
    //go to cell 2
    ">"
}

//final result:
//require 3 cells (discrete)
//initial at cell 0
//final at cell 2
//cell 0 and 1 is input (destructive)
//cell 2 is output
