// B. Prinzessin der Verurteilung
// Link - https://codeforces.com/contest/1536/problem/B



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fora(i,a,b) for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define nline << "\n";
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------------------------*/

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n; string s;
		cin >> n >> s;

		bool flag = true;
		fora(i, 0, 26) {
			string str; str += char(97 + i);
			size_t found = s.find(str);
			if (found == string::npos) {
				cout << str << "\n";
				flag = false; break;
			}
		}

		if (flag) {
			fora(i, 0, 26) {
				string str1; str1 += char(97 + i);
				fora(j, 0, 26) {
					string str2 = str1 + char(97 + j);
					size_t found = s.find(str2);
					if (found == string::npos) {
						cout << str2 << "\n";
						flag = false; break;
					}
				} if (!flag) break;
			}

			if (flag) {
				fora(i, 0, 26) {
					string str1; str1 += char(97 + i);
					fora(j, 0, 26) {
						string str2 = str1 + char(97 + j);
						fora(k, 0, 26) {
							string str3 = str2 + char(97 + k);
							size_t found = s.find(str3);
							if (found == string::npos) {
								cout << str3 << "\n";
								flag = false; break;
							}
						} if (!flag) break;
					} if (!flag) break;
				}
			}
		}
	}

	return 0;
}