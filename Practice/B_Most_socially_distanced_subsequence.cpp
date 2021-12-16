//       B. Most socially-distanced subsequence
// Link - https://codeforces.com/contest/1364/problem/B


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)
 
int main(){
    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        ll arr[n];
        fora(0,n) cin >> arr[i];

        vector <ll> v;
        bool positive = false, negative = false, last = false;

        if(arr[0] > arr[1]) negative = true;
        else positive = true;

        fora(0,n-1){
            if(positive){
                ll diff = arr[i] - arr[i+1];
                if(diff < 0){
                    v.push_back(arr[i]);
                    negative = true;
                    positive = false;
                }
            }else{
                ll diff = arr[i] - arr[i+1];
                if(diff > 0){
                    v.push_back(arr[i]);
                    negative = false;
                    positive = true;
                }
            }
        }v.push_back(arr[n-1]);

        cout << v.size() << "\n";
        for(auto x: v) cout << x << " ";
        cout << "\n";
    }
return 0;
}