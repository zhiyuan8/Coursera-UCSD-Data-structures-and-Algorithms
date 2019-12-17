#include <iostream>

using namespace std;

int get_money_remain(int m) {
    if (m % 10 == 0)
        return m - 10;
    else if (m % 5 ==0)
        return m - 5;
    else 
        return m - 1;
}

int main()
{
    
    int m; // m <= 10^3
    cin >> m;

    int money_remain = m;
    int count = 0;

    while (money_remain > 0) {
        money_remain = get_money_remain(money_remain);
        count += 1;
    }

    cout << count;
    return 0;
}