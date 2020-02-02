/* Dynamic Programming solution to find length of the
   longest common substring */
#include<iostream>
#include<string>
using namespace std;

struct Answer {
	int i,j,len;
};

/* Returns length of longest common substring of X[0..m-1]
   and Y[0..n-1] */
Answer LCSubStr(string X, string Y, int m, int n)
{
    // Create a table to store lengths of longest
    // common suffixes of substrings.   Note that
    // LCSuff[i][j] contains length of longest
    // common suffix of X[0..i-1] and Y[0..j-1].

    Answer ans = {0, 0, 0};

    int LCSuff[m+1][n+1];
    int result = 0;  // To store length of the
                     // longest common substring
    int start_X = 0;
    int start_Y = 0;

    /* Following steps build LCSuff[m+1][n+1] in
        bottom up fashion. */
    for (int i=0; i<=m; i++){
        for (int j=0; j<=n; j++){
            // The first row and first column
            // entries have no logical meaning,
            // they are used only for simplicity
            // of program
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i-1] == Y[j-1]){
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
								if ( LCSuff[i][j] > result){
									result = LCSuff[i][j];
									start_X = (i -1) - (result - 1);
									start_Y = (j -1) - (result - 1);
								}
            }
            else LCSuff[i][j] = 0;
        }
    }

    ans = {start_X, start_Y,result};
    return ans;
}

/* Driver program to test above function */
int main()
{
  string s, t;
  while (cin >> s >> t) {
    auto ans = LCSubStr( s, t, (int)s.length(), (int)t.length() );
    cout << ans.i << " " << ans.j << " " << ans.len << "\n";
  }
}
// Failed case #6/12: unknown signal 11 (Time used: 0.00/2.00, memory used: 11538432/536870912.)
