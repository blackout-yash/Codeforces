// B. Parity Alternated Deletions
// Link - codeforces.com/problemset/problem/1144/B



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

	int n;
	cin >> n;
	vector <int> odd, even;
	fora(i, 0, n) {
		int x; cin >> x;
		if (x & 1) odd.pb(x);
		else even.pb(x);
	}

	int size1 = odd.size(), size2 = even.size(), diff = abs(size1 - size2), sum = 0;
	if (diff < 2) cout << "0\n";
	else if (size1 > size2) {
		sort(odd.begin(), odd.end());
		fora(i, 0, diff - 1) sum += odd[i];
		cout << sum nline;
	} else {
		sort(even.begin(), even.end());
		fora(i, 0, diff - 1) sum += even[i];
		cout << sum nline;
	}

	return 0;
}