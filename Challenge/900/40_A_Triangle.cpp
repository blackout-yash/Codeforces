// A. Triangle
// Link - https://codeforces.com/problemset/problem/6/A



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

	int a[4];
	fora(i, 0, 4) cin >> a[i];
	sort(a, a + 4);

	if (a[0] + a[1] > a[2] || a[0] + a[1] > a[3] || a[0] + a[2] > a[3] || a[1] + a[2] > a[3]) cout << "TRIANGLE";
	else if (a[0] + a[1] == a[2] || a[0] + a[1] == a[3] || a[0] + a[2] == a[3] || a[1] + a[2] == a[3]) cout << "SEGMENT";
	else cout << "IMPOSSIBLE";

	return 0;
}