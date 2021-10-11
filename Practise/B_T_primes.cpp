// B. T-primes
// Link - https://codeforces.com/problemset/problem/230/B



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bitset <1000001> b;
    vector <int> prime;
    b.set();
    b[0] = b[1] = 0;
    for (long long i = 2; i < 1000001; i++) {
        if (b[i]) {
            prime.push_back(i);
            for (long long j = i * i; j < 1000001; j += i) {
                b[j] = 0;
            }
        }
    }

    int n, num;
    cin >> n;
    fora(i, 0, n) {
        cin >> num;
        double root = sqrt(num);
        int temp1 = ceil(root), temp2 = floor(root);
        if (ceil(root) == floor(root)) {
            if (binary_search(prime.begin(), prime.end(), root)) cout << "YES\n";
            else cout << "NO\n";
        } else cout << "NO\n";
    }
    return 0;
}