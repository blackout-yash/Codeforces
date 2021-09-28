//                  B. Shifting Sort
// Link - https://codeforces.com/contest/1579/problem/B


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)

ll find(ll arr[], ll key, ll start, ll end){
    fora(start, end){
        if(arr[i] == key) return i;
    }
return -1;
}

void insert(ll arr[], ll start, ll end){
    for(ll i = end; i > start; i--){
        arr[i] = arr[i-1];
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        ll arr[n], sorted[n], k = 0;
        fora(0,n){
            cin >> arr[i];
            sorted[i] = arr[i];
        }sort(sorted, sorted+n);

        vector <vector <ll>> v; 
        fora(0,n){
            ll index = find(arr, sorted[i], i, n);
            if(index != i){
                k++;
                vector <ll> temp;
                temp.push_back(i+1);
                temp.push_back(index+1); 
                temp.push_back(index-i); 

                insert(arr, i, index);
                arr[i] = sorted[i];

                v.push_back(temp);
            }
        }

        cout << k << "\n";
        fora(0,k) {
            for(ll j = 0; j < 3; j++){
                cout << v[i][j] << " ";
            }cout << "\n";
        }
    }
return 0;
}