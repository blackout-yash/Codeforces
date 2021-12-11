// B. Construct the String
// Link - https://codeforces.com/problemset/problem/1335/B



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

	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;

		string s; int count = 0;
		fora(i, 0, a) {
			s.pb(char('a' + count));
			if (count + 1 < b) count++;
		}

		count = 0;
		while (n--) {
			if (count == s.size()) count = 0;
			cout << s[count++];
		} cout nline;
	}

	return 0;
}