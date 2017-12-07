//mapping for the 8 special characters
//Run
//require 6 cells (continuous)
//cell 0: always 0 for synchronization
//cell 1: always 1 for synchronization
//cell 2: input (destructive)
//cell 3: always 0 for stopping the loop
//cell 4: bool
//cell 5: output

//go to cell 2
>>

//for plus
{
    //if cell 2 is not zero; set cell 4 to true
    [->>+
    //go to cell 3 to stop the loop
    <]
    //synchronization; go to cell 0
    <<[<]
    
    //go to cell 4
    >>>>
    //if cell 4 is true
    [-
    //got to cell 5
    >
    //add 43
    +++++++++++++++++++++++++++++++++++++++++++
    //go to cell 4; end loop
    <]
    //go to cell 2
    <<
}

//for comma
[->>+<]<<[<]>>>>[->
//add 1 = 44
+
<]<<

//for minus
[->>+<]<<[<]>>>>[->
//add 1 = 45
+
<]<<

//for dot
[->>+<]<<[<]>>>>[->
//add 1 = 46
+
<]<<

//for left arrow
[->>+<]<<[<]>>>>[->
//add 14 = 60
++++++++++++++
<]<<

//for right arrow
[->>+<]<<[<]>>>>[->
//add 2 = 62
++
<]<<

//for left square
[->>+<]<<[<]>>>>[->
//add 29 = 91
+++++++++++++++++++++++++++++
<]<<

//for right square
[->>+<]<<[<]>>>>[->
//add 2 = 93
++
<]<<

//final result:
//require 6 cells (continuous)
//initial at cell 0
//final at cell 2
//cell 2 is input (destructive)
//cell 5 is output
