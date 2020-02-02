#include <iostream>
// use dynamic programming
// first compare s1[0] with s2[j] and s1[j] with s2[0] to dicide boundary value
// or just use zero for The first row and first column entries have no logical meaning,they are used only for simplicity of program
// C[i][j] = 0 if s1[i] != s2[j]
// C[i][j] = C[i-1][j-1] + 1 if s1[i] == s2[j]
using namespace std;

void solve(int k, const string &s, const string &t) {
	int start_s = 0;
	int start_t = 0; // start of common string A's position i, B's position j, and length
	// I do not use table[i][j], I just use 1 element which is cur_table_val

	int max_common_str_len = 0; // this is save the maximal length of common substring in history
	int row = 0; // right top row
	int col = t.length() - 1; // right top col

	// check diagonal, start from right top element in the 2D table
	while (row < s.length()) { // stop until reach row of left bottom diagonal
		int common_str_len = 0; // initialize the value at beginning of diagonal
		int i = row; // get start value for row
		int j = col; // get start value for col
		while (i<s.length() && j<t.length()) { // stop until reach right bottom of current diagonal path
			if (s[i] == t[j]){
				common_str_len = common_str_len + 1;
				if (max_common_str_len < common_str_len){ // find the temporary max common substring
					start_s = i - (common_str_len-1);
					start_t = j - (common_str_len-1);
					max_common_str_len = common_str_len;
				}
			}
			else {
				common_str_len = 0;
			}
			//cout << "i " << i << " s[i]: " << s[i] << " j: " << j << " t[j]: " << t[j] << " common_str_len: " << common_str_len << endl; // debug
			i ++; // move diagonal
			j ++; // move diagonal
		}
		if (col>0){
			col--; // move 1 col left for starting point
		}
		else{
			row++; // move 1 row down for starting point
		}
		//cout << "finish 1 while loop! row " << row << " col " << col << " s.length() " << s.length() <<  endl;
	}
	cout << start_s << " " << start_t << " " << max_common_str_len << "\n"; // print out result
}

int main() {
	int k;
	string s, t;
	while (cin >> k >> s >> t) {
		solve(k, s, t);
	}
}
