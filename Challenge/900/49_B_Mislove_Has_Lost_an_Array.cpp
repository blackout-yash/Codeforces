// B. Mislove Has Lost an Array
// Link - https://codeforces.com/problemset/problem/1204/B



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

	int n, l, r, i = 0, minimal = 0, maximal = 0;
	cin >> n >> l >> r;

	fora(i, 0, n) {
		minimal += (pow(2, l - 1));
		if (l != 1) l--;
	}

	fora(j, 0, n) {
		maximal += (pow(2, i));
		if (i < r - 1) i++;
	}

	cout << minimal << " " << maximal;
	return 0;
}