//                   B. Combinatorics Homework
// Link - https://codeforces.com/problemset/problem/1574/B



#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)
 
int main(){
    ll t, a, b, c, m;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> m;
        ll sum = a+b+c;
        ll maximum = sum-3, minimum = 2*max(a, max(b, c)) - sum - 1;
        if(m >= minimum && m <= maximum) cout << "YES\n";
        else cout << "NO\n";
    }
return 0;
}