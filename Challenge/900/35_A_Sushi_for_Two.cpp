// A. Sushi for Two
// Link - https://codeforces.com/problemset/problem/1138/A



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

	int prev = 0, count = 1, maximum = 0;
	fora(i, 0, n) {
		if (i) {
			if (arr[i] == arr[i - 1]) count++;
			else {
				prev = count;
				count = 1;
			}
		}
		if (prev >= count) {
			maximum = max(maximum, 2 * count);
		}
	} cout << maximum;

	return 0;
}