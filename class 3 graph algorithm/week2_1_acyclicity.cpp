#include <iostream>
#include <vector>

// refer from:
// https://github.com/manparvesh/coursera-ds-algorithms/blob/master/3.%20Algorithms%20on%20Graphs/Programming%20assignment%202/acyclicity/acyclicity.cpp
using namespace std;

vector<bool> visited, rec_stack; // define a global variable, share by all functions

bool acyclicUtil(vector<vector<int> > &adj, int i) {
    if (!visited[i]) {
        // put in recursive stack and mark visited
        visited[i] = true;
        rec_stack[i] = true;
        vector<int>::iterator itr;
        for (itr = adj[i].begin(); itr != adj[i].end(); itr++) {
            if (!visited[*itr]) { // the node has not been explore, explore it, and
                if (acyclicUtil(adj, *itr)) {
                      return true;
                  }
            } else if (rec_stack[*itr]) { // the node has been explore, check if it is in rec_stack
                return true;
            }
        }
    }
    // go to a visited node, pop the node from recursive stack and return false
    rec_stack[i] = false;
    return false;
}

bool acyclic(vector<vector<int> > &adj) {
    visited.resize(adj.size(),false);
    rec_stack.resize(adj.size(),false);

    for (int i = 0; i < adj.size(); i++) {
        if (acyclicUtil(adj, i)) // go through all nodes in adjacent list
          return true;
    }

    return false;
}


int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}

/*
4 4
1 2
4 1
2 3
3 1

return 1
*/

/*
5 7
1 2
2 3
1 3
3 4
1 4
2 5
3 5

return 0
*/
