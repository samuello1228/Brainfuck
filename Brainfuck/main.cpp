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
#include <algorithm>
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
        
        if(i == 24) cerr<<endl;
        if(i == 49) cerr<<endl;
        if(i == 51) cerr<<endl;
        if(i == 54) cerr<<endl;
        if(i == 57) cerr<<endl;
        if(i == 60) cerr<<endl;
        if(i == 63) cerr<<endl;
        if(i == 66) cerr<<endl;
        if(i == 69) cerr<<endl;
        if(i == 94) cerr<<endl;
        if(i == 96) cerr<<endl;
        if(i == 99) cerr<<endl;
        if(i == 102) cerr<<endl;
        if(i == 105) cerr<<endl;
        if(i == 108) cerr<<endl;
    }
    cout<<endl;
}

void Run(string code,string input,string output)
{
    //input source code
    ifstream src(code.c_str());
    vector<int> binary;
    binary.reserve(5000);
    vector<int> bracket;
    bracket.reserve(5000);
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
    
    //match square bracket
    for(int i=0;i<binary.size();i++)
    {
        bracket.push_back(0);
    }
    for(int i=0;i<binary.size();i++)
    {
        if(binary[i]==91)
        {
            int binPointerTemp = i;
            int count = 0;
            while(true)
            {
                binPointerTemp++;
                if(binPointerTemp == binary.size())
                {
                    cout<<"Error: The corresponding ] cannot be found, for the [ at "<<i<<endl;
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
                        bracket[i] = binPointerTemp;
                        break;
                    }
                    else
                    {
                        count--;
                    }
                }
            }
        }
        else if(binary[i]==93)
        {
            int binPointerTemp = i;
            int count = 0;
            while(true)
            {
                binPointerTemp--;
                if(binPointerTemp == -1)
                {
                    cout<<"Error: The corresponding [ cannot be found, for the ] at "<<i<<endl;
                    return;
                }
                
                if(binary[binPointerTemp]==91)
                {
                    if(count == 0)
                    {
                        if(bracket[binPointerTemp] != i)
                        {
                            cout<<"Error: The corresponding ] is set wrongly, for the [ at "<<binPointerTemp<<endl;
                            return;
                        }
                        else
                        {
                            bracket[i] = binPointerTemp;
                            break;
                        }
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
    
    //performance test
    struct blockInfo
    {
        int rightBracket;
        int numberOfCommand;
        int numberOfExecute;
    };
    vector<blockInfo> BlockData;
    BlockData.reserve(50);
    
    int BlockDataIndex[binary.size()];
    
    //For the top level
    {
        blockInfo element;
        element.rightBracket = -1;
        element.numberOfCommand = 0;
        element.numberOfExecute = 1;
        
        int count = 0;
        for(int i=0;i<binary.size();i++)
        {
            if(binary[i]==91)
            {
                if(count==0)
                {
                    element.numberOfCommand++;
                }
                
                count++;
            }
            else if(binary[i]==93)
            {
                count--;
            }
            else
            {
                if(count==0)
                {
                    element.numberOfCommand++;
                }
            }
        }
        
        BlockData.push_back(element);
    }
    
    //for RightBracket
    for(int i=0;i<binary.size();i++)
    {
        if(binary[i]==93)
        {
            blockInfo element;
            element.rightBracket = i;
            element.numberOfCommand = 1;
            element.numberOfExecute = 0;
            
            BlockDataIndex[i] = int(BlockData.size());
            
            int binPointerTemp = i;
            int count = 0;
            while(true)
            {
                binPointerTemp--;
                
                if(binary[binPointerTemp]==91)
                {
                    if(count == 0)
                    {
                        break;
                    }
                    else
                    {
                        if(count==1)
                        {
                            element.numberOfCommand++;
                        }
                        
                        count--;
                    }
                }
                else if(binary[binPointerTemp]==93)
                {
                    count++;
                }
                else
                {
                    if(count==0)
                    {
                        element.numberOfCommand++;
                    }
                }
            }
            
            BlockData.push_back(element);
        }
    }
    
    {
        int sum = 0;
        for(int i=0;i<BlockData.size();i++)
        {
            cout<<BlockData[i].rightBracket<<" "<<BlockData[i].numberOfCommand<<endl;
            sum += BlockData[i].numberOfCommand;
        }
        cout<<sum<<endl;
    }
    
    
    //Run
    ifstream fin(input.c_str());
    ofstream fout(output.c_str());
    int binPointer = 0;
    bool inputIsEnd = false;
    bool isPrintAll = 0;
    bool isPrintC = 0;
    //isPrintAll = 1;
    isPrintC = 1;
    
    bool isPerformanceTest = true;
    int stepCount = 0;
    
    vector<int> array;
    array.reserve(500);
    array.push_back(0);
    int cellPointer = 0;
    
    cout<<"Info: The program is started."<<endl;
    bool isPrint = isPrintAll || isPrintC;
    if(isPrintAll || (isPrintC && isCout[binPointer]))
    {
        cout<<"    : "<<cellPointer<<" ";
        print(array);
    }
    while(true)
    {
        if(isPerformanceTest) stepCount++;
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
                binPointer = bracket[binPointer]+1;
            }
            else
            {
                binPointer++;
            }
        }
        else if(binary[binPointer]==93)
        {
            //]
            if(isPerformanceTest)
            {
                BlockData[BlockDataIndex[binPointer]].numberOfExecute++;
            }
            
            if(array[cellPointer]==0)
            {
                binPointer++;
            }
            else
            {
                binPointer = bracket[binPointer]+1;
            }
        }
        
        if(isPrint)
        {
            cout<<cellPointer<<" ";
            cout<<endl;
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
    if(isPerformanceTest)
    {
        sort(BlockData.begin(), BlockData.end(), [](blockInfo a, blockInfo b)->bool{return a.numberOfCommand*a.numberOfExecute > b.numberOfCommand*b.numberOfExecute;});
        
        int sum = 0;
        for(int i=0;i<BlockData.size();i++)
        {
            cout<<BlockData[i].rightBracket<<" ";
            cout<<BlockData[i].numberOfCommand<<" ";
            cout<<BlockData[i].numberOfExecute<<" ";
            //cout<<BlockData[i].numberOfExecute/16334.0<<" ";
            cout<<BlockData[i].numberOfCommand * BlockData[i].numberOfExecute <<" ";
            //cout<<BlockData[i].numberOfCommand * BlockData[i].numberOfExecute /16334.0<<" ";
            
            if(BlockData[i].rightBracket != -1)
            {
                for(int j=BlockData[i].rightBracket-10;j<=BlockData[i].rightBracket;j++)
                {
                    cout<<char(binary[j]);
                }
            }
            
            cout<<endl;
            sum += BlockData[i].numberOfCommand * BlockData[i].numberOfExecute;
        }
        cout<<sum<<endl;
        
        cout<<"Number of step: "<<stepCount<<endl;
    }
}

int main()
{
    /*
    ofstream test("data/v3/src/test.cpp");
    
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
    
    //build for v2
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/NOT_gate.cpp","data/v2/bin/NOT_gate.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/AND_gate.cpp","data/v2/bin/AND_gate.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/binary_initialize.cpp","data/v2/bin/binary_initialize.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/binary_add_one.cpp","data/v2/bin/binary_add_one.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/binary_clear.cpp","data/v2/bin/binary_clear.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/binary_copy_half.cpp","data/v2/bin/binary_copy_half.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/binary_is_same_initialize.cpp","data/v2/bin/binary_is_same_initialize.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/binary_is_same_run.cpp","data/v2/bin/binary_is_same_run.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/self_compiler.cpp","data/v2/bin/self_compiler.txt");
    //Run("data/v1/bin/next_compiler.txt","data/v2/src/next_compiler.cpp","data/v2/bin/next_compiler.txt");
    
    //rebuild for v2
    //Run("data/v2/bin/next_compiler.txt","data/v2/src/self_compiler.cpp","data/v2/rbin/self_compiler.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v2/src/next_compiler.cpp","data/v2/rbin/next_compiler.txt");
    
    //build for v3
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/NOT_gate.cpp","data/v3/bin/NOT_gate.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/AND_gate.cpp","data/v3/bin/AND_gate.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/binary_initialize.cpp","data/v3/bin/binary_initialize.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/binary_add_one.cpp","data/v3/bin/binary_add_one.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/binary_subtract_one.cpp","data/v3/bin/binary_subtract_one.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/binary_clear.cpp","data/v3/bin/binary_clear.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/binary_copy_half.cpp","data/v3/bin/binary_copy_half.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/binary_copy_full.cpp","data/v3/bin/binary_copy_full.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/binary_is_same_initialize.cpp","data/v3/bin/binary_is_same_initialize.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/binary_is_same_run.cpp","data/v3/bin/binary_is_same_run.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/binary_move_half.cpp","data/v3/bin/binary_move_half.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/self_compiler.cpp","data/v3/bin/self_compiler.txt");
    //Run("data/v2/bin/next_compiler.txt","data/v3/src/next_compiler.cpp","data/v3/bin/next_compiler.txt");
    
    //build for v4
    //Run("data/v3/bin/next_compiler.txt","data/v4/src/self_compiler.cpp","data/v4/bin/self_compiler.txt");
    Run("data/v3/bin/next_compiler.txt","data/v4/src/next_compiler.cpp","data/v4/bin/next_compiler.txt");
    Run("data/v4/bin/next_compiler.txt","data/v4/src/test.cpp","data/v4/bin/test.txt");
    
    return 0;
}
