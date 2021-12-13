// B. Food Buying
// Link - https://codeforces.com/problemset/problem/1296/B



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

int stringTointeger(string str) {
	int temp = 0;
	for (int i = 0; i < str.length(); i++) {
		temp = temp * 10 + (str[i] - '0');
	}
	return temp;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		int ans = 0, temp = 0, size, num;
		while (!s.empty()) {
			temp = int32_t(s[0] - '0');
			size = s.size();
			ans += temp * pow(10, size - 1);
			s = s.substr(1);
			num = stringTointeger(s) + temp * pow(10, size - 2);
			if (num == 0) break;
			else s = to_string(num);
		} cout << ans nline;
	}

	return 0;
}