#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using std::vector;

int get_majority_element_sort(vector<int> &a, int left, int right) {
  // the most straight-forward way for me is to sort the array by quick sort O(nlogn), and then go over the array in O(n) time, and check count.
  sort(a.begin(), a.end());
  size_t size = right;
  size_t half_size = int(size/2);

  for (auto x : a){ // use iterator to loop vector a
    std::cout << x << ' ';
  }
  std::cout << endl;

  int count = 1; // because I started counting from the second element after sorting
  for (size_t i = 1; i < size; i++) {
    if (a[i] == a[i-1]){
      count += 1; // add occurrance of existing number to count
    }
    else {
      count = 1; // count occurrance of a number again
    }
    if (count > half_size) {
      return a[i]; // break the function and return the element
    }
  }
  return -1; // return -1 if not found
}

/*
findCandidate(a[], size)
1.  Initialize index and count of majority element
     maj_index = 0, count = 1
2.  Loop for i = 1 to size – 1
    (a) If a[maj_index] == a[i]
          count++
    (b) Else
        count--;
    (c) If count == 0
          maj_index = i;
          count = 1
3.  Return a[maj_index]
*/

int find_candidate(vector<int> &a, int size){ // scan the list for the first time
  size_t major_index = 0;
  int count = 1;
  for (size_t i=1; i<size; i++){
    if (a[i] == a[major_index]) {
      count += 1;
    }
    else{
      count -= 1;
    }
    if (count == 0){ // abondon the part of list that we have scanned, start a new scanning from current position
      major_index = i;
      count = 1;
    }
  }
  return a[major_index];
}

int check_candidate(vector<int> &a, int size, int candidate){ // scan the list for the first time
  int count = 0;
  for (size_t i=0; i<size; i++){
    if (a[i] == candidate) {
      count += 1;
    }
  }
  if (count > int(size/2)){
    return candidate;
  }
  else {
    return -1; // return -1 if candidate is not the majority
  }
}

int get_majority_element_Moore_Voting_Algorithm(vector<int> &a, int size) {
  // Moore’s Voting Algorithm, see https://www.geeksforgeeks.org/majority-element/
  // see https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html for a second explanation
  // see https://blog.csdn.net/kimixuchen/article/details/52787307 for explanation in Chinese
  // The Boyer–Moore majority vote algorithm is an algorithm for finding the majority of a sequence of elements using linear time and constant space.
  int candidate = find_candidate(a, size);
  return check_candidate(a, size, candidate);
}

int get_majority_element_hashmap(vector<int> &a, int size) {
  // time complexity O(n), space O(n).
  // see https://www.geeksforgeeks.org/majority-element/
  unordered_map<int, int> m;
  for (size_t i = 0; i < size; i++) {
     m[a[i]]++;
  }
  int count = 0;
  for(auto i:m) {
      if(i.second > (size / 2) ) {  // for unordered_map, use .first & .second to fetch the element
        return i.first; // i.first = a[major_index]
      }
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  // std::cout << "majority element is: " << get_majority_element_O_sort(a, 0, a.size()) << '\n'; // do not use my first function, it is not divide-and-conquer

  std::cout << (get_majority_element_Moore_Voting_Algorithm(a, a.size()) != -1) << '\n'; // hand in this version

  // std::cout << (get_majority_element_hashmap(a, a.size()) != -1) << '\n';
}
