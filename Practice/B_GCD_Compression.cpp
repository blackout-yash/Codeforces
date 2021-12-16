//                 B. GCD Compression
// Link - https://codeforces.com/contest/1370/problem/B


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)
 
int main(){
    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        ll arr[2*n];
        fora(0,2*n) cin >> arr[i];

        ll count = 0, key, temp = n-1;
        map<ll, ll> m;

        fora(0,2*n){
            if(!(arr[i] & 1)){
                count++;
                if(count == 1) key = i+1;
                else if(count == 2){
                    m[key] = i+1;
                    count = 0;
                }
            }
        }

        count = 0;
        fora(0,2*n){
            if(arr[i] & 1){
                count++;
                if(count == 1) key = i+1;
                else if(count == 2){
                    m[key] = i+1;
                    count = 0;
                }
            }
        }

        for(auto it = m.begin(); it != m.end(); it++){
            if(!temp) break;
            cout << it->first << " " << it->second << "\n";
            temp--;
        }
    }
return 0;
}