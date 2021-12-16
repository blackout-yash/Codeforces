// B. Radio Station
// Link - https://codeforces.com/problemset/problem/918/B



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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	string name[n], command, ip, temp;
	map <string, int> ips;
	fora(i, 0, n) {
		cin >> name[i] >> temp;
		ips[temp] = i;
	}

	fora(i, 0, k) {
		cin >> command >> ip;
		cout << command << " " << ip << " #";
		temp = ip.substr(0, ip.size() - 1);
		cout << name[ips[temp]] nline;
	}

	return 0;
}