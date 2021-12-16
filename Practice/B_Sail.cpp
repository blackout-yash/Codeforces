// B. Sail
// Link - https://codeforces.com/problemset/problem/298/B



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size, s1, s2, e1, e2; string str;
	cin >> size >> s1 >> s2 >> e1 >> e2 >> str;

	int n = 0, s = 0, e = 0, w = 0;
	fora(i, 0, size) {
		if (str[i] == 'S') s++;
		else if (str[i] == 'N') n++;
		else if (str[i] == 'W') w++;
		else e++;
	}

	int num = 0;
	if (e1 > s1 && e >= (e1 - s1)) {
		num++; w = 0; e = (e1 - s1);
	} else if (e1 < s1 && w >= (s1 - e1)) {
		num++; e = 0; w = (s1 - e1);
	} else if (e1 == s1) {
		num++; e = 0; w = 0;
	}

	if (e2 > s2 && n >= (e2 - s2)) {
		num++; s = 0; n = (e2 - s2);
	} else if (e2 < s2 && s >= (s2 - e2)) {
		num++; n = 0; s = (s2 - e2);
	} else if (e2 == s2) {
		num++; n = 0; s = 0;
	}

	if (num != 2) cout << "-1\n";
	else {
		int count = 0; bool flag = true;
		fora(i, 0, size) {
			if (n == 0 && s == 0 && e == 0 && w == 0) {
				cout << count << "\n";
				flag = false; break;
			}
			if (n && str[i] == 'N') n--;
			else if (w && str[i] == 'W') w--;
			else if (s && str[i] == 'S') s--;
			else if (e && str[i] == 'E') e--;
			count++;
		}
		if (flag) cout << count << "\n";
	}

	return 0;
}