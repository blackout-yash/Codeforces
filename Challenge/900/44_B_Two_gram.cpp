// B. Two-gram
// Link - https://codeforces.com/problemset/problem/977/B



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

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; string s, temp;
	cin >> n >> s;

	map <string, int> m;
	fora(i, 1, n) {
		temp;
		temp.pb(s[i - 1]); temp.pb(s[i]);
		m[temp]++;
		temp.clear();
	}

	int maximum = 0;
	for (auto x : m) {
		if (maximum < x.second) {
			temp = x.first;
			maximum = x.second;
		}
	} cout << temp;

	return 0;
}