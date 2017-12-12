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
    vector<bool> isCout;
    isCout.reserve(5000);
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
            isCout.push_back(false);
        }
        else if(srcCellInt==99)
        {
            //c
            isCout[isCout.size() -1] = true;
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
    bool isPrintAll = 0;
    bool isPrintC = 0;
    //isPrintAll = 1;
    isPrintC = 1;
    
    vector<int> array;
    array.reserve(5000);
    array.push_back(0);
    int cellPointer = 0;
    
    cout<<"Info: The program is started."<<endl;
    bool isPrint = isPrintAll || isPrintC;
    if(isPrint)
    {
        cout<<"    : "<<cellPointer<<" ";
        print(array);
    }
    while(true)
    {
        isPrint = isPrintAll || (isPrintC && isCout[binPointer]);
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
    /*
    ofstream test("data/v4/src/test.cpp");
    
    if(false)
    {
        //if-else
        //require 2 cells (discrete)
        //cell 0 is input (destructive)
        //cell 1 is aux cell for cell 0
        test<<"+";
        
        {
            //if cell 0 is true
            test<<"[";
            //set cell 0 to false; set aux cell 1 to true
            test<<"->+<";
            //do if-part
            test<<">>++++++++<<";
            //go to cell 0
            test<<"]";
            
            //cell 0 is NOT GATE of cell 1
            test<<"+>[-<->]<";
            
            //if cell 0 is true
            test<<"[-";
            //go else-part
            test<<">>>++++++++++++++<<<";
            //go to cell 0
            test<<"]";
        }
        
        //final result:
        //require 2 cells
        //At cell 0
        //cell 0 is input (destructive)
        //cell 1 is aux cell
        //"[->+< (if-part) ]+>[-<->]<[- (else-part) ]"
    }
    
    if(false)
    {
        //OR gate
        //require 4 cells (discrete)
        //cell 0 and 2 are input (destructive)
        //cell 1 is aux cell for cell 0
        test<<"+>>+";
        //go to cell 0
        test<<"<<";
        
        {
            //if cell 0 is true
            test<<"[";
            //copy cell 0 to aux cell 1 and cell 3
            test<<"->+>>+<<<";
            test<<"]";
            
            //cell 0 is NOT gate of cell 1
            test<<"+>[-<->]<";
            
            //if cell 0 is true
            test<<"[-";
            //go to cell 2
            test<<">>";
            //copy cell 2 to cell 3
            test<<"[->+<]";
            //go to cell 0
            test<<"<<";
            test<<"]";
            
            //clear cell 2
            test<<">>[-]";
            //go to cell 3
            test<<">";
        }
        
        //final result:
        //require 4 cells (discrete)
        //initial at cell 0
        //final at cell 3
        //cell 0 and 2 are input (destructive)
        //cell 1 is aux cell for cell 0
        //cell 3 is output
        //"[->+>>+<<<]+>[-<->]<[->>[->+<]<<]>>[-]>"
    }

    test<<"]"<<endl;
    test.close();
    */
    
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
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/is_same.cpp","data/v2/bin/is_same.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/mapping_initialize.cpp","data/v2/bin/mapping_initialize.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/mapping_run.cpp","data/v2/bin/mapping_run.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/generator_initialize.cpp","data/v2/bin/generator_initialize.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/generator_update_by_input.cpp","data/v2/bin/generator_update_by_input.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/generator_update_by_subtract_one.cpp","data/v2/bin/generator_update_by_subtract_one.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/generator_copy.cpp","data/v2/bin/generator_copy.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/self_compiler.cpp","data/v2/bin/self_compiler.txt");
    
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/next_compiler.cpp","data/v2/bin/next_compiler.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v2/src/next_compiler.cpp","data/v2/rbin/next_compiler.txt");
    
    //build for v3
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/int_to_bool.cpp","data/v3/bin/int_to_bool.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/NOT_gate.cpp","data/v3/bin/NOT_gate.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/AND_gate.cpp","data/v3/bin/AND_gate.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/is_same.cpp","data/v3/bin/is_same.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/mapping_initialize.cpp","data/v3/bin/mapping_initialize.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/mapping_run.cpp","data/v3/bin/mapping_run.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/generator_initialize.cpp","data/v3/bin/generator_initialize.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/generator_update.cpp","data/v3/bin/generator_update.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/generator_copy.cpp","data/v3/bin/generator_copy.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/self_compiler.cpp","data/v3/bin/self_compiler.txt");
    
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/next_compiler.cpp","data/v3/bin/next_compiler.txt");
    //Run("data/v3/bin/next_compiler.txt","data/v3/src/next_compiler.cpp","data/v3/rbin/next_compiler.txt");
    
    //build for v4
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/self_compiler.cpp","data/v4/bin/self_compiler.txt");
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/binary_initialize.cpp","data/v4/bin/binary_initialize.txt");
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/binary_add_one.cpp","data/v4/bin/binary_add_one.txt");
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/binary_subtract_one.cpp","data/v4/bin/binary_subtract_one.txt");
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/binary_clear.cpp","data/v4/bin/binary_clear.txt");
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/binary_copy_half.cpp","data/v4/bin/binary_copy_half.txt");
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/binary_is_same_initialize.cpp","data/v4/bin/binary_is_same_initialize.txt");
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/binary_is_same_run.cpp","data/v4/bin/binary_is_same_run.txt");
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/.cpp","data/v4/bin/.txt");
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/.cpp","data/v4/bin/.txt");
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/.cpp","data/v4/bin/.txt");
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/.cpp","data/v4/bin/.txt");
    Run("data/v4/bin/self_compiler.txt","data/v4/src/test.cpp","data/v4/bin/test.txt");
    Run("data/v4/bin/test.txt","data/v4/input/test.cpp","data/v4/output/test.txt");
    
    
    return 0;
}
