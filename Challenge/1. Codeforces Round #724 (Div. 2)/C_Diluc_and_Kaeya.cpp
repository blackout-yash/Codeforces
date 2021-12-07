// C. Diluc and Kaeya
// Link - codeforces.com/contest/1536/problem/C



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
		int n; string s;
		cin >> n >> s;
		map <pair <int, int>, int> m;
		int d = 0, k = 0;
		fora(i, 0, n) {
			if (s[i] == 'D') d++;
			else k++;

			int gcd = _gcd(d, k);
			int temp1 = d / gcd, temp2 = k / gcd;

			m[mp(temp1, temp2)]++;
			cout << m[mp(temp1, temp2)] << " ";
		} cout nline;
	}

	return 0;
}