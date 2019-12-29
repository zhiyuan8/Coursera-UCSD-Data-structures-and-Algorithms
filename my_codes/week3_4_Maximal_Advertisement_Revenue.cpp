#include <iostream>
#include <vector>
#include <algorithm>
// divide a[i], b[i] into 2 lists respectively, positive and negative. Multiple biggist in absolute value, and the remaining multiple in reverse order

using namespace std;

struct great_order // for sort in descending order
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

void sort_ascending(vector<int> &x){
  if (x.size() >0)
    sort(x.begin(),x.end());
}

void sort_descending(vector<int> &x){
  if (x.size() >0)
    sort(x.begin(),x.end(),great_order());
    // std::sort(numbers.begin(), numbers.end(), std::greater<>()); // from C++14
}

long long multiple_sum(vector<int> a, vector<int> b, int len){
  long long result2 = 0;
  for (int i = 0; i < len; i++) {
    result2 += a[i] * b[i];
  }
  return result2;
}

long long multiple_sum_remained(vector<int> x_pos,vector<int> x_neg, int len_start, int len_end){
  long long result3 = 0;
  for (int i = len_start; i < len_end; i++) {
    result3 += x_pos[i] * x_neg[len_end - (i-len_start+1)];
  }
  return result3;
}

long long Calculate_Revenue(int a[],int b[], int n){
  long long result = 0;
  vector<int> a_pos,a_neg,b_pos,b_neg;
  for (int i = 0; i < n; i++) {
    if (a[i] >=0 ){
      a_pos.push_back(a[i]);
    }
    else{
      a_neg.push_back(a[i]);
    }
    if (b[i] >=0 ){
      b_pos.push_back(b[i]);
    }
    else{
      b_neg.push_back(b[i]);
    }
  } // end for loop
  sort_ascending(a_neg); // then absolute value in descending order
  sort_ascending(b_neg);
  sort_descending(a_pos);
  sort_descending(b_pos);

  result += multiple_sum(a_pos,b_pos,min(a_pos.size(),b_pos.size()));
  result += multiple_sum(a_neg,b_neg,min(a_neg.size(),b_neg.size()));

  // here add the part to extract the part of array that does not participate into the calculation above
  if (a_pos.size()>b_pos.size()){ // multiple remaining of a_pos and b_neg
    result += multiple_sum_remained(a_pos,b_neg,a_neg.size(),a_pos.size());
  }
  else{
    result += multiple_sum_remained(b_pos,a_neg,a_pos.size(),a_neg.size());
  }

  return result;
}

int main()
{
  int n,tmp; // n <=10^3
  int a[n];
  int b[n];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    a[i] = tmp;
  }
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    b[i] = tmp;
  }
  cout << Calculate_Revenue(a,b,n);

}
