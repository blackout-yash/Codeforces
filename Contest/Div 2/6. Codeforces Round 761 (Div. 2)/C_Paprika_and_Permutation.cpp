// C. Paprika and Permutation
// Link - https://codeforces.com/contest/1617/problem/C



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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> arr, rem;
		bool flag[n + 1];
		memset(flag, false, sizeof(flag));

		fora(i, 0, n) {
			int x; cin >> x;
			if (x > n) arr.pb(x);
			else {
				if (flag[x]) arr.pb(x);
				else flag[x] = true;
			}
		} sort(arr.begin(), arr.end());

		fora(i, 0, arr.size()) {
			int temp = ceil(double(arr[i]) / 2) - 1;
			if (temp > 0) rem.pb(temp);
		}

		int index = 0, count = 0; bool store = true;
		fora(i, 1, n + 1) {
			if (!flag[i]) {
				auto it = lower_bound(rem.begin() + index, rem.end(), i);
				int temp = (it - rem.begin());
				if (temp >= rem.size()) {
					store = false; break;
				} else {
					index = temp + 1; count++;
				}
			}
		}

		if (store) cout << count nline;
		else cout << "-1\n";
	}

	return 0;
}