// B1. Social Network (easy version)
// Link - https://codeforces.com/problemset/problem/1234/B1



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

int find(vector <int> &arr, int end, int key) {
	fora(i, 0, end) {
		if (arr[i] == key) return i;
	} return -1;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n, k;
	cin >> n >> k;
	vector <int> arr(n);
	fora(i, 0, n) cin >> arr[i];
	fora(i, 0, size(arr)) {
		if (i) {
			int index = find(arr, i, arr[i]);
			if (index == -1) {
				int size = i + 1;
				if (size > k) {
					arr.erase(arr.begin());
					i--;
				}
			} else {
				arr.erase(arr.begin() + i);
				i--;
			}
		}
	} reverse(arr.begin(), arr.end());
	cout << size(arr) nline;
	for (auto x : arr) cout << x << " ";

	return 0;
}