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

int get_sum_of_last_digit_m_n(long long m, long long n){

  int cur = 1;
  int prev = 0;
  if (n==0){
    return 0;
  }
  else { // when n >=2
    long long count = 1;
    int sum_of_last_digit;
    if ((m==0) || (m==1)){
      sum_of_last_digit = 1; // starting from 0+1
    } else {
      sum_of_last_digit = 0; // starting from F_m
    }
    int temp;
    while (count < n){
      // update
      temp = prev;
      prev = cur;
      cur = (cur + temp) % 10;
      count += 1;
      // add last digit
      if (count>=m){
        sum_of_last_digit += cur;
        sum_of_last_digit %= 10;
      }
      // cout << "prev="<< prev << " cur=" << cur << " sum_of_last_digit=" << sum_of_last_digit<<endl; // for debugging
    }
    return sum_of_last_digit;
  }
}

int get_sum_of_last_digit_m_n_FAST(long long m, long long n, int period){
  int whole_loops = int(n / period) -  ( int(m / period) + 1 ); // for example, m=10, n=130, then loops = (130 div 60) - ( (10 div 60) + 1) = 2 -1 = 1, there is 1 whole loop from F10 to F130
  int digit1 = get_sum_of_last_digit_m_n( int(m % period) , period-1 ); // get (F_m + ... + F_period_times_an_constant) % 10
  int digit2 = get_sum_of_last_digit_m_n( 0 , int(n % period) ); // get (F_period_times_an_constant_+_1  + ... + F_n) % 10
  int one_loop_last_digit = get_sum_of_last_digit(period);
  long long sum_up = one_loop_last_digit * whole_loops + digit1 + digit2;
  sum_up %= 10;
  return sum_up;

  // (Fm + ... + Fn) mod 10 = { (F0 + F59)*loops + (F0 + ... + F_remainder) } mod 10

}

int main() {
  long long m, n;
  cin >> m >> n; // m <= n
  int digit;
  int period = 60; // when mod with 10, period = 60, F60 and F0 have the same remainder, F61 and F1 have the same remainder
  if(n <=period)
    digit = get_sum_of_last_digit_m_n(m, n);
  else // n>60
    digit = get_sum_of_last_digit_m_n_FAST(m,n,period);
  //cout << "FAST method: " << digit << endl; // for debugging
  //cout << "SLOW method: " << get_sum_of_last_digit_m_n(m,n) << endl; // for debugging
  cout << digit;

   return 0;
 }

 /*
 Failed case #1/19: (Wrong answer)

 Input:
 1 2

 Your output:
 1
 Correct output:
 2
  (Time used: 0.00/1.00, memory used: 9670656/536870912.)
 */

 /*
 Failed case #15/19: time limit exceeded
 Input:
 1 10000000000

 Your output:

 stderr:

  (Time used: 1.99/1.00, memory used: 9682944/536870912.)
 */

 /*
 Failed case #18/19: (Wrong answer)

 Input:
 12 453

 Your output:
 12
 Correct output:
 2
  (Time used: 0.00/1.00, memory used: 9695232/536870912.)
 */
