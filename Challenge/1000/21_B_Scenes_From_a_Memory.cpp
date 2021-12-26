// B. Scenes From a Memory
// Link - https://codeforces.com/contest/1562/problem/B



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

int find(string &s, char c) {
	fora(i, 0, size(s)) {
		if (s[i] == c) return i;
	}
	return -1;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n; string s;
		cin >> n >> s;

		if (find(s, '1') != -1) cout << "1\n1\n";
		else if (find(s, '4') != -1) cout << "1\n4\n";
		else if (find(s, '6') != -1) cout << "1\n6\n";
		else if (find(s, '8') != -1) cout << "1\n8\n";
		else if (find(s, '9') != -1) cout << "1\n9\n";
		else {
			vector <int> itwo, ithree, ifive, iseven;
			fora(i, 0, size(s)) {
				int num = int32_t(s[i] - '0');
				if (num == 2) itwo.pb(i);
				else if (num == 3) ithree.pb(i);
				else if (num == 5) ifive.pb(i);
				else if (num == 7) iseven.pb(i);
			}

			int two = size(itwo), three = size(ithree), five = size(ifive), seven = size(iseven);

			if (two > 1) cout << "2\n22\n";
			else if (two && five && (itwo.front() < ifive.back())) cout << "2\n25\n";
			else if (two && seven && (itwo.front() < iseven.back())) cout << "2\n27\n";

			else if (three && two && (ithree.front() < itwo.back())) cout << "2\n32\n";
			else if (three > 1) cout << "2\n33\n";
			else if (three && five && (ithree.front() < ifive.back())) cout << "2\n35\n";

			else if (five && two && (ifive.front() < itwo.back())) cout << "2\n52\n";
			else if (five > 1) cout << "2\n55\n";
			else if (five && seven && (ifive.front() < iseven.back())) cout << "2\n57\n";

			else if (seven && two && (iseven.front() < itwo.back())) cout << "2\n72\n";
			else if (seven && five && (iseven.front() < ifive.back())) cout << "2\n75\n";
			else if (seven > 1) cout << "2\n77\n";
		}
	}

	return 0;
}