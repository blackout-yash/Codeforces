// B. String LCM
// Link - https://codeforces.com/problemset/problem/1473/B



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define nline << "\n"
#define size(x) (x).size()
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------------------------*/

int _gcd (int a, int b) {
	return b ? _gcd (b, a % b) : a;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string s, t, temp1, temp2;
		cin >> s >> t;
		int n1 = size(s), n2 = size(t), lcm = n1 * n2 / _gcd(n1, n2);

		while (size(temp1) != lcm) temp1 += s;
		while (size(temp2) != lcm) temp2 += t;

		if (temp1 == temp2) cout << temp1 nline;
		else cout << "-1\n";
	}

	return 0;
}