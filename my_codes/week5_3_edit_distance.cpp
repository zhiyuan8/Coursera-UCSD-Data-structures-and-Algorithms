#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int min_of_three(int a, int b, int c) {
  int tmp = numeric_limits<int>::max();
  if (a<tmp)  tmp =a;
  if (b<tmp)  tmp =b;
  if (c<tmp)  tmp =c;
  return tmp;
}

int edit_distance(const string &str1, const string &str2) {
    int row = str1.length();
    int column = str2.length();
    vector<vector<int> > D(row+1); // Create a vector of vector with size equal to row.
    for (int i = 0; i <= row; ++i) {
      D[i] = vector<int>(column+1); // Create the length of each row
    }

    for (int i = 0; i <= row; i++) {
      for (int j = 0; j <= column; j++) {
        if (i==0)
          {D[i][j] = j;} // initialization
        else if (j==0)
          {D[i][j] = i;} // initialization
        else
          {D[i][j] = std::max(row,column);} // initialization
        }
    }

    int insertion, deletion, match, mismatch;
    for(int i = 1; i <= row; ++i) {
      for (int j = 1; j <= column; ++j) {
        insertion = D[i-1][j] + 1;
        deletion  = D[i][j-1] + 1;
        match     = D[i-1][j-1];
        mismatch  = D[i-1][j-1] + 1;
        if (str1[i-1] == str2[j-1]) { // According to scheme at PPT, note that the string has index starting from 0, not 1
          D[i][j] = match;
        }
        else {
          D[i][j] = min_of_three(insertion, deletion, mismatch);
        }
        /*
        if (str1[i-1] == str2[j-1]) { // According to scheme at PPT, note that the string has index starting from 0, not 1
          D[i][j] =min_of_three(insertion, deletion, match);
        }
        else {
          D[i][j] = min_of_three(insertion, deletion, mismatch);
        }
        */
      }
    }
    // print D[i][j] for debugging
    //for (int i = 0; i <= row; i++) {
    //  for (int j = 0; j <= column; j++) {
    //    cout << D[i][j] << ' ';
    //  }
    //  cout << endl;
    //}
    return D[row][column]; // return the final result
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

/*
Input:
short
ports

Your output:
0 1 2 3 4
1 1 2 3 4
2 1 2 3 4
3 2 1 2 3
4 3 2 1 2
2

Correct output:
3
*/
