/*
  Andrew Sanborn And Keith Hammock
  2310 Section 1
  Program 2
  2/15/18

  Description: A compiler for jvm. It creates an executable file of opcodes
  (called executable) for the jvm to run.
*/
#include <string>
#include <iostream>
#include <fstream>
#include <map>

#define DEBUG false

using namespace std;

int main(int argc, char **argv){
  //pass 1
  map<string, int> symbolTable;
  int pc = 0;
  bool error = false;
  ifstream inputFile;
  inputFile.open(argv[1]);
  string command;
  // pass 1: parse input and add labels to symbol table at correct pc
  while(!error && inputFile >> command){
    //read statement & parse input
    if(command.find("comment") == 0)
      //skip rest of line
      getline(inputFile, command);
    else if(command.find("label") == 0){
      string label = command.substr(6,command.length()-7);
      if(symbolTable.count(label) == 0){
        //add the label to the symbol table at the current pc counter
        symbolTable[label] = pc;
      }
      else{
        cout << "error: multiple defined label" << endl;
        error = true;
      }
    }
    else if(!command.substr(0,4).compare("iinc"))
      pc += 3;
    else if(!command.substr(0,6).compare("bipush") ||
            !command.substr(0,6).compare("iload(") ||
            !command.substr(0,7).compare("istore(") ||
            !command.substr(0,4).compare("ifeq") ||
            !command.substr(0,4).compare("ifge") ||
            !command.substr(0,4).compare("ifgt") ||
            !command.substr(0,4).compare("ifle") ||
            !command.substr(0,4).compare("iflt") ||
            !command.substr(0,4).compare("ifne") ||
            !command.substr(0,4).compare("goto") ||
            !command.substr(0,13).compare("invokevirtual")){
      pc += 2;
    }
    //still need to add jsr and ret
    else if(!command.substr(0,7).compare("iconst_") ||
            !command.substr(0,6).compare("iload_") ||
            !command.substr(0,7).compare("istore_") ||
            !command.substr(0,3).compare("pop") ||
            !command.substr(0,4).compare("swap") ||
            !command.substr(0,3).compare("dup") ||
            !command.substr(0,4).compare("iadd") ||
            !command.substr(0,4).compare("isub") ||
            !command.substr(0,4).compare("imul") ||
            !command.substr(0,4).compare("idiv") ||
            !command.substr(0,4).compare("irem") ||
            !command.substr(0,4).compare("ineg") ||
            !command.substr(0,6).compare("return")){
      pc++;
    }
    // if not placed, command unknown - quit loop.
    else{
      cout << "error: unknown opcode mnemonics" << endl;
      error = true;
    }
  }

  #if DEBUG
    // print symbol table while testing
    for(auto it = symbolTable.cbegin(); it != symbolTable.end(); it++){
      cout << it->first << "\t" << it->second << endl;
    }
  #endif

  //reset/create vars before pass 2
  pc = 0;
  inputFile.close();
  inputFile.open(argv[1]);
  ofstream outFile;
  outFile.open("executable");
  //outFile << "write to executable";

  //pass 2: parse commands and print opcodes and addresses to file
  // (do not include pc)
  while(!error && inputFile >> command){
    if(command.find("comment") == 0)
      getline(inputFile, command);
    else if(command.find("label") == 0){
      //do nothing
    }
    else{
      outFile << pc << ":\t";
      if(!command.substr(0,9).compare("iconst_m1")){
        outFile << 2 << endl;
        pc++;
      }
      else if(!command.substr(0,8).compare("iconst_0")){
        outFile << 3 << endl;
        pc++;
      }
      else if(!command.substr(0,8).compare("iconst_1")){
        outFile << 4 << endl;
        pc++;
      }
      else if(!command.substr(0,8).compare("iconst_2")){
        outFile << 5 << endl;
        pc++;
      }
      else if(!command.substr(0,8).compare("iconst_3")){
        outFile << 6 << endl;
        pc++;
      }
      else if(!command.substr(0,8).compare("iconst_4")){
        outFile << 7 << endl;
        pc++;
      }
      else if(!command.substr(0,8).compare("iconst_5")){
        outFile << 8 << endl;
        pc++;
      }
      else if(!command.substr(0,6).compare("bipush")){
        outFile << 16 << "\t" << command.substr(7,command.length()-8) << endl;
        pc += 2;
      }
      else if(!command.substr(0,7).compare("iload_0")){
        outFile << 26 << endl;
        pc++;
      }
      else if(!command.substr(0,7).compare("iload_1")){
        outFile << 27 << endl;
        pc++;
      }
      else if(!command.substr(0,7).compare("iload_2")){
        outFile << 28 << endl;
        pc++;
      }
      else if(!command.substr(0,7).compare("iload_3")){
        outFile << 29 << endl;
        pc++;
      }
      else if(!command.substr(0,6).compare("iload(")){
        outFile << 21 << "\t" << command.substr(6,command.length()-7) << endl;
        pc += 2;
      }
      else if(!command.substr(0,8).compare("istore_0")){
        outFile << 59 << endl;
        pc++;
      }
      else if(!command.substr(0,8).compare("istore_1")){
        outFile << 60 << endl;
        pc++;
      }
      else if(!command.substr(0,8).compare("istore_2")){
        outFile << 61 << endl;
        pc++;
      }
      else if(!command.substr(0,8).compare("istore_3")){
        outFile << 62 << endl;
        pc++;
      }
      else if(!command.substr(0,8).compare("istore_4")){
        outFile << 61 << endl;
        pc++;
      }
      else if(!command.substr(0,7).compare("istore(")){
        outFile << 54 << "\t" << command.substr(7,command.length()-8) << endl;
        pc += 2;
      }
      else if(!command.substr(0,3).compare("pop")){
        outFile << 87 << endl;
        pc++;
      }
      else if(!command.substr(0,4).compare("swap")){
        outFile << 95 << endl;
        pc++;
      }
      else if(!command.substr(0,3).compare("dup")){
        outFile << 89 << endl;
        pc++;
      }
      else if(!command.substr(0,4).compare("iadd")){
        outFile << 96 << endl;
        pc++;
      }
      else if(!command.substr(0,4).compare("isub")){
        outFile << 100 << endl;
        pc++;
      }
      else if(!command.substr(0,4).compare("imul")){
        outFile << 104 << endl;
        pc++;
      }
      else if(!command.substr(0,4).compare("idiv")){
        outFile << 108 << endl;
        pc++;
      }
      else if(!command.substr(0,4).compare("irem")){
        outFile << 112 << endl;
        pc++;
      }
      else if(!command.substr(0,4).compare("ineg")){
        outFile << 116 << endl;
        pc++;
      }
      else if(!command.substr(0,4).compare("iinc")){
        outFile << 132 << "\t" << command.substr(5,command.find(",")-5)
             << "\t" << command.substr(command.find(",")+1,
                           command.length()-command.find(",")-2)  << endl;
        pc+=3;
      }
      else if(!command.substr(0,4).compare("ifeq")){
        string label = command.substr(5,command.length()-6);
        if(symbolTable.count(label) == 1){
          outFile << 153 << "\t";
          pc++;
          outFile << (symbolTable[label]-pc) << endl;
          pc++;
        }
        else{
          error = true;
          cout << "error: undefined label" << endl;
        }
      }
      else if(!command.substr(0,4).compare("ifge")){
        string label = command.substr(5,command.length()-6);
        if(symbolTable.count(label) == 1){
          outFile << 156 << "\t";
          pc++;
          outFile << (symbolTable[command.substr(5,command.length()-6)]-pc) << endl;
          pc++;
        }
        else{
          error = true;
          cout << "error: undefined label" << endl;
        }
      }
      else if(!command.substr(0,4).compare("ifgt")){
        string label = command.substr(5,command.length()-6);
        if(symbolTable.count(label) == 1){
          outFile << 157 << "\t";
          pc++;
          outFile << (symbolTable[command.substr(5,command.length()-6)]-pc) << endl;
          pc++;
        }
        else{
          error = true;
          cout << "error: undefined label" << endl;
        }
      }
      else if(!command.substr(0,4).compare("ifle")){
        string label = command.substr(5,command.length()-6);
        if(symbolTable.count(label) == 1){
          outFile << 158 << "\t";
          pc++;
          outFile << (symbolTable[command.substr(5,command.length()-6)]-pc) << endl;
          pc++;
        }
        else{
          error = true;
          cout << "error: undefined label" << endl;
        }
      }
      else if(!command.substr(0,4).compare("iflt")){
        string label = command.substr(5,command.length()-6);
        if(symbolTable.count(label) == 1){
          outFile << 155 << "\t";
          pc++;
          outFile << (symbolTable[command.substr(5,command.length()-6)]-pc) << endl;
          pc++;
        }
        else{
          error = true;
          cout << "error: undefined label" << endl;
        }
      }
      else if(!command.substr(0,4).compare("ifne")){
        string label = command.substr(5,command.length()-6);
        if(symbolTable.count(label) == 1){
          outFile << 154 << "\t";
          pc++;
          outFile << (symbolTable[command.substr(5,command.length()-6)]-pc) << endl;
          pc++;
        }
        else{
          error = true;
          cout << "error: undefined label" << endl;
        }
      }
      else if(!command.substr(0,4).compare("goto")){
        string label = command.substr(5,command.length()-6);
        if(symbolTable.count(label) == 1){
          outFile << 167 << "\t";
          pc++;
          outFile << (symbolTable[command.substr(5,command.length()-6)]-pc) << endl;
          pc++;
        }
        else{
          error = true;
          cout << "error: undefined label" << endl;
        }
      }
      else if(!command.substr(0,13).compare("invokevirtual")){
        outFile << 182 << "\t" << command.substr(14, command.length()-15) << endl;
        pc+=2;
      }
      else if(!command.substr(0,6).compare("return")){
        outFile << 177 << endl;
        pc++;
      }
      else{
        cout << "error: unknown opcode" << endl;
        error = true;
      }
    }
  }
}
