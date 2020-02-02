#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

/*void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap,
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
  }*/

  void heapify(vector<int> &arr, int n, int i) { // n is the number of nodes
    // break out loop if reach leaf
    if (i > int((n-1)/2)) {
      return;
    }
    int left_ind  = 2 * i + 1;
    int right_ind = 2 * i + 2;
    int index_to_change = i;
    // compare with left child
    if (left_ind < n) { // make sure left child exists
      if (arr[i] > arr[left_ind]) {
        index_to_change = left_ind;
      }
    }
    // compare with right child
    if (right_ind < n) { // make sure right child exists
      if (arr[index_to_change] > arr[right_ind]){
        index_to_change = right_ind;
      }
    }
    // If need swap
    if (index_to_change != i) {
      swap(arr[i], arr[index_to_change]);
      swaps_.push_back(make_pair(i, index_to_change));
      heapify(arr, n, index_to_change); // continue to do heapify recursively
    }
    else // If not need swap
      return;
  }

  void GenerateSwaps() {
      swaps_.clear();
      int start_index = int( ( data_.size()-1 ) / 2 );
      for(int i = start_index; i >= 0; --i) {
        heapify(data_, data_.size(), i);
      }
  }


 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
