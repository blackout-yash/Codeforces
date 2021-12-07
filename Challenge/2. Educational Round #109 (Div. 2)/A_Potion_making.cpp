// A. Potion-making
// Link - https://codeforces.com/contest/1525/problem/A



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fora(i,a,b) for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define nline << "\n";
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------------------------*/

int _gcd (int a, int b) {
	return b ? _gcd (b, a % b) : a;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		int gcd = _gcd(k, 100 - k);
		cout << k / gcd + (100 - k) / gcd nline;
	}

	return 0;
}