// C. Unique Number
// Link - https://codeforces.com/problemset/problem/1462/C



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
		int n;
		cin >> n;
		if (n > 45) cout << "-1\n";
		else {
			string s1, s2;
			int temp = 9, temp1 = n;
			while (temp) {
				if (temp <= n) {
					s1 += to_string(temp);
					n -= temp;
				} temp--;
			}

			temp = 1; n = temp1;
			while (temp != 10) {
				if (temp <= n) {
					s2 += to_string(temp);
					n -= temp;
				} temp++;
			}
			sort(s1.begin(), s1.end());
			sort(s2.begin(), s2.end());

			if (s1 > s2) cout << s1 nline;
			else cout << s2 nline;
		}
	}

	return 0;
}