// A. Add and Divide
// Link - https://codeforces.com/problemset/problem/1485/A



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
		int a, b, count;
		cin >> a >> b;
		if (a < b) cout << "1\n";
		else {
			int i = 0, minimum = INT_MAX;
			bool flag = false;
			if (b == 1) {
				b++; i++; flag = true;
			}

			while (true) {
				double value = a, power = b;
				count = ceil(log10(value) / log10(power));
				if (pow(power, count) == a) count++;
				if (count + i > minimum) break;
				minimum = min(minimum, count + i);
				i++; b++;
			} cout << minimum nline;
		}
	}

	return 0;
}