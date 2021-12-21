// A. Filling Shapes
// Link - https://codeforces.com/problemset/problem/1182/A



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


	int n;
	cin >> n;
	if (n & 1) cout << "0\n";
	else {
		int num = pow(2, n / 2);
		cout << num nline;
	}

	return 0;
}