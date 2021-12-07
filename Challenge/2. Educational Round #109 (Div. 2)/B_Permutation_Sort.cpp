// B. Permutation Sort
// Link - https://codeforces.com/contest/1525/problem/B



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fora(i,a,b) for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define nline << "\n";
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------------------------*/

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> arr(n);
		bool flag = true;
		int index1, index2;
		fora(i, 0, n) {
			cin >> arr[i];
			if (arr[i] != (i + 1)) flag = false;
			if (arr[i] == 1) index1 = i;
			if (arr[i] == n) index2 = i;
		}

		if (flag) cout << "0\n";
		else if (arr[0] == 1 || arr[n - 1] == n) cout << "1\n";
		else if (index1 != n - 1 || index2 != 0) cout << "2\n";
		else cout << "3\n";
	}
	return 0;
}