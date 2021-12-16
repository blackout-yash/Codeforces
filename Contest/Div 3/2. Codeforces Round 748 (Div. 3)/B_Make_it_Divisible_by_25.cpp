// B. Make it Divisible by 25
// Link - https://codeforces.com/contest/1593/problem/B



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		int zero = INT_MAX, two = INT_MAX, five = INT_MAX, seven = INT_MAX;

		bool flag = false;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (flag && s[i] == '0') {
				zero = s.size() - 2 - i;
				break;
			}

			if (s[i] == '0') flag = true;
		}

		flag = false;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '5') flag = true;
			if (flag && s[i] == '2') {
				two = s.size() - 2 - i;
				break;
			}
		}

		flag = false;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '0') flag = true;
			if (flag && s[i] == '5') {
				five = s.size() - 2 - i;
				break;
			}
		}

		flag = false;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '5') flag = true;
			if (flag && s[i] == '7') {
				seven = s.size() - 2 - i;
				break;
			}
		} cout << min(zero, min(two, min(five, seven))) << "\n";
	}
	return 0;
}