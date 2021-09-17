//                         B. 01 Game
// Link - https://codeforces.com/contest/1373/problem/B


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)
 
int main(){
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        ll i = 0; 
        while(!s.empty()){
            size_t found1 = s.find("01");
            size_t found2 = s.find("10");
            if (found1 == string::npos && found2 == string::npos) break;
            else if(found1 != string::npos) s.erase(found1, 2);
            else s.erase(found2, 2);
            i++;
        }
        if(i & 1) cout << "DA\n";
        else cout << "NET\n";
    }
return 0;
}