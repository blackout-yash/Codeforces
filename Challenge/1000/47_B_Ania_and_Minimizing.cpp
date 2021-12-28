// B. Ania and Minimizing
// Ḷink - https://codeforces.com/problemset/problem/1230/B



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

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n, k; string s;
	cin >> n >> k >> s;

	fora(i, 0, n) {
		if (!k) break;
		if (i || i + 1 == n) {
			if (s[i] != '0') {
				s[i] = '0';
				k--;
			}
		} else {
			if (s[i] != '1') {
				s[i] = '1';
				k--;
			}
		}
	} cout << s;

	return 0;
}