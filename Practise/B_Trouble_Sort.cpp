// B. Trouble Sort
// Link - https://codeforces.com/problemset/problem/1365/B



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

bool isSorted(int arr[], int temp[], int n) {
	fora(i, 0, n) {
		if (arr[i] != temp[i]) return false;
	}
	return true;
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
		int arr[n], b[n], temp[n], zero = 0, one = 0;
		bool flag = true;
		fora(i, 0, n) {
			cin >> arr[i];
			temp[i] = arr[i];
		} sort(temp, temp + n);
		fora(i, 0, n) {
			cin >> b[i];
			if (b[i]) one++;
			else zero++;
		}

		if (isSorted(arr, temp, n)) cout << "YES\n";
		else if (one > 0 && zero > 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}