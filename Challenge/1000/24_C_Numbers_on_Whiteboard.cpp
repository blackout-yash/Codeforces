// C. Numbers on Whiteboard
// Link - https://codeforces.com/problemset/problem/1430/C



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define nline << "\n"
#define size(x) (x).size()
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------------------------*/

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int low = n - 1, high = n;
		cout << "2\n";
		fora(i, 0, n - 1) {
			cout << low << " " << high nline;
			if ((low + high) & 1) {
				high = (low + high) / 2;
				high++;
			} else high = (low + high) / 2;
			low--;
		}
	}

	return 0;
}