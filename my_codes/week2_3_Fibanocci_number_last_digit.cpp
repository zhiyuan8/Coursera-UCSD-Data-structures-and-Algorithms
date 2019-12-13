#include <iostream>

using namespace std;

int get_Fibabocci_num_last_digit(long long n)
{
    int first = 1;
    int second = 0;
    int first_new;
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
            first_new = (first + second) % 10;
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
    int result = get_Fibabocci_num_last_digit(n);
    cout << result;

    return 0;
}
