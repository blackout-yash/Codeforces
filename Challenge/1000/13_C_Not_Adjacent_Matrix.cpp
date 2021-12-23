// C. Not Adjacent Matrix
// Link - https://codeforces.com/contest/1520/problem/C



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
		if (n == 1)cout << "1\n";
		else if (n == 2) cout << "-1\n";
		else {
			int arr[n][n], odd = 1, even = 4, minimum, maximum;
			fora(i, 0, n) {
				if (i + 1 == n) {
					minimum = min(odd, even);
					maximum = max(odd, even);
				}
				fora(j, 0, n) {
					if (i + 1 == n) {
						if (j + 1 == n) arr[i][j] = 2;
						else {
							if (maximum > n * n) maximum = minimum;
							arr[i][j] = maximum;
							maximum += 2;
						}
					}
					else if (i & 1) {
						arr[i][j] = even;
						even += 2;
					} else {
						arr[i][j] = odd;
						odd += 2;
					}
				}
			}

			fora(i, 0, n) {
				fora(j, 0, n) cout << arr[i][j] << " ";
				cout nline;
			}
		}
	}

	return 0;
}