// B. Decoding
// Link - https://codeforces.com/problemset/problem/746/B



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

	if (n & 1) {
		int i = 0;
		while (i != n) {
			if (i & 1) temp = s[i] + temp;
			else temp.pb(s[i]);
			i++;
		} cout << temp;
	} else {
		int i = 0;
		while (i != n) {
			if (i & 1) temp.pb(s[i]);
			else temp = s[i] + temp;
			i++;
		} cout << temp;
	}

	return 0;
}