#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string l,r;
    cin >> l >> r;
    int ans=0;
    bool d=false;
    for(ull i=0;i<l.size();i++) {
        if(d) {
            if(l[i]+1==r[i]) break;
            else if(l[i]=='9' and r[i]=='0') ans++;
            else break;
        } else {
            if(l[i]==r[i]) ans+=2;
            else if(l[i]+1==r[i]) {
                ans++;
                d = true;
            } else break;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
