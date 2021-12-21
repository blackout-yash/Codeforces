// D1. Sage's Birthday (easy version)
// Link - https://codeforces.com/problemset/problem/1419/D1



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

int count(vector <int> &ans) {
	int count = 0;
	fora(i, 1, size(ans) - 1) {
		if (ans[i - 1] > ans[i] && ans[i] < ans[i + 1]) count++;
	}
	return count;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, range = 0;
	cin >> n;
	vector <int> arr(n), ans;
	fora(i, 0, n) cin >> arr[i];

	if (n <= 2) {
		cout << "0\n";
		for (auto x : arr) cout << x << " ";
	} else {
		sort(arr.begin(), arr.end());
		fora(i, 0, size(arr)) {
			auto it = upper_bound(arr.begin(), arr.end(), arr[i]);
			if (it == arr.end()) break;
			else {
				int index = it - arr.begin();
				ans.pb(arr[index]); ans.pb(arr[i]);
				arr.erase(it);
			} range = i;
		}
		rfora(i, range + 1, size(arr)) ans.pb(arr[i]);

		cout << count(ans) nline;
		for (auto x : ans) cout << x << " ";
	}


	return 0;
}