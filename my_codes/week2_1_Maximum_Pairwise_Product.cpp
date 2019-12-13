#include <iostream>

using namespace std;

/*
int main()
{
    int n;
    int result = 0;
    cin >> n;
    int data[n] = {};
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            if (data[i]*data[j] > result)
                result = data[i]*data[j]; 
        }
    }
    cout << result;

    return 0;
}
*/

// note1: result and input data can be long long length
// note2: However, the long long data type goes beyond time-limit. 2-layer for-loop is REALLY bad

long long Max_Product(long long data[], int n)
{
    long long first = data[0];
    long long second = 0;
    for (int i=1;  i < n; ++i)
    {
        if (data[i] > first){
            second = first; // this line must be in front of next line!!!
            first = data[i];
        }
        else if (data[i] > second){
            second = data[i];
        }
        else
            continue;
    //cout << "loop=" << i << " first=" << first << " second=" << second << endl; // no need to convert numeric to string for cout
    }
    return (first*second);
}

int main()
{
    int n;
    cin >> n;
    long long data[n] = {};
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }
    long long result = Max_Product(data,n);
    cout << result;

    return 0;
}
