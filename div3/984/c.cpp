#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s,v;
    cin >> s;

    int uz = 0;

    for(ll i=0;i<((ll)s.size())-3;i++) if(s[i]=='1' and s[i+1]=='1' and s[i+2]=='0' and s[i+3]=='0') uz++;

    int q,i;
    
    cin >> q;
    while(q--) {
        cin >> i >> v;
        int contem = 0;

        i--;
        for(int j=i-3;j<=i;j++) if(s[j]=='1' and s[j+1]=='1' and s[j+2]=='0' and s[j+3]=='0') contem++;
        s[i] = v[0];
        int c2 = 0;
        for(int j=i-3;j<=i;j++) if(s[j]=='1' and s[j+1]=='1' and s[j+2]=='0' and s[j+3]=='0') c2++;

        uz += c2-contem;
        if(uz) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
