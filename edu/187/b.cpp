#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int count(ll c) {
    int r=0;
    while(c) {
        r+=c%10;
        c/=10;
    }
    return r;
}

void solve() {
    ll x;
    cin >> x;
    // cout << "YESYCAS\n";
    
    int ans = INT_MAX;
    int l = count(x);
    // cout << l << '\n';

    for(int end = 1;end<=9*18;end++) {
        int c = count(end);
        if(c!=end) continue;
        if(end==l) {
            ans = 0;
            break;
        }

        c = l - end; // quanto tenho q diminuir 
        if(c<0) continue;

        string s = to_string(x);
        int qtd=0;
        // cout << "operacoes: ";
        
        if(c>0){
            for(int d=9;d and c;d--) {
                for(int j=1;j<s.size() and c;j++) {
                    
                    if(s[j]-'0'==d) {
                        // cout << j << ' ';
                        s[j] -= min(c,d);
                        c -= min(c,d);
                        qtd++;
                    }
                }
                if(s[0]-'0'==d and c and d>1) {
                    // cout << 0 << ' ';
                    qtd++;
                    // if(end==9) print("({},{},{}) ",c,d,s[0]);
                    s[0] -= min(c,d-1);
                    // if(end==9) cout << s[0] << ' ';
                    c -= min(c,d-1);
                }
            }
        } else {
            for(int d=0;d<9 and c;d++) {
                for(int j=0;j<s.size() and c;j++) {
                    if(s[j]-'0'==d) {
                        // cout << j << ' ';
                        s[j] += min('9'-s[j],abs(c));
                        c += min('9'-s[j],abs(c));
                        qtd++;
                    }
                }
            }
        }
        // cout << '\n';
        // cout << end << ' ' << qtd << '\n';
        if(c==0) ans = min(ans,qtd);
    }
    

    cout << ans << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
