#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    long long c = a % b;
    while (c != 0){
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main()
{
    long long a,b;
    long long result;
    cin >> a >> b;
    if (a>=b)
    {
        result = a * b / gcd(a,b);
    }
    else
    {
        result = a * b / gcd(a,b); // make sure the first arg is bigger than the second
    }
    cout << result;

    return 0;
}
