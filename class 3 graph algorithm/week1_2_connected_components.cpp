#include <iostream>
#include <vector>

using namespace std;

void DFSUtil(vector<vector<int> > &adj, int x, int &cc, vector<bool>& visit){
  visit[x] = true;
  vector<int>::iterator itr;
  for (itr = adj[x].begin(); itr != adj[x].end(); itr++) {
    if (!visit[*itr]) { // not visited
        DFSUtil(adj, *itr, cc, visit);
        cc ++; // after finish exploring connected component starting from x,
    }
  }
}

int compute_cc(const int n, vector<vector<int> > &adj, int x) {
  //write your code here
  vector<bool> visit(n,false); // vector initialization
  int cc = 0;
  DFSUtil(adj,x,cc,visit);
  return cc;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1); // create adjacent list, this is a good method!
    adj[y - 1].push_back(x - 1);
  }
  std::cout << compute_cc(n, adj, 0);
}
