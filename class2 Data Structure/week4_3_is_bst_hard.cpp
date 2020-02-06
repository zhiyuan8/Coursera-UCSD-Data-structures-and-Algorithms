#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/* // try this case and look for patterns of 0,1
7
4 1 2
2 3 4
5 5 6
1 -1 -1
3 -1 -1
4 -1 -1
5 -1 -1
// in-roder index [in_order_vec]: 3 -> 1 -> 4 -> 0 -> 5 -> 2 -> 6
// in-order value: 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 5
*/

struct Node {
    int index; // help me better understand where I am
    int key;   // key is the value of node
    int left;
    int right;

    Node() : index(0), key(0), left(-1), right(-1) {}
    Node(int index_, int key_, int left_, int right_) : index(index_), key(key_), left(left_), right(right_) {}
};

vector<Node> tree;

void get_in_order_impl(int index, vector<int> & in_order_vec){ // no need to send tree struct to this inner-function
    if (index == -1){
      return;
    }
    get_in_order_impl(tree[index].left, in_order_vec);// deal with left
    in_order_vec.push_back(tree[index].index); // save index, not key
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

    //for (size_t i = 0; i < in_order_vec.size(); i++) {
    //  cout << i << ' ' << in_order_vec[i]  << endl; // debug
    //}

    // step 2: compare element one by one
    for (int i = 1; i < in_order_vec.size(); i++) {
          if (tree[in_order_vec[i]].key < tree[in_order_vec[i - 1]].key) // compare key
            return false;
          else if ( tree[in_order_vec[i]].key == tree[in_order_vec[i - 1]].key && in_order_vec[i-1] == tree[in_order_vec[i]].left ) // compare key & index when tie for left exists
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
        tree.push_back(Node(i, key, left, right)); // save index also
    }
    if (IsBinarySearchTree(tree)) {
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}
