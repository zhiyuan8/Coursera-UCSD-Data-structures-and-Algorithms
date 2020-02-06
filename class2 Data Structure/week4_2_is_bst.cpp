#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
    int key;
    int left;
    int right;

    Node() : key(0), left(-1), right(-1) {}
    Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

vector<Node> tree;

void get_in_order_impl(int index, vector<int> & in_order_vec){ // no need to send tree struct to this inner-function
    if (index == -1){
      return;
    }
    get_in_order_impl(tree[index].left, in_order_vec);// deal with left
    in_order_vec.push_back(tree[index].key);
    get_in_order_impl(tree[index].right, in_order_vec);//deal with right
}

void get_in_order(std::vector<int>& in_order_vec, const vector<Node>& tree){
    get_in_order_impl(0,in_order_vec);// index, in_order_vec
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  if (tree.size() == 0){
    return true;
  }
  else {
    // step 1: get in_order
    vector <int> in_order_vec;
    get_in_order(in_order_vec,tree);

    // step 2: compare element one by one
    for (int i = 1; i < in_order_vec.size(); i++) {
          if (in_order_vec[i] < in_order_vec[i - 1])
          return false;
    }
    return true;
  }
}

int main() {
    int nodes;
    cin >> nodes;

    for (int i = 0; i < nodes; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }
    if (IsBinarySearchTree(tree)) {
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}
