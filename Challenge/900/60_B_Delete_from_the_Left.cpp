// B. Delete from the Left
// Link - https://codeforces.com/problemset/problem/1005/B



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

	int count = 0, j = s1.size() - 1, k = s2.size() - 1;
	rfora(i, 0, min(s1.size(), s2.size())) {
		if (s1[j--] == s2[k--]) count++;
		else break;
	}
	cout << s1.size() + s2.size() - 2 * count;

	return 0;
}