// A. Balanced Rating Changes
// Link - https://codeforces.com/problemset/problem/1237/A



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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n, sum = 0;
	cin >> n;
	vector <int> arr(n), temp(n);
	fora(i, 0, n) {
		cin >> arr[i];
		temp[i] = arr[i] / 2;
		sum += (temp[i]);
	}
	if (sum > 0) {
		fora(i, 0, n) {
			if (arr[i] < 0 && (arr[i] & 1)) {
				temp[i]--; sum--;
			}
			if (!sum) break;
		}
	} else if (sum < 0) {
		fora(i, 0, n) {
			if (arr[i] > 0 && (arr[i] & 1)) {
				temp[i]++; sum++;
			}
			if (!sum) break;
		}
	}

	for (auto x : temp) cout << x nline;

	return 0;
}