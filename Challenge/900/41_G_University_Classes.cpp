// G. University Classes
// Link - https://codeforces.com/problemset/problem/847/G



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

	int n;
	cin >> n;
	string s[n];
	fora(i, 0, n) cin >> s[i];

	int maximum = INT_MIN;
	fora(i, 0, 7) {
		int count = 0;
		fora(j, 0, n) {
			if (s[j][i] == '1') count++;
		} maximum = max(maximum, count);
	} cout << maximum;

	return 0;
}