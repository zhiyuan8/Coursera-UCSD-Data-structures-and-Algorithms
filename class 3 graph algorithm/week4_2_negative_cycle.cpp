#include <iostream>
#include <vector>
#include <limits>
// cannot pass case 5...
using namespace std;
#define INTMAX numeric_limits<int>::max()

vector<int> BellmanFord(vector<vector<int> > &adj, vector<vector<int> > &cost){
  int src = 0; // source node is 0

  // step 1: initialization
  vector<int> dist (adj.size(),INTMAX);
  dist[src] = 0;

  // step 2: update dist
  for (size_t i = 0; i < adj.size(); i++) {
    for (size_t j = 0; j < adj[i].size(); j++) {
      int u = i;
      int v = adj[i][j];
      int w = cost[i][j];
      if (dist[u] != INTMAX){ // avoid int overflow
        if (dist[u] + w < dist[v]){
          dist[v] = dist[u] + w;
        }
      }
    }
  }
  return dist;
}

bool negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  vector<int> dist = BellmanFord(adj , cost);

  // Step 3: check for negative-weight cycles.
  // If we get a shorter path, then there is a cycle.
  for (size_t i = 0; i < adj.size(); i++) {
    for (size_t j = 0; j < adj[i].size(); j++) {
      if (dist[i] != INTMAX){ // avoid int overflow
        if (dist[i] + cost[i][j] < dist[adj[i][j]]){
          return true; // find negative cycle
        }
      }
    }
  }
  return false;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
