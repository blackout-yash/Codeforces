// C. Letters
// Link - codeforces.com/problemset/problem/978/C



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

	int n, m;
	cin >> n >> m;
	vector <int> a(n), room(n);
	fora(i, 0, n) {
		cin >> a[i];
		if (i) room[i] = room[i - 1] + a[i];
		else room[i] = a[i];
	}
	fora(i, 0, m) {
		int b; cin >> b;
		auto it = lower_bound(room.begin(), room.end(), b);
		int index = it - room.begin(), temp;
		if (index) temp = b - room[index - 1];
		else temp = b;

		cout << index + 1 << " " << temp nline;
	}

	return 0;
}