// A. Buying Torches
// Link - https://codeforces.com/problemset/problem/1418/A



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
		int x, y, k;
		cin >> x >> y >> k;

		int req = (y * k) + k, count = k, gain = (x - 1);
		req--;

		count += (req / gain);
		if (req % gain) count++;
		cout << count nline;
	}

	return 0;
}