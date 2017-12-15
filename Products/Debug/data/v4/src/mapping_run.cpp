//mapping for the 8 special characters
//Run
//require 42 cells
//cell 0 to 15 : 4 bit input (initialize to null)
//cell 16: bool for input is not zero
//cell 17 to 41 : 7 bit output (initialize to zero)

//At cell 12

//for plus
{
    //At cell 12
    //copy it to cell 15 and 16
    "[->>>+>+<<<<]"
    
    //go to cell 15
    ">>>"
    //copy it to cell 12
    "[-<<<+>>>]"
    
    {
        //go to cell 16
        ">"
        //if it is ture
        "[-"
        
        //n is null, 000
        //e is left end, 001
        //0 is 101
        //1 is 110
        
        //change the output from 0 (nnnnnnne) to 43 (ne101011)
        //go to cell 17
        ">"
        //set each bit
        ">>>" //n to n
        ">>+>" //n to e
        "+>+>>" //n to 1
        "+>>+>" //n to 0
        "+>+>>" //n to 1
        "+>>+>" //n to 0
        "+>+>>" //n to 1
        "+>+>->" //e to 1
        //At cell 41
        
        
        //go to cell 15 (minus 26)
        "<<<<<<<<<<"
        "<<<<<<<<<<"
        "<<<<<<"
        //subtract input by one
        "<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]"
        
        ">"
        //go to cell 16 (minus 25)
        "]"
    }
    
    //go to cell 12
    "<<<<"
    
    //final result for one special character:
    //"[->>>+>+<<<<]>>>[-<<<+>>>]>[->"
    
    //change each bit
    //from 0 (nnnnnnne) to 43 (ne101011)
    //">>>" //n to n
    //">>+>" //n to e
    //"+>+>>" //n to 1
    //"+>>+>" //n to 0
    //"+>+>>" //n to 1
    //"+>>+>" //n to 0
    //"+>+>>" //n to 1
    //"+>+>->" //e to 1
    
    //"<<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<"
}

//for comma
"[->>>+>+<<<<]>>>[-<<<+>>>]>[->"

//change each bit
//from 43 (ne101011) to 44 (ne101100)
">>>"
">>>"
">>>"
">>>"
">>>"
">+>->" //0 to 1
">->+>" //1 to 0
">->+>" //1 to 0

"<<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<"

//for minus
"[->>>+>+<<<<]>>>[-<<<+>>>]>[->"

//change each bit
//from 44 (ne101100) to 45 (ne101101)
">>>"
">>>"
">>>"
">>>"
">>>"
">>>"
">>>"
">+>->" //0 to 1

"<<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<"

//for dot
"[->>>+>+<<<<]>>>[-<<<+>>>]>[->"

//change each bit
//from 45 (ne101101) to 46 (ne101110)
">>>"
">>>"
">>>"
">>>"
">>>"
">>>"
">+>->" //0 to 1
">->+>" //1 to 0

"<<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<"

//for left arrow
"[->>>+>+<<<<]>>>[-<<<+>>>]>[->"

//change each bit
//from 46 (ne101110) to 60 (ne111100)
">>>"
">>>"
">>>"
">+>->" //0 to 1
">>>" //1 to 1
">>>" //1 to 1
">->+>" //1 to 0
">>>" //0 to 0

"<<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<"

//for right arrow
"[->>>+>+<<<<]>>>[-<<<+>>>]>[->"

//change each bit
//from 60 (ne111100) to 62 (ne111110)
">>>"
">>>"
">>>"
">>>"
">>>"
">>>"
">+>->" //0 to 1
">>>" //0 to 0

"<<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<"

//for left square
"[->>>+>+<<<<]>>>[-<<<+>>>]>[->"

//change each bit
//from 62 (ne111110) to 91 (e1011011)
">>+>" //n to e
"+>+>->" //e to 1
">->+>" //1 to 0
">>>" //1 to 1
">>>" //1 to 1
">->+>" //1 to 0
">>>" //1 to 1
">+>->" //0 to 1

"<<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<"

//for right square
"[->>>+>+<<<<]>>>[-<<<+>>>]>[->"

//change each bit
//from 91 (e1011011) to 93 (e1011101)
">>>"
">>>"
">>>"
">>>"
">>>"
">+>->" //0 to 1
">->+>" //1 to 0
">>>" //1 to 1

"<<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<"

////for c
//"[->>>+>+<<<<]>>>[-<<<+>>>]>[->"
//
////change each bit
////from 93 (e1011101) to 99 (e1100011)
//">>>"
//">>>"
//">+>->" //0 to 1
//">->+>" //1 to 0
//">->+>" //1 to 0
//">->+>" //1 to 0
//">+>->" //0 to 1
//">>>" //1 to 1
//
//"<<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<"

//clear input to null
//go to cell 14
">>"
//set it to zero
"-"
//go to cell 12
"<<"

//final result:
//require 42 cells (continuous)
//At cell 12
//cell 0 to 15 is input (destructive)
//cell 17 to 41 is output

//for the 8 special characters
//"[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>+>+>+>>+>>+>+>+>>+>>+>+>+>>+>+>-><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>+>->>->+>>->+><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>>>>>>>+>-><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>>>>+>->>->+><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>+>->>>>>>>>->+>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>>>>+>->>>><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>+>+>+>->>->+>>>>>>>>->+>>>>>+>-><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>+>->>->+>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<>>-<<"

//for the 8 special characters and c
//"[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>+>+>+>>+>>+>+>+>>+>>+>+>+>>+>+>-><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>+>->>->+>>->+><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>>>>>>>+>-><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>>>>+>->>->+><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>+>->>>>>>>>->+>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>>>>+>->>>><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>+>+>+>->>->+>>>>>>>>->+>>>>>+>-><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>>>>>>>>>>+>->>->+>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<[->>>+>+<<<<]>>>[-<<<+>>>]>[->>>>>>>>+>->>->+>>->+>>->+>>+>->>>><<<<<<<<<<<<<<<<<<<<<<<<<<<[<<<]<-<<<<[->>>>+>+<<<<<]+>>>>[-<<<<->>>>]<<<<[->>->-<<<]>>>>>[-<<<<<+>>>>>]+>[>+>->]>]<<<<>>-<<"
