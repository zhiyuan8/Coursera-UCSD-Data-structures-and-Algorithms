#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <limits>

// using an auxiliary stack.

// referred from
// https://www.geeksforgeeks.org/tracking-current-maximum-element-in-a-stack/

using namespace std;
using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element; // this takens O(n) time, should not use it

class StackWithMax {

  public:
    vector<int> stack;
    vector<int> stack_track_max;
    int size = 0;

    void Push(int value) {
        stack.push_back(value);
        if (size == 0){
            stack_track_max.push_back(value);
        } else {
            stack_track_max.push_back(std::max(stack_track_max[size-1],value)); // maximal of current value and the last element of tracking stack
        }
        size += 1;
    }

    void Pop() {
        assert(stack.size());
        stack.pop_back();
        stack_track_max.pop_back();
        size -= 1;
    }

    int Max() const {
        return stack_track_max[size-1]; // return the last element of tracking stack
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
