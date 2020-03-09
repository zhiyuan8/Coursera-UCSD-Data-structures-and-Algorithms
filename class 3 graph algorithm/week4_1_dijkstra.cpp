#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
#define INT_MAX numeric_limits<int>::max()

void print_dist(vector<int> &dist){
  cout << "print_dist";
  for (auto x:dist) {
    cout << x << ' ';
  }
  cout << endl;
}

void print_vector_of_vector(vector<vector<int> > &vec){
  for (size_t i=0; i< vec.size(); i++) {
    cout << "node: " << i << " ";
    for (auto x:vec[i]) {
      cout << x << " ";
    }
    cout << endl;
  }
}

int pick_vertex(vector<vector<int> > &adj, vector<int> &dist, vector<bool> &sptSet){
  // Pick the vertex with minimum distance value and not already included in SPT
  // for min-Heap, it takes O(logV), but vector takes O(V)
  int min_val = INT_MAX;
  int min_index = 0;
  for (int i=0; i<adj.size(); i++){
      if (dist[i] <= min_val && sptSet[i] == false){ // dist[i] <= min_val, otherwise isolated node will never be selected
        min_val = dist[i];
        min_index = i;
        //cout << "In pick_vertex, min_index= " << min_index << endl;
      }
  }
  return min_index;
}

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  // refer from: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
  // adj: adjacent list representation
  // dist[V]: save the dist from node s to all nodes
  // sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

  // step 1: initialization
  int num_V = adj.size();
  vector<int> dist(num_V,INT_MAX);
  vector<bool> sptSet(num_V,false);

  // step 2: set up src node s
  dist[s] = 0;

  // Find shortest path for all vertices
  for (int i = 0; i < num_V; i++){ // loop over all vertices

    // step 3: Pick the vertex with minimum distance value and not already included in SPT, and mark as explored
    int u = pick_vertex(adj, dist, sptSet);
    //cout << "loop: " << i << " pick vertex: " <<u << endl;
    //print_dist(dist); // to debug
    sptSet[u] = true;

    // step 4: Update dist value of the adjacent vertices of the picked vertex.
    for (int j = 0; j < adj[u].size(); j++){ // cannot iterate adj[u], because cost[][] has same index as adj[][]
      // Update dist[v] if <1> v is not in sptSet <2> dist[v] > dist[u] + w[u][v]
      int v = adj[u][j]; // get the neighbor of node u
      //cout << "u " << u << " v " << v << " sptSet[v] " << sptSet[v] << " dist[u] " << dist[u] << " dist[v] " << dist[v] << " cost[u][v] " << cost[u][j] << endl;
      if (sptSet[v] == false && (dist[u] != INT_MAX) ){ // avoid "dist[u] + cost[u][v]" go above INT_MAX
        if (dist[v] > (dist[u] + cost[u][j])) {
              dist[v] = dist[u] + cost[u][j];
        }
      }
    }
    //print_dist(dist); // to debug

    if (sptSet[t]){ // node t is explored, break for loop
      break;
    }
  }

  if (dist[t] == INT_MAX){
      return -1; // cannot found, return -1
  } else {
      return dist[t];
  }
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
  //cout << "print out adj " << endl;
  //print_vector_of_vector(adj);
  //cout << "print out cost " << endl;
  //print_vector_of_vector(cost);
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
