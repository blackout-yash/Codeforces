// A. Wasted Time
// Link - https://codeforces.com/contest/127/problem/A



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
	int n, k;
	cin >> n >> k;
	double x[n], y[n], dist = 0.0, time;
	fora(i, 0, n) cin >> x[i] >> y[i];

	fora(i, 1, n) {
		double temp = (x[i] - x[i - 1]) * (x[i] - x[i - 1]) + (y[i] - y[i - 1]) * (y[i] - y[i - 1]);
		dist += sqrt(temp);
	} time = dist / 50; time *= k;
	printf("%0.9lf\n", time);

	return 0;
}