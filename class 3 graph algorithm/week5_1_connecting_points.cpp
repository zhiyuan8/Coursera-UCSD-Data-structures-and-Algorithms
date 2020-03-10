#include <algorithm> // sort()
#include <iostream>
#include <unordered_map> // for DisjointSet
#include <iomanip> // setprecision()
#include <vector>
#include <cmath> // sqrt()
#include <utility>  // for pair()
// use: vector<pair<double, pair<int, int> > > edges, then weight can be "index"
using namespace std;

class DisjointSet { //to represent disjoint set
   unordered_map<int, int> parent; // represent of node i
   public:
   DisjointSet(int V) { // Default Constructor
      for (int i=0;i<V;i++){ // create n disjoint sets
      parent[i] = i;
      }
   }
   int Find(int l) { // Find the root of the set in which element l belongs
      if (parent[l] == l) // if l is root
         return l;
      return Find(parent[l]); // recurs for parent till we find root
   }
   void Union(int m, int n) { // perform Union of two subsets m and n
      int x = Find(m);
      int y = Find(n);
      parent[x] = y;
   }
};

void print_edges(vector<pair<double, pair<int, int> > > &edges){
  for (auto edge:edges) {
    double w = edge.first;
    int u = edge.second.first;
    int v = edge.second.second;
    cout << "u: " << u << " v: " << v << " w: " << w << endl;
  }
}

double minimum_distance(vector<pair<double, pair<int, int> > > &edges, size_t V) {
  double result = 0.; // the total weight of mst
  //write your code here
  // step 1: sort edges according to weight
  sort(edges.begin(), edges.end()); // will sort by first of pair
  //cout << "after sorting:" << endl;
  //print_edges(edges);
  // step 2: create DisjointSet
  DisjointSet distjoint(V);
  // step 3: loop from smallest weighted edge
  for (auto edge:edges) {
      int u = edge.second.first;
      int v = edge.second.second;
      //cout << "u " << u << " " << distjoint.Find(u) << " v " << v << " " << distjoint.Find(v)<<endl;
      if (distjoint.Find(u) != distjoint.Find(v)){ // not in same group, no cycle
        //cout << "find " << u << ' ' << v << endl;
        result += edge.first;
        distjoint.Union(u,v); // Union u & v
      }
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  vector<pair<double, pair<int, int> > > edges;

  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i]; // get the x y position of each point
  }
  for (size_t i = 0; i < n; i++) { // get weight of each edge
    for (size_t j = 0; j < n; j++) {
      if (i!=j){
        edges.push_back( { sqrt( pow(x[i]-x[j],2) + pow(y[i]-y[j],2) ) ,
           { i , j } } );
      }
    }
  }
  //print_edges(edges);
  std::cout << std::setprecision(10) << minimum_distance(edges, n) << std::endl;
}
