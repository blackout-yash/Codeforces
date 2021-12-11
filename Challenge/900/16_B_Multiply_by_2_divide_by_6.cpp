// B. Multiply by 2, divide by 6
// Link - https://codeforces.com/problemset/problem/1374/B



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
		int n, count = 0;
		cin >> n;
		bool flag = true;
		while (true) {
			if (n == 1) break;
			else if (n % 6 == 0) n /= 6;
			else if ((n * 2) % 6 == 0) {
				count++;
				n = (n * 2) / 6;
			} else {
				flag = false;
				break;
			} count++;
		} if (flag) cout << count nline;
		else cout << "-1\n";
	}

	return 0;
}