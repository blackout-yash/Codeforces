// B. Phoenix and Puzzle
// Link - https://codeforces.com/problemset/problem/1515/B



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
		int n;
		cin >> n;
		if (n & 1) cout << "NO\n";
		else {
			int num1 = sqrt(n / 2), num2 = sqrt(n / 4);
			if (n % 2 == 0 && num1 * num1 == n / 2) cout << "YES\n";
			else if (n % 4 == 0 && num2 * num2 == n / 4) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}