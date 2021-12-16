//                      B. Table Tennis
// Link - https://codeforces.com/problemset/problem/879/B


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)
 
int main(){
    ll n, k;
    cin >> n >> k;
    ll arr[n], max = INT_MIN, index = -1;
    fora(0,n){
        cin >> arr[i];
        if(max < arr[i]){
            max = arr[i];
            index = i;
        }
    }
    bool flag = true;
    for(ll i = 0; i < index; i++){
        ll count, num = arr[i];
        if(i) count = 1;
        else count = 0;
        for(ll j = i+1; j < index; j++){
            if(num > arr[j]){
                count++;
                i++;
            }else break;
        }
        if(count >= k){
            cout << num;
            flag = false;
            break;
        }
    }
 
    if(flag) cout << max << "\n";
return 0;
}