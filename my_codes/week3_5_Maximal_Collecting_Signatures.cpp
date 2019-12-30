// <1> mark the right end point of the interval which locates at the leftmost position
// <2> delete all intervals that contains the mark in <1>
// <3> then again, mark the right end point of the remaining interval which locates at the leftmost position. do this over and over again

// save the data into 2 vectors, a[] for all left end points, b[] for all right end points
#include <iostream>
#include <vector>
using namespace std;

int find_min_index(vector<int> x){
  int index = 0;
  int min_val = 1000000000; // 10^10 will cause int overflow, 10^9 = 1 billion which is OK
  for (int i = 0; i < x.size(); i++) {
    if (x[i]<min_val){
      min_val = x[i];
      index = i;
    }
  }
  return index;
}

//https://stackoverflow.com/questions/20582519/delete-from-specific-indexes-in-a-stdvector
// this function has wide applications, it removes some elements in list A according to B wihch is a list of indices
template<typename T>
void remove_index(std::vector<T>& vector, const std::vector<int>& to_remove)
{
    auto vector_base = vector.begin();
    size_t down_by = 0;

    for (auto iter = to_remove.cbegin();
              iter < to_remove.cend();
              iter++, down_by++) // use iterator, this method is very fancy!!
    {
      // (condition) ? (if_true) : (if_false)
      size_t next = (iter + 1 == to_remove.cend()? vector.size(): *(iter + 1)); // "iter + 1 == to_remove.cend()" means reached the end of to_remove

      //cout << "within remove_index,vector.size()=" << vector.size() << endl;
      //cout << "within remove_index, *iter + 1=" << *iter + 1 << " next=" << next << " *iter - down_by=" << *iter - down_by << endl;

      std::move(vector_base + *iter + 1,
                vector_base + next,
                vector_base + *iter - down_by);// move index range [*iter + 1,next] of vector_base to new position starting at (*iter - down_by)
    } // when to_remove = {0,2}, firstly the indices ranging in [1,2] will be moved to index starting from 1-1=0
    // secondly, the indices ranging in [2,5] will be moved to index starting from 5-2=3
    // when ind_to_delete {0,2}, at 1st iteration, *iter = 0, down_by=1, next=2; at 2nd iteration, *iter=2, down_by=2, next=5;
    vector.resize(vector.size() - to_remove.size()); // resize (size_type n, const value_type& val)
}

int main()
{
  int n,tmp; // n <=10^3
  cin >> n;

  vector<int> mark_result(n);

  int ind; // to get the index of the interval

  vector<int> a(n); // [0,10^9]
  vector<int> b(n); // [0,10^9]
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    a[i] = tmp;
    cin >> tmp;
    b[i] = tmp;
  }

  while (a.size()>0){ // stop when a.size() == 0
    ind = find_min_index(a);
    mark_result.push_back(b[ind]); // marker is right end point with index "ind"
    vector<int> ind_to_delete; // to get the index of the interval to be deleted
    for (int i = 0; i < b.size(); i++) {
      if (a[i] <= b[ind]) && (b[i] >= b[ind]){
        ind_to_delete.push_back(i);
      }
    }
    remove_index(a, ind_to_delete);
    remove_index(b, ind_to_delete);
  }

}
