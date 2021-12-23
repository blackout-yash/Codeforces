// C. Double-ended Strings
// Link - https://codeforces.com/problemset/problem/1506/C



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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string s, p;
		cin >> s >> p;
		int n1 = size(s), n2 = size(p), minimum = n1 + n2;
		fora(i, 0, n1) {
			fora(j, 1, (n1 + 1) - i) {
				size_t found = p.find(s.substr(i, j));
				if (found != string::npos) {
					minimum = min(minimum, n1 + n2 - (2 * j));
				}
			}
		} cout << minimum nline;
	}

	return 0;
}