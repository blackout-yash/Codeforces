// C. Product of Three Numbers
// Link - https://codeforces.com/contest/1294/problem/C



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
        int n;
        cin >> n;
        set <int> s;

        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (n / i == i) {
                    if (i > 1 && i != n) s.insert(i);
                }
                else {
                    if (i > 1 && i != n) s.insert(i);
                    if ((n / i) > 1 && (n / i) != n) s.insert(n / i);
                }
            }
        } vector <int> v(s.begin(), s.end());

        if (s.size() > 2) {
            bool flag = true;
            fora(i, 0, v.size() - 1) {
                fora(j, i + 1, v.size()) {
                    int num1 = v[i], num2 = v[j], num3 = n / (num1 * num2);
                    if (num1 != num3 && num2 != num3 && num3 > 1 && (num1 * num2 * num3) == n) {
                        cout << "YES\n";
                        cout << num1 << " " << num2 << " " << num3 << "\n";
                        flag = false;
                        break;
                    }
                } if (!flag) break;
            }
            if (flag) cout << "NO\n";
        } else cout << "NO\n";
    }
    return 0;
}