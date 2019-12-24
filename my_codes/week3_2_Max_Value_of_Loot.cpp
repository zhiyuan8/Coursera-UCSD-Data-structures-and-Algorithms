#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int v[], int w[], int weight_remain){

}

struct IdxCompare // remember this struct
{
    const std::vector<float>& target;

    IdxCompare(const std::vector<float>& target): target(target) {} // default constructor

    bool operator()(int a, int b) const { return target[a] >= target[b]; } // in descending order, and comparison should includes =
};

int main()
{

    int n,W; // W <= 2 * 10^6
    long long total_weight = 0; // total weight for all goods
    cin >> n >> W;

    int v[n];
    int w[n];
    std::vector<float> fraction(n); // push_back is slower than initializing a fixed length vector
    std::vector<int> index(n); // this vector saves the index
    double value_in_bag = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i] >> w[i];
        if (w[i] == 0)
        {   // I must consider the case where w=0 firstly, it cannot be nominator, the item will automatically be put into bag at beginning
          fraction[i] = 2 * (v[i]+0.0); // treat w[i]=0 as 0.5, because the next w[i]=1, 0.5<1 still satisfies
        }
        else
        {
          fraction[i] = (v[i]+0.0) / w[i];
        }
        index[i] = i;
        total_weight += w[i];
    }

    // case 0: all items weights <= volumn, then take everything
    if (total_weight<=W)
    {
      for (int i = 0; i < n; ++i)
      {
        value_in_bag += v[i];
      }
      cout << value_in_bag;
    }
    else
    { //  all items weights > volumn
      std::sort(index.begin(), index.end(), IdxCompare(fraction)); // use faction to sort and outputs sorted index. NOTE that faction is not sorted

      int weight_remain = W; // weight_remain will be 0 eventually

      for (int i = 0; i < index.size(); i++) {
        int ind = index[i];
        weight_remain -= w[ind];
        // case 1: bag is full
        if (weight_remain <= 0)
          value_in_bag += v[ind] * ( (weight_remain + w[ind] + 0.0) / w[ind] );
        // case 2: bag is not full
        else
          value_in_bag += v[ind];
      }
      cout << value_in_bag;
    }

}

/*
Failed case #5/13: Wrong answer
got: -60.0266 expected: 0.0
 (Time used: 0.00/1.00, memory used: 9752576/671088640.)
*/
