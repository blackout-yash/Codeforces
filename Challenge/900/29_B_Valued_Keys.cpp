// B. Valued Keys
// Link - https://codeforces.com/problemset/problem/801/B



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

	string s1, s2;
	cin >> s1 >> s2;

	bool flag = true;
	fora(i, 0, s1.size()) {
		if (s2[i] > s1[i]) {
			flag = false;
			break;
		}
	}
	if (flag)cout << s2;
	else cout << "-1\n";

	return 0;
}