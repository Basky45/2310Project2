/*
  Andrew Sanborn And Keith Hammock
  2310 Section 1
  Program 2
  2/15/18

  Description:
*/
#include <string>
#include <iostream>
#include <fstream>
#include <map>


#define ICONST_M1 2             // push -1 onto stack
#define ICONST_0 3              // push 0 onto stack
#define ICONST_1 4              // push 1 onto stack
#define ICONST_2 5              // push 2 onto stack
#define ICONST_3 6              // push 3 onto stack
#define ICONST_4 7              // push 4 onto stack
#define ICONST_5 8              // push 5 onto stack
#define BIPUSH 16               // bipush <value>, push <byte value>

#define ILOAD_0 26              // iload_0 push local variable 0
#define ILOAD_1 27              // iload_1 push local variable 1
#define ILOAD_2 28              // iload_2 push local variable 2
#define ILOAD_3 29              // iload_3 push local variable 3
#define ILOAD 21                // iload <varnum>, push <varnum>

#define ISTORE_0 59             // pop stack to local variable 0
#define ISTORE_1 60             // pop stack to local variable 1
#define ISTORE_2 61             // pop stack to local variable 2
#define ISTORE_3 62             // pop stack to local variable 3
#define ISTORE 54               // istore <varnum>, pop to <varnum>

#define POP 87                  // discard top of stack
#define SWAP 95                 // swap top two items of stack
#define DUP 89                  // duplicate top of stack

#define IADD 96                 // add
#define ISUB 100                // subtract
#define IMUL 104                // mul
#define IDIV 108                // div
#define IREM 112                // remainder
#define INEG 116                // negate
#define IINC 132                // iinc <varnum> <n>, add <n> to <varnum>

#define IFEQ 153                // ifeq <label>, if == 0, goto <label>
#define IFGE 156                // ifge <label>, if >= 0, goto <label>
#define IFGT 157                // ifgt <label>, if >  0, goto <label>
#define IFLE 158                // ifle <label>, if <= 0, goto <label>
#define IFLT 155                // iflt <label>, if <  0, goto <label>
#define IFNE 154                // ifne <label>, if != 0, goto <label>
#define GOTO 167                // goto <label>

#define JSR 168			/* jump to subroutine <label> */
#define RET 169			/* return from subroutine */

#define INVOKEVIRTUAL 182       /* method call specialized to call */
                                /* System.out.println with a local */
                                /* variable as argument */
#define PRINT 1                 /* argument for System.out.print */
#define PRINTLN 2               /* argument for System.out.println */
#define RETURN 177              /* return from method */

#define MEMORY_SIZE 1000
#define STACK_SIZE 10
#define LOCAL_VARIABLE_SIZE 10



using namespace std;

int main(int argc, char **argv){

  map<string,int> opCodeMap;
  map<string, int> symbolTable;
  //create opCodeMap for commands
  opCodeMap["iconst_m1"] = 2;
  opCodeMap["iconst_0"] = 3;
  opCodeMap["iconst_1"] = 4;
  opCodeMap["iconst_2"] = 5;
  opCodeMap["iconst_3"] = 6;
  opCodeMap["iconst_4"] = 7;
  opCodeMap["iconst_5"] = 8;
  opCodeMap["bipush"] = 16;
  opCodeMap["iload_0"] = 26;
  opCodeMap["iload_1"] = 27;
  opCodeMap["iload_2"] = 28;
  opCodeMap["iload_3"] = 29;
  opCodeMap["iload"] = 21;
  opCodeMap["istore_0"] = 59;
  opCodeMap["istore_1"] = 60;
  opCodeMap["istore_2"] = 61;
  opCodeMap["istore_3"] = 62;
  opCodeMap["istore"] = 54;
  opCodeMap["pop"] = 87;
  opCodeMap["swap"] = 95;
  opCodeMap["dup"] = 89;
  opCodeMap["iadd"] = 96;
  opCodeMap["isub"] = 100;
  opCodeMap["imul"] = 104;
  opCodeMap["idiv"] = 108;
  opCodeMap["irem"] = 112;
  opCodeMap["ineg"] = 116;
  opCodeMap["iinc"] = 132;
  opCodeMap["ifeq"] = 153;
  opCodeMap["ifne"] = 154;
  opCodeMap["iflt"] = 155;
  opCodeMap["ifge"] = 156;
  opCodeMap["ifgt"] = 157;
  opCodeMap["ifle"] = 158;
  opCodeMap["goto"] = 167;
  opCodeMap["jsr"] = 168;
  opCodeMap["ret"] = 169;
  opCodeMap["invokevirtual"] = 182;
  opCodeMap["print"] = 1;
  opCodeMap["println"] = 2;
  opCodeMap["return"] = 177;

  //pass 1
  //int location = 0;
  int pc = 0;
  bool done = false;
  bool error = false;
  ifstream inputFile;
  inputFile.open(argv[1]);  // ?????
  string command;
  while(!done && !error && !inputFile.eof()){
    //read statement & parse input
    inputFile >> command;
    if(command.find("comment") == 0)
      //skip rest of line
      getline(inputFile, command);
    else if(command.find("label") == 0){
      //cout << command << endl;
      //int endLoc = command.find(")")-1;
      symbolTable[command.substr(6,command.length()-7)] = pc;
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
    else
      pc++;
  }
  for(auto it = symbolTable.cbegin(); it != symbolTable.end(); it++){
    cout << it->first << "\t" << it->second << endl;
  }
  // switch(opCodeopCodeMap[command]){
  //   case comment:
  //   //do nothing
  //   break;
  //   case LABEL:
  //   //add parameter to symbol table with location
  //   break;
  //   case OTHER:
  //   // multiple for all opcodes
  //   location++; // maybe location += 2;
  //   break;
  //   default:
  //   error = true;
  //   cout << "unknown opcode mnemonics" << endl;
  //}
  //reset input file
}
