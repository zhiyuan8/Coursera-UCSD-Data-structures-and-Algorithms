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
    bool flag = true; // if false, it means unable to find bracket
    size_t pos = 0;

    std::stack <Bracket> opening_brackets_stack;
    for (size_t position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') { //
            Bracket Bra={next,((int)position+1)}; // initialization
            opening_brackets_stack.push(Bra);
        }

        if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.size()>0){
                Bracket Bra2 = opening_brackets_stack.top();
                if (Bra2.Matchc(next)) { // find matched string
                    opening_brackets_stack.pop(); // delete matched string
                }
                else{
                    flag = false;
                    pos = position + 1;
                    break;
                }
            } else {
                flag = false;
                pos = position + 1;
                break;
            }
        }
    }

    // Printing answer, write your code here
    if (pos > 0){
        cout << pos;
    }else if (opening_brackets_stack.size() > 0){
        Bracket Bra3 = opening_brackets_stack.top();
        cout << Bra3.position;
    } else {
        cout << "Success";
    }
}
/*
Failed case #15/54: unknown signal 11
Input:
}
Your output:
stderr:
 (Time used: 0.00/1.00, memory used: 10055680/536870912.)
*/
/*
Failed case #26/54: (Wrong answer)
Input:
[](()
Your output:
5
Correct output:
3
*/

