#include <iostream>
#include <vector>

using namespace std;

void DFSUtil(vector<vector<int> > &adj, int x, const int y, bool &find, vector<bool>& visit){
  visit[x] = true;
  vector<int>::iterator itr;
  for (itr = adj[x].begin(); itr != adj[x].end(); itr++) {
    if (!visit[*itr]) { // not visited
       if (*itr == y){
         find = true;
         return; // abort
       }
        DFSUtil(adj, *itr, y, find, visit);
    }
  }
}

bool reach(const int n, vector<vector<int> > &adj, int x, const int y) {
  //write your code here
  vector<bool> visit(n,false); // vector initialization
  bool find = false;
  DFSUtil(adj,x,y,find,visit);
  return find;
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
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(n, adj, x - 1, y - 1);
}
