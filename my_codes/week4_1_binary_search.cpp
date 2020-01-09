#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int binary_search(const vector<int> &a, int l, int r, const int x) {
  if (r < l){ // unable to find key x, return -1
    return (l-1);
  }
  int mid = int( l + (r-l)/2 );
  if (a[mid] == x){
    return mid;
  }
  else if (a[mid] > x){ // should find key at left half interval
    binary_search(a,l,mid-1,x);
  }
  else {
    binary_search(a,mid+1,r,x);
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << linear_search(a, b[i]) << ' ';
  }
}
