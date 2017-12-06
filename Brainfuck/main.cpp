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
    bool isPrint = 1;
    
    vector<int> array;
    array.reserve(5000);
    array.push_back(0);
    int cellPointer = 0;
    
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
    ofstream bin0("data/bin0.cpp");
    bin0<<",[.,]";
    bin0.close();
    
    ofstream src1("data/src1.cpp");
    src1<<",[.,]";
    src1.close();
    
    ofstream bin0test("data/bin0test.cpp");
    
    if(false)
    {
        //int to bool
        //require 4 cells
        //cell 0: always 0; for synchronizing the pointer after loop
        //cell 1: input cell (not destructive)
        bin0test<<">,";
        //cell 2: bool result
        //cell 3: set 0 for stopping the loop
        
        //go to cell 0
        bin0test<<"<";
        
        {
            //go to cell 1
            bin0test<<">";
            
            {
                //if cell 1 is non-zero
                bin0test<<"[";
                //go to cell 2
                bin0test<<">";
                //set cell 2 to true
                bin0test<<"+";
                //go to cell 3 to stop the loop
                bin0test<<">]";
            }
            
            //if input is zero; go to cell 0
            //if input is not zero; avoid 0 at cell 3; go to cell 2 and its value must be 1
            bin0test<<"<";
            //go to cell 0 by loop; synchronization
            bin0test<<"[<]";
        }
        
        //final result:
        //require 4 cells
        //At cell 0
        //cell 0 and 3 is zero
        //cell 1 is input (not destructive)
        //cell 2 is output
        //bin0test<<">[>+>]<[<]"
    }
    
    if(false)
    {
        //NOT gate
        //require 2 cells
        //cell 0 is input
        bin0test<<"+";
        //go to cell 1
        bin0test<<">";
        
        {
            //set 1 at cell 1
            bin0test<<"+";
            //go to cell 0
            bin0test<<"<";
            //subtract cell 0 by cell 1
            bin0test<<"[->-<]";
            //go to cell 1;
            bin0test<<">";
        }
        
        //final result:
        //require 2 cells
        //At cell 1
        //cell 0 is input (destructive)
        //cell 1 is output
        //bin0test<<"+<[->-<]>";
    }
    
    if(false)
    {
        //if-else
        //require 2 cells
        //cell 0 is input (destructive)
        //cell 1 is aux cell for cell 0
        bin0test<<"+";
        
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
        
        //final result:
        //require 2 cells
        //At cell 0
        //cell 0 is input (destructive)
        //cell 1 is aux cell
        //bin0test<<"+[->+< (if-part) ]+>[-<->]<[- (else-part) ]";
    }
    
    if(false)
    {
        //OR gate
        //require 4 cells
        
        //cell 0 and 2 are input
        //cell 1 is aux cell for cell 0
        bin0test<<">>";
        //go to cell 0
        bin0test<<"<<";
        
        //if cell 0 is true
        bin0test<<"[";
        //copy cell 0 to aux cell 1 and cell 3
        bin0test<<"->+>>+<<<";
        bin0test<<"]";
        
        //cell 0 is NOT GATE of cell 1
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
        
        //final result: [->+>>+<<<]+>[-<->]<[->>[->+<]<<]>>[-]>
    }
    
    if(false)
    {
        //AND gate
        //require 3 cells
        
        //cell 0 and 1 are input
        bin0test<<">";
        //go to cell 0
        bin0test<<"<";
        
        //if cell 0 is true
        bin0test<<"[-";
        //go to cell 1
        bin0test<<">";
        //copy cell 1 to cell 2
        bin0test<<"[->+<]";
        //go to cell 0
        bin0test<<"<";
        bin0test<<"]";
        
        //clear cell 1
        bin0test<<">[-]";
        //go to cell 2
        bin0test<<">";
        
        //final result: [->[->+<]<]>[-]>
    }
    
    if(false)
    {
        //compare same
        //cell 0: bool result
        //cell 1: bool for while loop
        //cell 2;5;8 are 0
        //cell 3;6 are input
        bin0test<<">>>+++++>>>++++++>>";
        
        //go to cell 1
        bin0test<<"<<<<<<<";
        
        //subtraction
        {
            //while loop
            bin0test<<"+[-";
            
            //go to cell 3
            bin0test<<">>";
            //subtract by 1
            bin0test<<"-";
            
            //go to cell 6
            bin0test<<">>>";
            //subtract by 1
            bin0test<<"-";
            
            //go to cell 2
            bin0test<<"<<<<";
            //int to bool for cell 3
            bin0test<<">[>+>]<[<]";
            
            //go to cell 5
            bin0test<<">>>";
            //int to bool for cell 6
            bin0test<<">[>+>]<[<]";
            
            //go to cell 7
            bin0test<<">>";
            //cell 1 is AND gate of cell 4 and 7
            bin0test<<"[-<<<[-<<<+>>>]>>>]<<<[-]<<<";
            //at cell 1
            
            //end while loop
            bin0test<<"]";
        }
        
        //int to bool for cell 3 and 5
        {
            //go to cell 2
            bin0test<<">";
            //int to bool for cell 3
            bin0test<<">[>+>]<[<]";
            //clear cell 3
            bin0test<<">[-]";
            
            //go to cell 5
            bin0test<<">>";
            //int to bool for cell 6
            bin0test<<">[>+>]<[<]";
            //clear cell 6
            bin0test<<">[-]";
        }
        
        //NOT gate
        {
            //go to cell 5
            bin0test<<"<";
            //cell 5 is NOT gate for cell 4
            bin0test<<"+<[->-<]>";
            
            //go to cell 8
            bin0test<<">>>";
            //cell 8 is NOT gate for cell 7
            bin0test<<"+<[->-<]>";
        }
        
        //go to cell 8
        //cell 0 is AND Gate of cell 5 and 8
        bin0test<<"[-<<<[-<<<<<+>>>>>]>>>]<<<[-]<<<<<";
        
        //final result: bin0test<<">+[->>->>>-<<<<>[>+>]<[<]>>>>[>+>]<[<]>>[-<<<[-<<<+>>>]>>>]<<<[-]<<<]>>[>+>]<[<]>[-]>>>[>+>]<[<]>[-]<+<[->-<]>>>>+<[->-<]>[-<<<[-<<<<<+>>>>>]>>>]<<<[-]<<<<<";
    }
    
    if(false)
    {
        //generator
        //require 6 cells
        
        //do it for 2 times
        //bin0test<<">";
        
        //cell 0: bool for cell 4 is filled
        //cell 1: aux bool for cell 4 is filled
        bin0test<<"+";
        //cell 2: bool for cell 5 is filled
        //cell 3: aux bool for cell 5 is filled
        
        //cell 4: input cell
        bin0test<<">>>>,";
        //cell 5: another input cell
        
        //go to cell 0
        bin0test<<"<<<<";
        
        //do it for 2 times
        //bin0test<<"<";
        //bin0test<<"++";
        //bin0test<<"[-";
        //bin0test<<">";
        
        {
            //if cell 0 is true, copy cell 4 to cell 5 and somewhere (cell 6)
            bin0test<<"[";
            //set cell 0 to false, set aux cell 1 to true
            bin0test<<"->+";
            //go to cell 4
            bin0test<<">>>";
            //copy cell 4 to cell 5 and somewhere (cell 6)
            //bin0test<<"[->+>n+<<n]";
            bin0test<<"[->+>+<<]";
            //go to cell 0
            bin0test<<"<<<<";
            bin0test<<"]";
        }
        
        {
            //if cell 2 is true, copy cell 5 to cell 4 and somewhere (cell 6)
            bin0test<<">>[";
            //set cell 2 to false, set aux cell 3 to true
            bin0test<<"->+";
            //go to cell 5
            bin0test<<">>";
            //copy cell 5 to cell 4 and somewhere (cell 6)
            bin0test<<"[-<+>>+<]";
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
        
        //clean somewhere (cell 6)
        bin0test<<">>>>>>[-]<<<<<<";
        
        //do it for 2 times
        //bin0test<<"<]";
        
        //final result: initialize: +>>>>,<<<<
        //final result: apply: [->+>>>[->+>n+<<n]<<<<]>>[->+>>[-<+>>n+<n]<<<]<<>[->+<]>>[-<<<+>>>]<<<
        //n=1 for next to the generator (right to the generator)
    }
    
    if(false)
    {
        //cell 0-5: generator for plus sign
        //initialize generator for plus sign
        bin0test<<"+>>>>+++++++++++++++++++++++++++++++++++++++++++";
        
        //cell 6-8: cell for input character
        //go to cell 7
        bin0test<<">>>";
        //input
        bin0test<<",";
        //copy cell 7 to cell 6 and cell 8
        bin0test<<"[-<+>>+<]";
        
        //go to generator (cell 0)
        bin0test<<"<<<<<<<";
        //apply generator to cell 9; n=4
        //bin0test<<"[->+>>>[->+>>>>+<<<<<]<<<<]>>[->+>>[-<+>>>>>+<<<<]<<<]<<>[->+<]>>[-<<<+>>>]<<<";
        
        //cell 9: bool for matching a character; first bit is special character; second bit is input character
        
        
        bin0test<<"";
    }
    
    bin0test.close();
    
    
    ofstream src1test("data/src1test.cpp");
    src1test<<"*";
    //src1test<<"+";
    //src1test<<"0";
    src1test.close();
    
    //Run("data/bin0.cpp","data/src1.cpp","data/bin1.cpp");
    Run("data/bin0test.cpp","data/src1test.cpp","data/bin1test.cpp");
    return 0;
}
