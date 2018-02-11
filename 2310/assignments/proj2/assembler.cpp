/*
  Andrew Sanborn And Keith Hammock
  2310 Section 1
  Program 2
  2/15/18

  Description:
*/
#include <string>
#include <iostream>
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

int main(){



  map<string,int> opCodeMap;
  map<string, int> symbolTable;
  //create map for commands
  map["iconst_m1"] = 2;
  map["iconst_0"] = 3;
  map["iconst_1"] = 4;
  map["iconst_2"] = 5;
  map["iconst_3"] = 6;
  map["iconst_4"] = 7;
  map["iconst_5"] = 8;
  map["bipush"] = 16;
  map["iload_0"] = 26;
  map["iload_1"] = 27;
  map["iload_2"] = 28;
  map["iload_3"] = 29;
  map["iload"] = 21;
  map["istore_0"] = 59;
  map["istore_1"] = 60;
  map["istore_2"] = 61;
  map["istore_3"] = 62;
  map["istore"] = 54;
  map["pop"] = 87;
  map["swap"] = 95;
  map["dup"] = 89;
  map["iadd"] = 96;
  map["isub"] = 100;
  map["imul"] = 104;
  map["idiv"] = 108;
  map["irem"] = 112;
  map["ineg"] = 116;
  map["iinc"] = 132;
  map["ifeq"] = 153;
  map["ifne"] = 154;
  map["iflt"] = 155;
  map["ifge"] = 156;
  map["ifgt"] = 157;
  map["ifle"] = 158;
  map["goto"] = 167;
  map["jsr"] = 168;
  map["ret"] = 169;
  map["invokevirtual"] = 182;
  map["print"] = 1;
  map["println"] = 2;
  map["return"] = 177;
  
  //pass 1
  int location = 0;
  bool done = false;
  bool error = false;
  while(!done && !error){
    //read statement & parse input
    int command;
    switch(command){
      case comment:
        //do nothing
        break;
      case LABEL:
        //add parameter to symbol table with location
        break;
      case OTHER:
        // multiple for all opcodes
        location++; // maybe location += 2;
        break;
      default:
        error = true;
        cout << "unknown opcode mnemonics" << endl;
    }
  }
}
