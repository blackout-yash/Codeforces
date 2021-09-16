//                   B. Different Divisors
// Link - https://codeforces.com/contest/1474/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)

const int n = 10000000;
bitset <10000005> b;
vector <int> prime;

void sieve(){
    b.set();

    b[0] = b[1] = 0;

    for(long long i = 2; i <= n; i++){
        if(b[i]){
            prime.push_back(i);
            for(long long j = i*i; j <= n; j += i){
                b[j] = 0;
            }
        }
    }
}
 
int main(){
    sieve();

    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        ll ans = 1, result = n+1;
        fora(0,2){
            auto it = lower_bound(prime.begin(), prime.end(), result);
            ll index = it - prime.begin();
            ans *= prime[index];
            result = prime[index] + n;
        }cout << ans << "\n";
    }
return 0;
}