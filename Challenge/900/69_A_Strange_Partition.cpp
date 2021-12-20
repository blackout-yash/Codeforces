// A. Strange Partition
// Link - https://codeforces.com/problemset/problem/1471/A



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

	int t;
	cin >> t;
	while (t--) {
		int n, x, sum = 0, count = 0;
		cin >> n >> x;
		fora(i, 0, n) {
			int num; cin >> num;
			sum += num;
			count += ceil(double(num) / x);
		} int ans =  ceil(double(sum) / x);
		cout << ans << " " << count nline;
	}

	return 0;
}