//             A. Casimir's String Solitaire
// Link - https://codeforces.com/contest/1579/problem/A


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        ll a = 0, b = 0, c = 0;
        fora(0,s.size()){
            if(s[i] == 'A') a++;
            else if(s[i] == 'B') b++;
            else c++;
        }

        if(b == a+c) cout << "YES\n";
        else cout << "NO\n";
    }
return 0;
}