// B. Cover Points
// Link - https://codeforces.com/problemset/problem/1047/B



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

	int t, maximum = INT_MIN;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		maximum = max(maximum, a + b);
	} cout << maximum;

	return 0;
}