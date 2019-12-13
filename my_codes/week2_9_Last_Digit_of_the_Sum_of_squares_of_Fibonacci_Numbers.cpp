#include <iostream>

using namespace std;

int get_sum_of_square_of_last_digit(long long n){
  int cur = 1;
  int prev = 0;
  if (n==0){
    return 0;
  }
  else if (n==1) {
    return (0+1);
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
      sum_of_last_digit += cur * cur;
      sum_of_last_digit %= 10;
      // cout << "prev="<< prev << " cur=" << cur << " sum_of_last_digit=" << sum_of_last_digit<<endl; // for debugging
    }
    return sum_of_last_digit;
  }
}

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

int main() {
  long long n;
  cin >> n;
  int digit;
  int period = 60; // when mod with 10, period = 60, F60 and F0 have the same remainder, F61 and F1 have the same remainder
  if(n <=period)
  {
    digit =  get_sum_of_square_of_last_digit(n);
  }
  else // n>60
  {
    int reminder_1, reminder_2;
    reminder_1  = get_Fibabocci_num_last_digit(n%period); // use the fact that F0^2 + ... + Fn^2 = F_n * F_(n+1), secondly, (x*y) mod 10 = [(x mod 10) * (y mod 10)] mod 10
    reminder_2  = get_Fibabocci_num_last_digit((n+1)%period);
    digit = (reminder_1 * reminder_2) % 10;
  }
  //cout << "FAST method: " << digit << endl; // for debugging
  //cout << "SLOW method: " << get_sum_of_square_of_last_digit(n) << endl; // for debugging
  cout << digit;

   return 0;
 }

 /*
 Failed case #18/22: time limit exceeded
 Input:
 832564823476

 Your output:

 stderr:

  (Time used: 1.99/1.00, memory used: 9687040/536870912.)
 */
