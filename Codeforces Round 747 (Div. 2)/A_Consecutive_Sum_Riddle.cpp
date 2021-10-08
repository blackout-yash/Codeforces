// A. Consecutive Sum Riddle
// Link - https://codeforces.com/contest/1594/problem/A



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(ll i=a;i<b;i++)

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int last = n - 1;
		if (last) last *= -1;
		cout << last << " " << n << "\n";
	}

	return 0;
}