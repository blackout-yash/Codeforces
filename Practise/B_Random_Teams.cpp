// B. Random Teams
// Link - https://codeforces.com/problemset/problem/478/B



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> b >> a;
	int que = b / a, rem = b % a;
	int temp1 = (que * (que + 1)) / 2, temp2 = (que * (que - 1)) / 2;
	int minimum1 = rem * temp1 + (a - rem) * temp2;
	int minimum2 = ((b - a) * ((b - a) + 1)) / 2;
	cout << min(minimum1, minimum2) << " " << max(minimum1, minimum2);

	return 0;
}