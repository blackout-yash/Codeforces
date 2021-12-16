// 					B. Hemose Shopping
// Link - https://codeforces.com/contest/1592/problem/B



#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t, n, x;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		ll arr[n], temp[n];
		fora(0, n) {
			cin >> arr[i];
			temp[i] = arr[i];
		} sort(temp, temp + n);

		bool flag = true;
		fora(0, n) {
			if (arr[i] !=  temp[i] && x > i && x > (n - i - 1)) {
				cout << "NO\n";
				flag = false;
				break;
			}
		} if (flag) cout << "YES\n";
	}
	return 0;
}