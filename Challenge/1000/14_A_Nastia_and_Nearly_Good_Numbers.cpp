// A. Nastia and Nearly Good Numbers
// Link - https://codeforces.com/problemset/problem/1521/A



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
		int a, b;
		cin >> a >> b;
		int x = a * b, y = a, z = x + a;

		if (y % (a * b) != 0 && z % a == 0 && z % (a * b) != 0) cout << "YES\n" << x << " " << y << " " << z nline;
		else cout << "NO\n";
	}

	return 0;
}