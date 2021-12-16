// A. ABC String
// Link - https://codeforces.com/problemset/problem/1494/A



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fora(i,a,b) for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define nline << "\n"
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------------------------*/

bool check(string &s) {
	int count = 0;
	fora(i, 0, s.size()) {
		if (s[i] == '(') count++;
		else count--;

		if (count < 0) return false;
	}

	if (count) return false;
	return true;
}

string solve(string &s, string bracket) {
	string temp;
	fora(i, 0, s.size()) {
		if (s[i] == 'A') {
			if (bracket[0] == '0') temp.pb('(');
			else temp.pb(')');
		} else if (s[i] == 'B') {
			if (bracket[1] == '0') temp.pb('(');
			else temp.pb(')');
		} else {
			if (bracket[2] == '0') temp.pb('(');
			else temp.pb(')');
		}
	}

	return temp;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		string temp1 = solve(s, "001"), temp2 = solve(s, "010"), temp3 = solve(s, "011"), temp4 = solve(s, "100"), temp5 = solve(s, "101"), temp6 = solve(s, "110");

		if (check(temp1) || check(temp2) || check(temp3) || check(temp4) || check(temp5) || check(temp6)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}