#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    bool flag = true; // flag == True means it succeed
    int position_global = 0;

    std::stack <Bracket> opening_brackets_stack; // the stack cosists of many "Bracket" structure elements
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket b =  {next,   // char type
                          position + 1 // int position
                          };
            opening_brackets_stack.push(b); // push_back
        }

        if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.size() == 0) {  // firstly evaluate stack size
              flag == false;
              position_global = position + 1;
              break;
            }
            else {
              Bracket bt = opening_brackets_stack.top(); // get first element
              opening_brackets_stack.pop(); // delete first element
              flag  = bt.Matchc(next);
              if (!flag) { // when flag == false
                position_global = position + 1;
                break;
              }
            }
        }
    }
    // At the end of stack, if no error detected before, then finally check if there is any remaining char
    if ( flag && (opening_brackets_stack.size() > 0) ){
      flag = false;
      position_global = text.length();
    }

    // Printing answer, write your code here
    if (flag){
      cout << "Success" ;
    }
    else{
      cout << position_global;
    }

    return 0;
}
