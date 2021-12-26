// A. Johnny and Ancient Computer
// Link - https://codeforces.com/problemset/problem/1362/A



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

string decimalToBinary(int n) {
	string s = bitset<64> (n).to_string();
	const auto loc1 = s.find('1');

	if (loc1 != string::npos) return s.substr(loc1);
	return "0";
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int tt;
	cin >> tt;
	while (tt--) {
		int a, b;
		cin >> a >> b;
		if (a == b) cout << "0\n";
		else {
			string s1 = decimalToBinary(a), s2 = decimalToBinary(b);
			bool flag = true; int n1 = size(s1), n2 = size(s2);
			fora(i, 0, min(n1, n2)) {
				if (s1[i] != s2[i]) {
					flag = false;
					break;
				}
			}

			if (!flag) cout << "-1\n";
			else {
				string temp;
				if (n1 > n2) temp = s1;
				else temp = s2;

				flag = true; int count = 0;
				fora(i, min(n1, n2), size(temp)) {
					if (temp[i] != '0') {
						flag = false;
						break;
					} else count++;
				}

				if (!flag) cout << "-1\n";
				else if (count % 3) cout << (count / 3) + 1 nline;
				else cout << (count / 3)nline;
			}
		}
	}

	return 0;
}