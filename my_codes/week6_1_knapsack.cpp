#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int optimal_weight_knapsack(int W, const vector<int> &w) { // in this problem. weight is value

  vector<vector<int>> value(W+1);

  int n = w.size(); // n is # of items

  for (int i = 0; i <= W; i++) {
    value[i] = vector<int>(n+1);
    value[i][0] = 0; // initialization
  }
  for (int j = 0; j <= n; j++) {
    value[0][j] = 0; // initialization
  }
  /*
  for (int i = 1; i <= W; i++) { // i is the weight capacity
    for (int j = 1; j <= n; j++) { // j is the item index
      if (i>=w[j-1]){ // j starts from 0!
        value[i][j] = std::max(value[i-w[j-1]][j-1]+w[j-1],value[i][j-1]); // when j=1, it means whether to pick item 0 or not
      }
      else{
        value[i][j] = value[i][j-1];
      }
    }
  }
  return value[W+1][n+1];
  */
  return 0;

}

int main() {
  int n, W;
  std::cin >> W >> n; // W is weight capacity
  vector<int> w(n); // n is # of items
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight_knapsack(W, w) << '\n';
}
