#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/*
In topological sorting, we use a temporary stack. We don’t print the vertex immediately,
we first recursively call topological sorting for all its adjacent vertices,
then push it to a stack. Finally, print contents of stack.
Note that a vertex is pushed to stack only when all of its adjacent vertices
(and their adjacent vertices and so on) are already in stack.
*/

void DFSUtil(vector<vector<int> > adj, int index, vector<bool> &visited, stack<int> &Stack) {
  visited[index] = true;
  vector<int>::iterator itr;
  for( itr=adj[index].begin(); itr!=adj[index].end(); itr++ ){
    if (!visited[*itr]){
        DFSUtil(adj, *itr, visited, Stack);
    }
  }
  // Push current vertex to stack which stores result after exploring all its neighbors and unable to go further
  Stack.push(*itr); // v is the 'sink' vertex
}

vector<int> toposort(vector<vector<int> > adj) {
  vector<bool> visited(adj.size(), false); // mark unsivited
  stack<int> Stack; // save the stack and pop it, you get the ordering

  // Call the recursive helper function to store Topological
  for (int i = 0; i < adj.size(); i++)  // Sort starting from all vertices one by one
    if (!visited[i]){
        DFSUtil(adj, i, visited, Stack);
    }

  vector<int> result; // the result
  while(!Stack.empty()){
    result.push_back(Stack.top()); // pass to result
    Stack.pop();
  }
  return result;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
