#include <iostream>

using namespace std;

int knapsack(int v[], int w[], int weight_remain){

}

int main()
{

    int n,W; // W <= 2 * 10^6
    cin >> n >> W;

    double result;
    int v[n];
    int w[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i] >> w[i];
    }
    // sort according to v/w;




    int weight_remain = W;
    int count = 0
    while ((count < n ) && (weight_remain > 0)) { // stop either all items are taken or no space for bag
      int weight_prev = weight_remain; // save the weight before put in new stuff
      weight_remain = knapsack(v, w, weight_remain);
    }


}
