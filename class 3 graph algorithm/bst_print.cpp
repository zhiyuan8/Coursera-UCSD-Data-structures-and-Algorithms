#include <iostream>
#include <vector>
#include <queue> // need a queue
#include <limits>
// refer from
// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

using namespace std;

void bst( vector<int> &dist, vector<vector<int> > &adj, int s ) {
  dist[s] = 0;

  // step 2: create queue and enque source node
  queue<int> bst_queue;
  bst_queue.push(s);

  // step 3: create iterator to explore neighbors of source node
  vector<int>::iterator itr;

  // step 4: explore all unvisited neighbors of node
  while (!bst_queue.empty()){ // check if all neighbors are explored
    // deque a node from bst_queue
    s = bst_queue.front();
    bst_queue.pop();

    // explore the neighbors of dequed node
    for( itr=adj[s].begin(); itr !=adj[s].end(); itr++ ){
      if ( dist[*itr] == std::numeric_limits<int>::max() ) { // the node is not visited
           bst_queue.push(*itr);
           dist[*itr] = dist[s] + 1;
      }
    }
  }

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
  int s; // index of soruce node, starting from 1
  cin >> s;

  vector<int> dist(adj.size(), std::numeric_limits<int>::max()); // step 1: mark all dist to be inf
  bst(dist, adj, s);

  // print out dist
  for (int i=0; i<dist.size(); i++){
    cout << "node: " << i << " distance from source: " << dist[i] << endl;
  }

}
