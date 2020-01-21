#include<deque>
#include<iostream>
#include<vector>
using namespace std;

// referred from
// http://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/

class MonotonicQueue {
public:
  void push(int e) {
    while(!data_.empty() && e > data_.back()) data_.pop_back();
    data_.push_back(e);
  }

  void pop() {
    data_.pop_front();
  }

  int max() const { return data_.front(); }
private:
  deque<int> data_;
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  MonotonicQueue q;
  vector<int> ans;

  for (size_t i = 0; i < nums.size(); ++i) {
    q.push(nums[i]);
    if ((int)i - k + 1 >= 0) { // Zhiyuan Li: try not to use size_t for i, because when you compute a negative (i-k+1), unexpected overflow problem occurs
      //cout << "i=" << i << "i-k+1=" << i-k+1 << endl;
      ans.push_back(q.max());
      if (nums[i - k + 1] == q.max()) q.pop();
    }
  }
  //cout << "ans.size() " << ans.size() << endl;
  return ans;
}


int main(){

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums.at(i);

    int k;
    cin >> k;

    vector<int> ans = maxSlidingWindow(nums,k);

    // print output
    for (size_t i=0; i< ans.size(); ++i){
        cout << ans[i] << ' ';
    }
}
