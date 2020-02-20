#include <iostream>
#include <vector>
#include <queue> // need a queue
#include <limits>

using namespace std;

void distance( vector<int> &dist, vector<vector<int> > &adj, int s ) {
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;

  vector<int> dist(adj.size(), std::numeric_limits<int>::max()); // step 1: mark all dist to be inf

  distance(dist, adj, s);

  if (dist[t] == std::numeric_limits<int>::max() ){ // cannot found
    cout << -1;
  } else {
    cout << dist[t];
  }

}
