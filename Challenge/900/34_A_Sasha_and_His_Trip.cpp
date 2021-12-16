// A. Sasha and His Trip
// Link - https://codeforces.com/problemset/problem/1113/A



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

	int n, k;
	cin >> n >> k;

	if (k >= n) cout << n - 1;
	else cout << (k - 1) + ((n - k) * ((n - k) + 1)) / 2;

	return 0;
}