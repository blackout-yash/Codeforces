// B. Gregor and the Pawn Game
// Link - https://codeforces.com/problemset/problem/1549/B



#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fora(i,a,b) for(ll i=a;i<b;i++)

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, count = 0;
		string start, end;
		cin >> n >> start >> end;

		fora(i, 0, n) {
			if (!i) {
				if (end[i] == '1' && start[i] == '0') count++;
				else if (end[i] == '1' && start[i + 1] == '1') {
					start[i + 1] = '2';
					count++;
				}
			} else if (i + 1 == n) {
				if (end[i] == '1' && start[i] == '0') count++;
				else if (end[i] == '1' && start[i - 1] == '1') count++;
			} else {
				if (end[i] == '1' && start[i] == '0') count++;
				else if (end[i] == '1' && start[i - 1] == '1') count++;
				else if (end[i] == '1' && start[i + 1] == '1') {
					start[i + 1] = '2';
					count++;
				}
			}
		} cout << count << "\n";
	}

	return 0;
}