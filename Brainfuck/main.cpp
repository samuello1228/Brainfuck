//
//  main.cpp
//  Brainfuck
//
//  Created by Samuel Lo on 5/12/2017.
//  Copyright © 2017年 Samuel Lo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void print(vector<int>& array)
{
    for(unsigned int i=0;i<array.size();i++)
    {
        if(array[i]==0)
        {
            cout<<"000 ";
        }
        else if(array[i]<10)
        {
            cout<<"00"<<array[i]<<" ";
        }
        else if(array[i]<100)
        {
            cout<<"0"<<array[i]<<" ";
        }
        else if(array[i]<1000)
        {
            cout<<array[i]<<" ";
        }
    }
    cout<<endl;
}

void Run(string code,string input,string output)
{
    //input source code
    ifstream src(code.c_str());
    vector<int> binary;
    binary.reserve(5000);
    int loopCheck = 0;
    while(true)
    {
        char srcCellChar;
        src.get(srcCellChar);
        
        if(src.eof())
        {
            break;
        }
        
        int srcCellInt = int(srcCellChar);
        //cout<<srcCellChar<<" "<<srcCellInt<<endl;
        if(srcCellInt==43 ||
           srcCellInt==44 ||
           srcCellInt==45 ||
           srcCellInt==46 ||
           srcCellInt==60 ||
           srcCellInt==62 ||
           srcCellInt==91 ||
           srcCellInt==93 )
        {
            if(srcCellInt==91)
            {
                loopCheck++;
            }
            else if(srcCellInt==93 )
            {
                loopCheck--;
            }
            
            if(loopCheck<0)
            {
                cout<<"Error: The binary file has unmatched [."<<endl;
                return;
            }
            
            binary.push_back(srcCellInt);
        }
        else
        {
            cout<<"Error: The binary file contains other character: "<<srcCellInt<<endl;
            return;
        }
    }
    
    if(binary.size()==0)
    {
        cout<<"Error: The binary file is empty."<<endl;
        return;
    }
    
    if(loopCheck!=0)
    {
        cout<<"Error: The binary file has unmatched [ or ]."<<endl;
        return;
    }
    src.close();
    
    //Run
    ifstream fin(input.c_str());
    ofstream fout(output.c_str());
    int binPointer = 0;
    bool inputIsEnd = false;
    bool isPrint = 0;
    
    vector<int> array;
    array.reserve(5000);
    array.push_back(0);
    int cellPointer = 0;
    
    cout<<"Info: The program is started."<<endl;
    if(isPrint)
    {
        cout<<"    : "<<cellPointer<<" ";
        print(array);
    }
    while(true)
    {
        if(isPrint) cout<<binPointer<<" "<<char(binary[binPointer])<<" : ";
        
        if(binary[binPointer]==43)
        {
            //+
            if(array[cellPointer]==255)
            {
                cout<<"Error: The cell "<<cellPointer<<" is overflow."<<endl;
                return;
            }
            else array[cellPointer]++;
            
            binPointer++;
        }
        else if(binary[binPointer]==44)
        {
            //,
            if(inputIsEnd)
            {
                cout<<"Error: The input file is already ended."<<endl;
                return;
            }
            
            char inputChar;
            fin.get(inputChar);
            
            int inputInt;
            if(fin.eof())
            {
                inputIsEnd = true;
                inputInt = 0;
                cout<<"Info: The input file is ended."<<endl;
            }
            else
            {
                inputInt = int(inputChar);
                if(inputInt<=9 || (inputInt>=11 && inputInt<=31) || inputInt>=127)
                {
                    cout<<"Error: The input character "<<inputInt<<" cannot be printable."<<endl;
                    return;
                }
            }
            
            array[cellPointer]=inputInt;
            
            binPointer++;
        }
        else if(binary[binPointer]==45)
        {
            //-
            if(array[cellPointer]==0)
            {
                cout<<"Error: The cell "<<cellPointer<<" is underflow."<<endl;
                return;
            }
            else array[cellPointer]--;
            
            binPointer++;
        }
        else if(binary[binPointer]==46)
        {
            //.
            if(array[cellPointer]<=31 || array[cellPointer]>=127)
            {
                cout<<"Error: The output character "<<array[cellPointer]<<" cannot be printable at cell "<<cellPointer<<endl;
                return;
            }
            else
            {
                fout<<char(array[cellPointer]);
            }
            
            binPointer++;
        }
        else if(binary[binPointer]==60)
        {
            ///<
            if(cellPointer==0)
            {
                cout<<"Error: The cell pointer is already leftmost, cannnot further move left."<<endl;
                return;
            }
            else cellPointer--;
            
            binPointer++;
        }
        else if(binary[binPointer]==62)
        {
            //>
            if(cellPointer == array.size()-1)
            {
                array.push_back(0);
            }
            
            cellPointer++;
            
            binPointer++;
        }
        else if(binary[binPointer]==91)
        {
            //[
            if(array[cellPointer]==0)
            {
                int binPointerTemp = binPointer;
                int count = 0;
                while(true)
                {
                    binPointerTemp++;
                    if(binPointerTemp == binary.size())
                    {
                        cout<<"Error: The corresponding ] cannot be found, for the [ at "<<binPointer<<endl;
                        return;
                    }
                    
                    if(binary[binPointerTemp]==91)
                    {
                        count++;
                    }
                    else if(binary[binPointerTemp]==93)
                    {
                        if(count == 0)
                        {
                            binPointer = binPointerTemp+1;
                            break;
                        }
                        else
                        {
                            count--;
                        }
                    }
                }
            }
            else
            {
                binPointer++;
            }
        }
        else if(binary[binPointer]==93)
        {
            //]
            if(array[cellPointer]==0)
            {
                binPointer++;
            }
            else
            {
                int binPointerTemp = binPointer;
                int count = 0;
                while(true)
                {
                    binPointerTemp--;
                    if(binPointerTemp == -1)
                    {
                        cout<<"Error: The corresponding [ cannot be found, for the ] at "<<binPointer<<endl;
                        return;
                    }
                    
                    if(binary[binPointerTemp]==91)
                    {
                        if(count == 0)
                        {
                            binPointer = binPointerTemp+1;
                            break;
                        }
                        else
                        {
                            count--;
                        }
                    }
                    else if(binary[binPointerTemp]==93)
                    {
                        count++;
                    }
                }
            }
        }
        
        if(isPrint)
        {
            cout<<cellPointer<<" ";
            print(array);
        }
        
        if(binPointer == binary.size())
        {
            cout<<"Info: The program is ended."<<endl;
            break;
        }
    }
    
    fin.close();
    fout.close();
}

int main()
{
    ofstream bin0test("data/bin0test.cpp");
    if(false)
    {
        //int to bool
        bin0test<<">[>+>]<[<]";
    }
    
    if(false)
    {
        //NOT gate
        bin0test<<"+<[->-<]>";
    }
    
    if(false)
    {
        //if-else
        //require 2 cells (discrete)
        //cell 0 is input (destructive)
        //cell 1 is aux cell for cell 0
        bin0test<<"+";
        
        {
            //if cell 0 is true
            bin0test<<"[";
            //set cell 0 to false; set aux cell 1 to true
            bin0test<<"->+<";
            //do if-part
            bin0test<<">>++++++++<<";
            //go to cell 0
            bin0test<<"]";
            
            //cell 0 is NOT GATE of cell 1
            bin0test<<"+>[-<->]<";
            
            //if cell 0 is true
            bin0test<<"[-";
            //go else-part
            bin0test<<">>>++++++++++++++<<<";
            //go to cell 0
            bin0test<<"]";
        }
        
        //final result:
        //require 2 cells
        //At cell 0
        //cell 0 is input (destructive)
        //cell 1 is aux cell
        //bin0test<<"[->+< (if-part) ]+>[-<->]<[- (else-part) ]";
    }
    
    if(false)
    {
        //OR gate
        //require 4 cells (discrete)
        //cell 0 and 2 are input (destructive)
        //cell 1 is aux cell for cell 0
        bin0test<<"+>>+";
        //go to cell 0
        bin0test<<"<<";
        
        {
            //if cell 0 is true
            bin0test<<"[";
            //copy cell 0 to aux cell 1 and cell 3
            bin0test<<"->+>>+<<<";
            bin0test<<"]";
            
            //cell 0 is NOT gate of cell 1
            bin0test<<"+>[-<->]<";
            
            //if cell 0 is true
            bin0test<<"[-";
            //go to cell 2
            bin0test<<">>";
            //copy cell 2 to cell 3
            bin0test<<"[->+<]";
            //go to cell 0
            bin0test<<"<<";
            bin0test<<"]";
            
            //clear cell 2
            bin0test<<">>[-]";
            //go to cell 3
            bin0test<<">";
        }
        
        //final result:
        //require 4 cells (discrete)
        //initial at cell 0
        //final at cell 3
        //cell 0 and 2 are input (destructive)
        //cell 1 is aux cell for cell 0
        //cell 3 is output
        //bin0test<<"[->+>>+<<<]+>[-<->]<[->>[->+<]<<]>>[-]>";
    }
    
    if(false)
    {
        //AND gate
        bin0test<<"[->[->+<]<]>[-]>";
    }
    
    if(false)
    {
        //is_same
        //bin0test<<">+[->>->>>-<<<<>[>+>]<[<]>>>>[>+>]<[<]>>[-<<<[-<<<+>>>]>>>]<<<[-]<<<]>>[>+>]<[<]>[-]>>>[>+>]<[<]>[-]<+<[->-<]>>>>+<[->-<]>[-<<<[-<<<<<+>>>>>]>>>]<<<[-]<<<<<";
    }
    
    if(false)
    {
        //initialize generator
        //bin0test<<"+";
    }
    
    if(false)
    {
        //generator: copy to somewhere (cell 7)
        
        //initialize generator
        bin0test<<"+>>>>>,[-<+>>+<]<<<<<";
        
        {
            //if cell 0 is true; copy cell 4 to cell 5 and somewhere (cell 7)
            bin0test<<"[";
            //set cell 0 to false; set aux cell 1 to true
            bin0test<<"->+";
            //go to cell 4
            bin0test<<">>>";
            //copy cell 4 to cell 5 and somewhere (cell 7)
            //bin0test<<"[->+>>n+<<<n]";
            bin0test<<"[->+>>+<<<]";
            //go to cell 0
            bin0test<<"<<<<";
            bin0test<<"]";
        }
        
        {
            //if cell 2 is true; copy cell 5 to cell 4 and somewhere (cell 7)
            bin0test<<">>[";
            //set cell 2 to false; set aux cell 3 to true
            bin0test<<"->+";
            //go to cell 5
            bin0test<<">>";
            //copy cell 5 to cell 4 and somewhere (cell 7)
            //bin0test<<"[-<+>>>n+<<n]";
            bin0test<<"[-<+>>>+<<]";
            //go to cell 2
            bin0test<<"<<<";
            bin0test<<"]";
            
            //go to cell 0
            bin0test<<"<<";
        }
        
        {
            //go to aux cell 1
            bin0test<<">";
            //if cell 1 is true; set cell 1 to false; set cell 2 to true
            bin0test<<"[->+<]";
            
            //go to aux cell 3
            bin0test<<">>";
            //if cell 3 is true; set cell 3 to false; set cell 0 to true
            bin0test<<"[-<<<+>>>]";
            
            //go to cell 0
            bin0test<<"<<<";
        }
        
        //final result:
        //At cell 0
        /*
        bin0test<<"[->+>>>[->+>";
        bin0test<<">n";
        bin0test<<"+<<";
        bin0test<<"<n";
        bin0test<<"]<<<<]>>[->+>>[-<+>>";
        bin0test<<">n";
        bin0test<<"+<";
        bin0test<<"<n";
        bin0test<<"]<<<]<<>[->+<]>>[-<<<+>>>]<<<";
        */
        //n=1 for next to the generator (right to the generator)
        //n = x minus 6
    }
    
    if(false)
    {
        //generator: update value in generator
        
        //initialize generator
        bin0test<<"+>>>>>,[-<+>>+<]<<<<<";
        
        {
            {
                //if cell 0 is true;
                bin0test<<"[";
                //set cell 0 to false; set aux cell 1 to true
                bin0test<<"->+";
                //go to cell 4
                bin0test<<">>>";
                
                //update the value
                //update by input
                if(false)
                {
                    //clear cell 4
                    bin0test<<"[-]";
                    //go to cell 6
                    bin0test<<">>";
                    //clear cell 6
                    bin0test<<"[-]";
                    
                    //go to cell 5
                    bin0test<<"<";
                    //input
                    bin0test<<",";
                    //copy cell 5 to cell 4 and 6
                    bin0test<<"[-<+>>+<]";
                    
                    //go to cell 4
                    bin0test<<"<";
                }
                
                //subtract 1
                if(false)
                {
                    //subtract cell 4 by 1
                    bin0test<<"-";
                    //go to cell 6
                    bin0test<<">>";
                    //subtract cell 6 by 1
                    bin0test<<"-";
                    
                    //go to cell 4
                    bin0test<<"<<";
                }
                
                //go to cell 0
                bin0test<<"<<<<";
                bin0test<<"]";
            }
            
            {
                //if cell 2 is true;
                bin0test<<">>[";
                //set cell 2 to false; set aux cell 3 to true
                bin0test<<"->+";
                //go to cell 5
                bin0test<<">>";
                
                //update the value
                //update by input
                if(false)
                {
                    //clear cell 5
                    bin0test<<"[-]";
                    //go to cell 6
                    bin0test<<">";
                    //clear cell 6
                    bin0test<<"[-]";
                    
                    //go to cell 4
                    bin0test<<"<<";
                    //input
                    bin0test<<",";
                    //copy cell 4 to cell 5 and 6
                    bin0test<<"[->+>+<<]";
                    
                    //go to cell 5
                    bin0test<<">";
                }
                
                //subtract 1
                if(false)
                {
                    //subtract cell 5 by 1
                    bin0test<<"-";
                    //go to cell 6
                    bin0test<<">";
                    //subtract cell 6 by 1
                    bin0test<<"-";
                    
                    //go to cell 5
                    bin0test<<"<";
                }
                
                //go to cell 2
                bin0test<<"<<<";
                bin0test<<"]";
                
                //go to cell 0
                bin0test<<"<<";
            }
            
            {
                //go to aux cell 1
                bin0test<<">";
                //if cell 1 is true; set cell 1 to false; set cell 0 to true
                bin0test<<"[-<+>]";
                
                //go to aux cell 3
                bin0test<<">>";
                //if cell 3 is true; set cell 3 to false; set cell 2 to true
                bin0test<<"[-<+>]";
                
                //go to cell 0
                bin0test<<"<<<";
            }
        }
        
        //final result:
        //At cell 0
        
        //update by input
        //bin0test<<"[->+>>>[-]>>[-]<,[-<+>>+<]<<<<<]>>[->+>>[-]>[-]<<,[->+>+<<]><<<]<<>[-<+>]>>[-<+>]<<<";
        
        //subtract 1
        //bin0test<<"[->+>>>->>-<<<<<<]>>[->+>>->-<<<<]<<>[-<+>]>>[-<+>]<<<";
    }
    
    //test generator
    if(false)
    {
        //cell 0 is counter
        //do it for 2 times
        bin0test<<"++";
        
        //go to cell 1
        bin0test<<">";
        //cell 1 to 7 is generator
        //initialize generator
        bin0test<<"+>>>>>,[-<+>>+<]<<<<<";
        
        //go to cell 0
        bin0test<<"<";
        //for loop
        bin0test<<"[-";
        //go to cell 1
        bin0test<<">";
        
        //generator: copy value
        if(false)
        {
            //copy to cell 8
            bin0test<<"[->+>>>[->+>";
            bin0test<<">";
            bin0test<<"+<<";
            bin0test<<"<";
            bin0test<<"]<<<<]>>[->+>>[-<+>>";
            bin0test<<">";
            bin0test<<"+<";
            bin0test<<"<";
            bin0test<<"]<<<]<<>[->+<]>>[-<<<+>>>]<<<";

            
            //go to cell 8
            bin0test<<">>>>>>>";
            //clean cell 8
            bin0test<<"[-]";
            //go to cell 1
            bin0test<<"<<<<<<<";
        }
        
        //generator: update value
        if(false)
        {
            //update value from input
            bin0test<<"[->+>>>[-]>>[-]<,[-<+>>+<]<<<<<]>>[->+>>[-]>[-]<<,[->+>+<<]><<<]<<>[-<+>]>>[-<+>]<<<";
        }
        
        //go to cell 0
        bin0test<<"<";
        bin0test<<"]";
    }
    
    if(false)
    {
        //mapping for the 8 special characters
        
        //for plus
        {
            
            //final result for one special character:
            //bin0test<<"[->>+<]<<[<]>>>>[->";
            //bin0test<<"+"; //n times
            //bin0test<<"<]<<";
        }
        
        //Run
        //bin0test<<">>[->>+<]<<[<]>>>>[->+++++++++++++++++++++++++++++++++++++++++++<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->++++++++++++++<]<<[->>+<]<<[<]>>>>[->++<]<<[->>+<]<<[<]>>>>[->+++++++++++++++++++++++++++++<]<<[->>+<]<<[<]>>>>[->++<]<<";
    }
    
    //if(false)
    {
        //remove all characters except the 8 special characters
        //include is_same
        //include mapping_initialize
        //include mapping_run
        //include generator_initialize
        
        //cell 0 to 6: generator for input
        //go to cell 0
        //initialize generator
        bin0test<<"+";
        //update value by input
        bin0test<<"[->+>>>[-]>>[-]<,[-<+>>+<]<<<<<]>>[->+>>[-]>[-]<<,[->+>+<<]><<<]<<>[-<+>]>>[-<+>]<<<";
        
        //cell 7 to 13: generator for counter
        //go to cell 7
        bin0test<<">>>>>>>";
        //initialize generator
        bin0test<<"+";
        
        //cell 14 to 19: mapping for the 8 special characters
        //go to cell 14
        bin0test<<">>>>>>>";
        //initialize mapping
        bin0test<<">+<";
        
        //cell 20 to 28: is_same
        //cell 23: copy for input characters
        //cell 26: copy for special characters
        
        //go to constant value cell for input (cell 6)
        bin0test<<"<<<<<<<<";
        
        //while(input)
        {
            //At cell 6
            //if input is not zero
            bin0test<<"[";
            
            //go to counter (cell 7)
            bin0test<<">";
            //update value by adding 8
            bin0test<<"[->+>>>++++++++>>++++++++<<<<<<]>>[->+>>++++++++>++++++++<<<<]<<>[-<+>]>>[-<+>]<<<";
            //go to constant value cell for counter (cell 13)
            bin0test<<">>>>>>";
            
            //for loop
            {
                //At cell 13
                bin0test<<"["; //p201
                
                {
                    //go to input (cell 0)
                    bin0test<<"<<<<<<<<<<<<<";
                    
                    //copy to cell 23
                    //n = x minus 6 = 23 minus 6 = 17
                    bin0test<<"[->+>>>[->+>";
                    bin0test<<">>>>>>>>>>>>>>>>>";
                    bin0test<<"+<<";
                    bin0test<<"<<<<<<<<<<<<<<<<<";
                    bin0test<<"]<<<<]>>[->+>>[-<+>>";
                    bin0test<<">>>>>>>>>>>>>>>>>";
                    bin0test<<"+<";
                    bin0test<<"<<<<<<<<<<<<<<<<<";
                    bin0test<<"]<<<]<<>[->+<]>>[-<<<+>>>]<<<";
                }
                
                {
                    //go to counter (cell 7)
                    bin0test<<">>>>>>>"; //p355
                    
                    //copy to input for mapping (cell 16)
                    //n = x minus 13 = 16 minus 13 = 3
                    bin0test<<"[->+>>>[->+>";
                    bin0test<<">>>";
                    bin0test<<"+<<";
                    bin0test<<"<<<";
                    bin0test<<"]<<<<]>>[->+>>[-<+>>";
                    bin0test<<">>>";
                    bin0test<<"+<";
                    bin0test<<"<<<";
                    bin0test<<"]<<<]<<>[->+<]>>[-<<<+>>>]<<<";
                }
                
                {
                    //go to mapping (cell 14)
                    bin0test<<">>>>>>>"; //p440
                    //do mapping
                    bin0test<<">>[->>+<]<<[<]>>>>[->+++++++++++++++++++++++++++++++++++++++++++<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->+<]<<[->>+<]<<[<]>>>>[->++++++++++++++<]<<[->>+<]<<[<]>>>>[->++<]<<[->>+<]<<[<]>>>>[->+++++++++++++++++++++++++++++<]<<[->>+<]<<[<]>>>>[->++<]<<"; //p719
                    //At cell 16
                }
                
                {
                    //go to result of mapping (cell 19)
                    bin0test<<">>>";
                    
                    //destructive copy from cell 19 to cell 26
                    bin0test<<"[-";
                    bin0test<<">>>>>>>";
                    bin0test<<"+";
                    bin0test<<"<<<<<<<";
                    bin0test<<"]"; //p740
                }
                
                {
                    //go to is_same (cell 20)
                    bin0test<<">";
                    //run is_same
                    bin0test<<">+[->>->>>-<<<<>[>+>]<[<]>>>>[>+>]<[<]>>[-<<<[-<<<+>>>]>>>]<<<[-]<<<]>>[>+>]<[<]>[-]>>>[>+>]<[<]>[-]<+<[->-<]>>>>+<[->-<]>[-<<<[-<<<<<+>>>>>]>>>]<<<[-]<<<<<"; //p897
                    //go to compare resuit (cell 20)
                    
                    {
                        //At cell 20
                        //if compare resuit is true
                        bin0test<<"[-";
                        
                        {
                            //go to constant value cell for input (cell 6)
                            bin0test<<"<<<<<<<<<<<<<<";
                            //output
                            bin0test<<"."; //p914
                        }
                        
                        //break
                        {
                            //go to counter (cell 7)
                            bin0test<<">";
                            //update value to 1
                            bin0test<<"[->+>>>[-]>>[-]<+[-<+>>+<]<<<<<]>>[->+>>[-]>[-]<<+[->+>+<<]><<<]<<>[-<+>]>>[-<+>]<<<";
                        }
                        
                        //go to cell 20
                        bin0test<<">>>>>>>>>>>>>";
                        bin0test<<"]"; //p1013
                    }
                }
                
                //go to counter (cell 7)
                bin0test<<"<<<<<<<<<<<<<";
                //update value by subtract 1
                bin0test<<"[->+>>>->>-<<<<<<]>>[->+>>->-<<<<]<<>[-<+>]>>[-<+>]<<<";
                
                //go to constant value cell for counter (cell 13)
                bin0test<<">>>>>>";
                //end for loop
                bin0test<<"]"; //p1087
            }
            
            //go to input (cell 0)
            bin0test<<"<<<<<<<<<<<<<"; //p1100
            //update value by input
            bin0test<<"[->+>>>[-]>>[-]<,[-<+>>+<]<<<<<]>>[->+>>[-]>[-]<<,[->+>+<<]><<<]<<>[-<+>]>>[-<+>]<<<";
            //go to constant value cell for input (cell 6)
            bin0test<<">>>>>>";
            //end while loop
            bin0test<<"]"; //p1191
        }
    }
    
    bin0test.close();
    
    
    ofstream src1test("data/src1test.cpp");
    src1test<<"]";
    //src1test<<"+";
    //src1test<<"0";
    src1test.close();
    
    //build for v1
    //Run("data/v0/bin/next_compiler.txt","data/v1/src/self_compiler.cpp","data/v1/bin/self_compiler.txt");
    //Run("data/v0/bin/next_compiler.txt","data/v1/src/next_compiler.cpp","data/v1/bin/next_compiler.txt");
    
    //rebuild for v1
    //Run("data/v1/bin/next_compiler.txt","data/v1/src/next_compiler.cpp","data/v1/rbin/next_compiler.txt");
    
    //build for v2
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/int_to_bool.cpp","data/v2/bin/int_to_bool.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/NOT_gate.cpp","data/v2/bin/NOT_gate.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/AND_gate.cpp","data/v2/bin/AND_gate.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/mapping_initialize.cpp","data/v2/bin/mapping_initialize.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/mapping_run.cpp","data/v2/bin/mapping_run.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/is_same.cpp","data/v2/bin/is_same.txt");
    Run("data/v1/bin/next_compiler.txt","data/v2/src/generator_initialize.cpp","data/v2/bin/generator_initialize.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/.cpp","data/v2/bin/.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/.cpp","data/v2/bin/.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/.cpp","data/v2/bin/.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/.cpp","data/v2/bin/.txt");
    
    //Run("data/bin0test.cpp","data/src1test.cpp","data/bin1test.cpp");
    return 0;
}
