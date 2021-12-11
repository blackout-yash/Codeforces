// B. Prime Square
// Link - https://codeforces.com/problemset/problem/1436/B



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

const int n = 1e5;
bitset < n + 5 > b;
vector <int> prime;

void sieve() {
	b.set();

	b[0] = b[1] = 0;

	for (long long i = 2; i <= n; i++) {
		if (b[i]) {
			prime.push_back(i);
			for (long long j = i * i; j <= n; j += i) {
				b[j] = 0;
			}
		}
	}
}

void increment(int &j) {
	while (j++) {
		if (!(binary_search(prime.begin(), prime.end(), j))) return;
	}
}

void decrement(int &num) {
	while (num--) {
		if (!(binary_search(prime.begin(), prime.end(), num))) return;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sieve();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) cout << "1\n";
		else {
			int num = n, j = 1;
			bool flag = false;
			if (binary_search(prime.begin(), prime.end(), num)) decrement(num);
			while (true) {
				for (auto x : prime) {
					if (x > j) {
						if (ceil(double(x - j) / num) == n - 1 && floor(double(x - j) / num) == n - 1) {
							flag = true; break;
						}
					}
				} if (flag) break;
				else increment(j);
			}

			fora(i, 0, n) {
				fora(k, 0, n) {
					if (i == k) cout << j << " ";
					else cout << num << " ";
				} cout nline;
			}
		}
	}
	return 0;
}