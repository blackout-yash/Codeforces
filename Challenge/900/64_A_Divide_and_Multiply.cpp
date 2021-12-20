// A. Divide and Multiply
// Link - codeforces.com/contest/1609/problem/A



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

	int t;
	cin >> t;
	while (t--) {
		int n, count = 0, sum = 0;
		cin >> n;
		vector <int> arr(n);
		fora(i, 0, n) {
			cin >> arr[i];
			while (arr[i] % 2 == 0) {
				arr[i] /= 2; count++;
			}
		} sort(arr.begin(), arr.end());

		fora(i, 0, count) arr.back() *= 2;

		fora(i, 0, n) {
			sum += arr[i];
		} cout << sum nline;
	}

	return 0;
}