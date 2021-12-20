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

	int n; string s;
	cin >> n >> s;

	vector<int> v;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			v.pb(i);
			if (n / i != i) v.pb(n / i);
		}
	} sort(v.begin(), v.end());

	for (auto x : v) {
		string temp1 = s.substr(0, x), temp2 = s.substr(x);
		reverse(temp1.begin(), temp1.end());
		s = temp1 + temp2;
	} cout << s;

	return 0;
}