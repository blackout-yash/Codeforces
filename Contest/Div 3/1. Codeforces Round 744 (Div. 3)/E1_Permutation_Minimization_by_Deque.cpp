//      E1. Permutation Minimization by Deque
// Link - https://codeforces.com/contest/1579/problem/E1


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        ll x, prev;
        deque <ll> d;
        fora(0,n){
            cin >> x;
            if(!i) {
                d.push_back(x);
                prev = x;
            }else {
                if(prev < x) d.push_back(x);
                else {
                    d.push_front(x);
                    prev = x;
                }
            }
        }
        for(auto it = d.begin(); it != d.end(); it++) cout << *it << " ";
        cout << "\n";
    }
return 0;
}