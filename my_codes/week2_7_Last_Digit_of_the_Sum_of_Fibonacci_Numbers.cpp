#include <iostream>

using namespace std;

int get_sum_of_last_digit(long long n){
  int cur = 1;
  int prev = 0;
  if (n==0){
    return 0;
  }
  else if (n==1) {
    return 0+1;
  }
  else { // when n >=2
    long long count = 1;
    int sum_of_last_digit = 1; // starting from 0+1
    int temp;
    while (count < n) {
      // update
      temp = prev;
      prev = cur;
      cur = (cur + temp) % 10;
      count += 1;
      // add last digit
      sum_of_last_digit += cur;
      sum_of_last_digit %= 10;
      // cout << "prev="<< prev << " cur=" << cur << " sum_of_last_digit=" << sum_of_last_digit<<endl; // for debugging
    }
    return sum_of_last_digit;
  }
}

int get_sum_of_last_digit_FAST(long long n, int period){
  int loops = int(n / period);
  int remainder = n % period;
  // (F0 + ... + Fn) mod 10 = { (F0 + F59)*loops + (F0 + ... + F_remainder) } mod 10
  int one_loop_last_digit = get_sum_of_last_digit(period);
  long long sum_up = one_loop_last_digit * loops + get_sum_of_last_digit(remainder);
  sum_up %= 10;
  return sum_up;
}
/*
Failed case #13/16: time limit exceeded
Input:
832564823476

Your output:

stderr:

 (Time used: 2.00/1.00, memory used: 9682944/536870912.)
*/

/*
mod	          2	3	5	  6	  10	25	30	50	98	125	150	206	243	250	   490	566	   590
Pisano period	3	8	20	24	60	100	120	300	336	500	600	624	648	1500	1680	1704	1740
*/

int main() {
  long long n;
  cin >> n;
  int digit;
  int period = 60; // when mod with 10, period = 60, F60 and F0 have the same remainder, F61 and F1 have the same remainder
  if(n <=period)
    digit = get_sum_of_last_digit(n);
  else // n>60
    digit = get_sum_of_last_digit_FAST(n,period);
  //cout << "FAST method: " << digit << endl; // for debugging
  //cout << "SLOW method: " << get_sum_of_last_digit(n) << endl; // for debugging
  cout << digit;
   return 0;
 }
