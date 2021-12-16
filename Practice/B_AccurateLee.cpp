//                     B. AccurateLee
// link - https://codeforces.com/contest/1369/problem/B


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)
 
int main(){
    ll t, n;
    cin >> t;
    while(t--){
        string s;
        cin >> n >> s;
        ll zero = 0, one = 0;
        fora(0,n){
            if(s[i] == '1')break;
            zero++;
        }

        for(ll i = n-1; i >= 0; i--){
            if(s[i] == '0')break;
            one++;
        }

        if(zero+one == n) cout << s << "\n";
        else {
            fora(0,zero) cout << "0";
            cout << "0";
            fora(0,one) cout << "1";
            cout << "\n";
        }
    }
return 0;
}