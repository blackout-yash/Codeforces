// B. Grow The Tree
// Link - https://codeforces.com/problemset/problem/1248/B



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
	sort(arr, arr + n);

	int x = 0, y = 0;
	rfora(i, n / 2, n) x += arr[i];
	fora(i, 0, n / 2) y += arr[i];

	cout << x*x + y*y;

	return 0;
}