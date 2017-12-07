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
        //bin0test<<">[>+>]<[<]";
    }
    
    if(false)
    {
        //NOT gate
        //bin0test<<"+<[->-<]>";
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
        //bin0test<<"[->[->+<]<]>[-]>";
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
        
        //final result:
        //At cell 0
        /*
        bin0test<<"[->+>>>[->+>";
        bin0test<<">n";
        bin0test<<"+";
        bin0test<<"<n";
        bin0test<<"<<]<<<<]>>[->+>>[-<+>>";
        bin0test<<">n";
        bin0test<<"+";
        bin0test<<"<n";
        bin0test<<"<]<<<]<[->+<]>>[-<<<+>>>]<<<";
        */
        //n=1 for next to the generator (right to the generator)
        //n = x minus 6
    }
    
    if(false)
    {
        //generator: update value in generator
        //update by input
        //bin0test<<"[->+>>>[-]>>[-]<,[-<+>>+<]<<<<<]>>[->+>>[-]>[-]<<,[->+>+<<]><<<]<[-<+>]>>[-<+>]<<<";
        
        //update value to 0
        //bin0test<<"[->+>>>[-]>>[-]<<<<<<]>>[->+>>[-]>[-]<<<<]<[-<+>]>>[-<+>]<<<";
        
        //update value to 1
        //bin0test<<"[->+>>>[-]+>>[-]+<<<<<<]>>[->+>>[-]+>[-]+<<<<]<[-<+>]>>[-<+>]<<<";
        
        //subtract 1
        //bin0test<<"[->+>>>->>-<<<<<<]>>[->+>>->-<<<<]<[-<+>]>>[-<+>]<<<";
        
        //add 8
        //bin0test<<"[->+>>>++++++++>>++++++++<<<<<<]>>[->+>>++++++++>++++++++<<<<]<[-<+>]>>[-<+>]<<<";
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
    
    bin0test.close();
    
    ofstream src1test("data/src1test.cpp");
    src1test<<"]";
    src1test.close();
    
    //build for v1
    //Run("data/v0/bin/next_compiler.txt","data/v1/src/self_compiler.cpp","data/v1/bin/self_compiler.txt");
    //Run("data/v0/bin/next_compiler.txt","data/v1/src/next_compiler.cpp","data/v1/bin/next_compiler.txt");
    
    //rebuild for v1
    //Run("data/v1/bin/next_compiler.txt","data/v1/src/self_compiler.cpp","data/v1/rbin/self_compiler.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v1/src/next_compiler.cpp","data/v1/rbin/next_compiler.txt");
    
    //build for v2
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/int_to_bool.cpp","data/v2/bin/int_to_bool.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/NOT_gate.cpp","data/v2/bin/NOT_gate.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/AND_gate.cpp","data/v2/bin/AND_gate.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/mapping_initialize.cpp","data/v2/bin/mapping_initialize.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/mapping_run.cpp","data/v2/bin/mapping_run.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/is_same.cpp","data/v2/bin/is_same.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/generator_initialize.cpp","data/v2/bin/generator_initialize.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/generator_update_by_input.cpp","data/v2/bin/generator_update_by_input.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/generator_update_by_subtract_one.cpp","data/v2/bin/generator_update_by_subtract_one.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/generator_copy.cpp","data/v2/bin/generator_copy.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/self_compiler.cpp","data/v2/bin/self_compiler.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/.cpp","data/v2/bin/.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/.cpp","data/v2/bin/.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/.cpp","data/v2/bin/.txt");
    
    //Run("data/bin0test.cpp","data/src1test.cpp","data/bin1test.cpp");
    return 0;
}
