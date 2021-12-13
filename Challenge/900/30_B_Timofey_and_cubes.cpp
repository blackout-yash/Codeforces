// B. Timofey and cubes
// Link - https://codeforces.com/problemset/problem/764/B



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

	int n;
	cin >> n;
	int arr[n];
	fora(i, 0, n) cin >> arr[i];

	int i = 0, j = n - 1;

	while (i <= j) {
		if (!(i & 1)) swap(arr[i], arr[j]);
		i++; j--;
	}

	fora(i, 0, n) cout << arr[i] << " ";
	return 0;
}