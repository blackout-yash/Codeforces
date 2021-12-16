//                  B. Red and Blue
// Link - https://codeforces.com/contest/1469/problem/B


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)
 
int main(){
    ll t, n, m;
    cin >> t;
    while(t--){
        cin >> n;
        ll r[n];
        fora(0,n) cin >> r[i];
        cin >> m;
        ll b[m];
        fora(0,m) cin >> b[i];

        ll sum1 = 0, sum2 = 0;
        ll temp1 = 0, temp2 = 0;
        fora(0,n){
            temp1 += r[i];
            sum1 = max(sum1, temp1);
        }
        fora(0,m){
            temp2 += b[i];
            sum2 = max(sum2, temp2);
        }
        cout << sum1+sum2 << "\n";
    }
return 0;
}