#include <iostream>
#include <math.h>       /* pow */

using namespace std;

int get_Fibabocci_reminder_only(int n, int m) 
{
    int first_mod_m = 1;
    int second_mod_m = 0;
    int count = 1;
    int temp; // for storage
    if (n == 0) {
        return (0 % m);
    }
    else if (n==1) {
        return (1 % m);
    }
    else {
        while (count < n) { // get period
            count += 1;
            temp = second_mod_m;
            second_mod_m = first_mod_m;
            first_mod_m = (first_mod_m + temp) % m; 
        }
        return  first_mod_m;  
    }
}

int get_Fibabocci_reminder_and_period(unsigned long long n, int m)
{
    int first_mod_m = 1;
    int second_mod_m = 0;
    int count = 1;
    int period = -1; // if it is still -1, that means period is unable to be found out within range [1,m]
    int temp; // for storage
    if (n == 1) {
        return (1 % m);
    }
    else { // when n >=2
        while (count < n) { // get period
            count += 1;
            temp = second_mod_m;
            second_mod_m = first_mod_m;
            first_mod_m = (first_mod_m + temp) % m; 
            //cout << "count=" << count << " first_mod_m=" << first_mod_m << " second_mod_m=" << second_mod_m << endl; // for debugging
            if ( (first_mod_m == 1) && (second_mod_m == 0) ) {
                period = count - 1; // break while loop and return
                //cout << "find period, it is: " << period << endl; // for debugging
                break;
            }
        }
        if (period == -1) // unable to find period, return first_mod_m which is the result
            return first_mod_m;
        else {
            int n2 = n % period;
            int result = get_Fibabocci_reminder_only(n2, m);
            return result;
        }
    }    
}

int main()
{
    unsigned long long n; // n is for Fibanocci array length
    int m;
    cin >> n >> m;
    int result = get_Fibabocci_reminder_and_period(n, m); // use the fact that (fib(0)%m + fib(1)%m )%m will give us the value of fib(2)%m
    //cout << "result=" << result; // for debugging
    cout << result;
    
    return 0;
}
