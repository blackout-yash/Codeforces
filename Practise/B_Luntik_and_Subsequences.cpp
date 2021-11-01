// B. Luntik and Subsequences
// Link - https://codeforces.com/contest/1582/problem/B



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int power(int a, int b) {
	if (b == 0) return 1;
	long long res = pow(a, b / 2);
	if (b % 2) return res * res * a;
	return res * res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n;

		int one = 0, zero = 0;
		fora(i, 0, n) {
			cin >> x;
			if (!x) zero++;
			else if (x == 1) one++;
		}

		if (one == 0) cout << "0\n";
		else cout << power(2, zero) * one << "\n";
	}

	return 0;
}