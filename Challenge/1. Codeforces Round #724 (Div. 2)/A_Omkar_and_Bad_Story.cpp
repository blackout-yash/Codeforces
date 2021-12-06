// A. Omkar and Bad Story
// Link - https://codeforces.com/contest/1536/problem/A



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

int find(vector <int> &arr, int key) {
	fora(i, 0, arr.size()) {
		if (arr[i] == key) return false;
	}
	return true;
}

void check(vector <int> &arr) {
	fora(i, 0, arr.size()) {
		fora(j, i + 1, arr.size()) {
			int temp = abs(arr[i] - arr[j]);
			if (find(arr, temp)) arr.pb(temp);
			if (arr.size() >= 301) return;
		}
	}
	return;
}

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
		fora(i, 0, n) cin >> arr[i];

		bool flag = true;
		while (arr.size() <= 300) {
			int size = arr.size();
			check(arr);
			if (arr.size() == size && size <= 300) {
				cout << "YES\n" << size nline;
				for (auto x : arr) cout << x << " ";
				cout nline; flag = false; break;
			}
		}
		if (flag) cout << "NO\n";
	}

	return 0;
}