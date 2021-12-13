// B. The Time
// Link - https://codeforces.com/problemset/problem/622/B



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

	int hour, minute, a;
	string s;
	cin >> s >> a;

	hour = int32_t(s[0] - '0') * 10 + int32_t(s[1] - '0');
	minute = int32_t(s[3] - '0') * 10 + int32_t(s[4] - '0');

	minute += a;
	int mrem = minute % 60, que = minute / 60, hrem;
	hour += que;
	hrem = hour % 24;

	int size1 =  floor(log10(hrem) + 1), size2 =  floor(log10(mrem) + 1);

	if (size1 == 2 && size2 == 2) cout << hrem << ":" << mrem;
	else if (size1 == 2) cout << hrem << ":0" << mrem;
	else if (size2 == 2) cout << 0 << hrem << ":" << mrem;
	else cout << 0 << hrem << ":0" << mrem;

	return 0;
}