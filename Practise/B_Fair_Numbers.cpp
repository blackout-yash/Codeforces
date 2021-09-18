//                  B. Fair Numbers
// https://codeforces.com/contest/1465/problem/B


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)
 
int main(){
    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(ll unsigned i = n;;i++){
            ll unsigned temp = i;
            bool flag = true;
            while(temp){
                ll rem = temp % 10;
                if(rem && i % rem){
                    flag = false;
                    break;
                }temp /= 10;
            }if(flag){
                cout << i << "\n";
                break;
            }
        }
    }
return 0;
}