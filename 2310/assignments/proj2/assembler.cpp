/*
  Andrew Sanborn And Keith Hammock
  2310 Section 1
  Program 2
  2/15/18

  Description:
*/
#include <string>
#include <iostream>


/*
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
*/



using namespace std;

int main(){

  //create map for commands??

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
