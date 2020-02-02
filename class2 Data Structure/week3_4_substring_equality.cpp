#include <iostream>
#include <math.h>       /* pow */
#include<vector>

using namespace std;
typedef long long ll;

# define x 256

template<class T>
T modify(T p1, int p2) { // in case I get negative number after mod, transfer to positive
	if (p1 < 0)
		return p1 + p2;
	return p1;
}

class Solver {
	string s;
	size_t len;
	vector<int> h1; // length = s.length() + 1
	vector<int> h2; // length = s.length() + 1
	const int m1 =pow(10,9) + 7;
	const int m2 =pow(10,9) + 9;

public:
	Solver(string s) : s(s) {
		// initialization, precalculation
		h1.push_back(0);
		h2.push_back(0);
		len = s.length();
		for (size_t i = 0; i < len; i++) {
			h1.push_back( modify( (x*h1[i]+s[i]) % m1 , m1 ) );
			h2.push_back( modify( (x*h2[i]+s[i]) % m2 , m2 ) );
		}
	}
	bool ask(int a, int b, int l) {
		int mod_Ha_m1 =  modify( (ll)(h1[a+l] - pow(x,l) * h1[a]) % m1, m1 ); // H(a,a+l-1) = h1[a+l] - pow(x,l) * h1[a]
		int mod_Hb_m1 =  modify( (ll)(h1[b+l] - pow(x,l) * h1[b]) % m1, m1 ); // (ab) mod p = ( (a mod p) (b mod p) ) mod p
		int mod_Ha_m2 =  modify( (ll)(h1[a+l] - pow(x,l) * h1[a]) % m2, m2 );
		int mod_Hb_m2 =  modify( (ll)(h1[b+l] - pow(x,l) * h1[b]) % m2, m2 );
		if ((mod_Ha_m1 == mod_Hb_m1) && (mod_Ha_m2 == mod_Hb_m2)){
			return true;
		}
		else{
			return false;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
