//              A. Regular Bracket Sequences
// Link - https://codeforces.com/problemset/problem/1574/A


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)

void print(char ch[], ll n){
    fora(0,n) cout << ch[i];
    cout << "\n";
}
 
int main(){
    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;

        fora(0,n){
            ll open = i+1, close = 1+i;
            while(close){
                if(open){
                    cout << "(";
                    open--;
                }else {
                    cout << ")";
                    close--;
                }
            }

            for(ll j = 0; j < 2*(n-1-i); j++){
                if(j & 1) cout << ")";
                else cout << "(";
            }cout << "\n";
        } 
    }
return 0;
}