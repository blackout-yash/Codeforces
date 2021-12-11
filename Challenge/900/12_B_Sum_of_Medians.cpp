// B. Sum of Medians
// Link - https://codeforces.com/problemset/problem/1440/B



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
		int n, k;
		cin >> n >> k;
		vector <int> arr(n * k);
		fora(i, 0, n * k) cin >> arr[i];
		sort(arr.begin(), arr.end());

		int sum = 0, size = n * k, i = 1, range = ceil((double)n / 2);
		if (!(n & 1)) range++;
		while (k--) {
			sum += arr[size - (i * range)];
			i++;
		} cout << sum nline;
	}

	return 0;
}