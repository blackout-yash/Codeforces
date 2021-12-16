// 				A. Gamer Hemose
// Link - https://codeforces.com/contest/1592/problem/A



#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t, n, h;
	cin >> t;
	while (t--) {
		cin >> n >> h;

		ll arr[n], count = 0, first = INT_MIN, second; second = first;

		fora(0, n) {
			cin >> arr[i];
			if (arr[i] > first) {
				second = first;
				first = arr[i];
			} else if (arr[i] > second && arr[i] != first)
				second = arr[i];
		}
		fora(0, n) {
			if (arr[i] == first) count++;
		} if (count > 1) second = first;

		ll que = h / (first + second);

		h -= ((first + second) * que);
		que *= 2;
		if (h) que++;
		if (h > first) que++;
		cout << que << "\n";
	}
	return 0;
}