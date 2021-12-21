// A. Santa Claus and Candies
// Link - https://codeforces.com/problemset/problem/753/A



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

int count(int n) {
	int count = (-1 + sqrt(1 + 8 * n)) / 2;
	return count;
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int temp = count(n);
	cout << temp nline;
	fora(i, 0, temp - 1) cout << i + 1 << " ";
	cout << n - (temp * (temp - 1)) / 2;

	return 0;
}