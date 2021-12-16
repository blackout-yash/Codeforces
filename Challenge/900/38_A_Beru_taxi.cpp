// A. Beru-taxi
// Link - https://codeforces.com/problemset/problem/706/A



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
	double a, b, x, y, n, v, minimum = INT_MAX;
	cin >> a >> b >> n;
	while (n--) {
		cin >> x >> y >> v;
		double temp = (a - x) * (a - x) + (b - y) * (b - y), dist = sqrt(temp), time = dist / v;
		minimum = min(minimum, time);
	} printf("%0.9lf", minimum);

	return 0;
}