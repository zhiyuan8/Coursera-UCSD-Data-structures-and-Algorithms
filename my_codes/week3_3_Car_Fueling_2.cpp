/*
950
400
4
200 375 550 750
*/
/*
10
3
4
1 2 5 9
*/

#include <iostream>
#include <vector>

using namespace std;
int MinRefills(vector<int> x,int N, int L) { // N is # of stops, L is maximal distance after refueling
  int refill_cur, refill_prev, count; // they are index for gas stops
  refill_cur = 0;
  count = 0;
  bool stop_flag = false;
  //cout << "L= " << L << " N= " << N << endl;
  while (refill_cur<=N) { // stop until reach end
    refill_prev = refill_cur;
    //cout << "at while outer loop, x[refill_prev]: " << x[refill_prev] << "  x[refill_cur]: " << x[refill_cur] << " count: " << count << endl;
    while ( (x[refill_cur]-x[refill_prev]) <= L ) {
      refill_cur += 1;
      //cout << "at while inner loop, x[refill_prev]: " << x[refill_prev] << "  x[refill_cur]: " << x[refill_cur] << " refill_cur:" << refill_cur << " count: " << count << endl;
      if (refill_cur == (N+2)) {
        stop_flag = true;
        break;
      }
    }
    refill_cur -=1; // because (x[refill_cur]-x[refill_prev]) > L
    if (stop_flag) {
      return count;
    }
    if (refill_cur == refill_prev) { // cannot find the next stop
      //cout << "within if, x[refill_prev]: " << x[refill_prev] << " x[refill_cur]: " << x[refill_cur] << endl;
      return -1;
    }
    count +=1;
  }
  return count;
}

int main()
{
  int d,m,n,tmp; // [1,10^5]
  cin >> d >> m >> n; // d is total distance, m miles for refueling, n stops
  vector<int> x(n+2); // for stops, x[0]=0, x[1]...x[n], x[n+1]=d
  x[0] = 0;
  x[n+1] = d;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    x[i+1] = tmp;
  } // 0<stop<d

  cout << MinRefills(x, n, m);

}
