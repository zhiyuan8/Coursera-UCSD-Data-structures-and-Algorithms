#include <iostream>
#include <vector>
#include<deque>

using namespace std;

class MonotonicQueue{
public:
    void push_back(int x){ // push_back is wrong????
        if (x <= data.front()){ // in this case, just append x to deque
            data.push_back(x);
        } else { // in this case, clear deque and append x
            data.clear();
            data.push_back(x);
        }
    }
    int top(){
        return data.front(); // also the maximal element
    }
    void pop(){
        data.pop_front();// delete the top element
    }
    deque<int> data;
};


int main() {
    int n = 0;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) // ++i and i++ won't affect loop counts, but "++i" is claimed to avoid copy issue...
        cin >> A.at(i);
    int w = 0;
    cin >> w;

    MonotonicQueue mqueue;
    vector<int> max_result;

    // calculate MonotonicQueue and return top value for each window
    for (int i=0; i<n; ++i){
        mqueue.push_back(A[i]);
        if ( i >= (w-1) ){ // when it comes to at least end of first window
            max_result.push_back(mqueue.top()); // first and also the maximal value of deque
            if (A[i - w + 1] == mqueue.top()){ // the first element of current window happens to be the largest. Note that other portentially largest element are also saved in deque
                mqueue.pop();
            }
        }
    }

    // print out result
    int size_max_result = max_result.size();
    for (int i=0; i<size_max_result;++i){
        cout << max_result[i] << ' ';
    }
    return 0;
}
