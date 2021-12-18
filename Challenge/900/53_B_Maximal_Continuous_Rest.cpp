// B. Maximal Continuous Rest
// Link - https://codeforces.com/problemset/problem/1141/B



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

	int n, sum = 0, maximum = 0;
	cin >> n;
	int arr[n];
	fora(i, 0, n) {
		cin >> arr[i];
		if (arr[i]) sum++;
		else sum = 0;
		maximum = max(maximum, sum);
	}

	if (!sum) cout << maximum nline;
	else {
		fora(i, 0, n) {
			cin >> arr[i];
			if (arr[i]) sum++;
			else break;
			maximum = max(maximum, sum);
		} cout << maximum nline;
	}

	return 0;
}