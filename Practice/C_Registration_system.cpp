// C. Registration system
// Link - https://codeforces.com/problemset/problem/4/C



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	map <string, int> m;
	fora(i, 0, n) {
		string temp; cin >> temp;
		m[temp]++;
		if (m[temp] == 1) cout << "OK\n";
		else cout << temp << m[temp] - 1 << "\n";
	}

	return 0;
}