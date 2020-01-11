#include <iostream>
#include <vector>

using namespace std;
const int INITIAL = 1000000;
/*
N(x) = min { N(x - coin_i)+1, for i from 1 to m } when x > coin_i
*/

int get_change_DP(int m) {
  vector<int> coins = {1,3,4};
  vector<int> N(m+1); // from 0 to m
  N[0]= 0;
  for (size_t i = 1; i <= m; i++) { // start from N[1], end till N[m]
    N[i] = INITIAL;
    for (size_t j = 0; j < coins.size(); j++) {
      if (i >= coins[j]) {
          // cout << "i=" << i << " N[i]=" << N[i] << " N[i-coins[j]]=" <<  N[i-coins[j]] << endl;
          int N_candidate = N[i-coins[j]];
          if ((N_candidate+1)< N[i]) {
            N[i] = N_candidate+1;
           }
        }
     }
  }
  //for (size_t i = 0; i < N.size(); i++) {
  //  cout << "i=" << i << " N[i]=" << N[i] << endl; // print out N
  //}
  return N[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change_DP(m) << '\n';
}
