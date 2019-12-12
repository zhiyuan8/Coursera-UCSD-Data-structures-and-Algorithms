#include <iostream>

using namespace std;

long long get_Fibabocci_num(long long n)
{
    long long first = 1;
    long long second = 0;
    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else{
        long long count = 1;
        while (count < n) {
            count += 1;
            long long first_new = first + second;
            second = first;
            first = first_new;
        }
        return first;
    }
}

int main()
{
    long long n; // n is for Fibanocci array length
    cin >> n;
    long long result = get_Fibabocci_num(n);
    cout << result;

    return 0;
}
