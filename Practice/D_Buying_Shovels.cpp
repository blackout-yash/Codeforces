// D. Buying Shovels
// Link - https://codeforces.com/problemset/problem/1360/D



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        set <int> s;

        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (n / i == i) {
                    if (k >= i) s.insert(i);
                }
                else {
                    if (k >= i) s.insert(i);
                    if ((n / i) <= k) s.insert(n / i);
                }
            }
        }

        for (auto it = s.rbegin(); it != s.rend(); it++) {
            if (n % *it == 0) {
                cout << n / *it << "\n";
                break;
            }
        }
    }
    return 0;
}