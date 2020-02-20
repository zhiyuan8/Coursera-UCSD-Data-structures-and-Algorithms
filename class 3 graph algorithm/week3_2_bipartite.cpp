#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool bipartite(vector<vector<int> > &adj) {
  /* Create a color array to store colors assigned to all veritces. Vertex
  number is used as index in this array. The value '-1' of colorArr[i]
  is used to indicate that no color is assigned to vertex 'i'. The value 1
  is used to indicate first color is assigned and value 0 indicates second color is assigned.
*/

  // step 1: initialization
  int src = 0; // source node is node 0
  vector<char> color(adj.size(), -1); // step 1: color has same function as visit
  color[src] = 1;    // color 1st mode

  // step 2: create queue and enque source node
  queue<int> bst_queue;
  bst_queue.push(src);

  // step 3: create iterator to explore neighbors of source node
  vector<int>::iterator itr;

  // step 4: explore all unvisited neighbors of node
  while (!bst_queue.empty()){ // check if all neighbors are explored
    // deque a node from bst_queue
    src = bst_queue.front();
    bst_queue.pop();

    // explore the neighbors of dequed node
    for( itr=adj[src].begin(); itr !=adj[src].end(); itr++ ){
      if ( color[*itr] == -1 ) { // the node is not visited
           bst_queue.push(*itr);
           color[*itr] = 1 - color[src]; // if color[src] == 0, *itr takes 1, else, takes 0
      }
      else{ // the node is visited, check if there is a color conflict
          if ( color[*itr] + color[src] != 1){ // 1+0 or 0+1
            return false;
          }
      }
    }
  }
  return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
