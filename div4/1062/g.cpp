#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    ll v[n];
    ll c[n];
    map<ll,vector<int>> m;

    for(int i=0;i<n;i++) {
        cin >> i[v];
        m[v[i]].push_back(i);
    }
    int id = 0;
    for(auto const &[fds,vpos]:m) {
        for(int pos:vpos) {
            v[pos] = id;
        }
        id++;
    }

    m.clear();

    for(int i=0;i<n;i++) cin >> i[c];

    // ll dp[n][id];
    ll suf[id];

    for(int i=0;i<id;i++) {
        if(v[n-1]==i) suf[i] = 0;
        else suf[i] = c[n-1];
    }

    for(int i=id-2;i>=0;i--) suf[i] = min(suf[i],suf[i+1]);
    
    for(int i=n-2;i>=0;i--) {
        ll suf2[id];
        for(int val=0;val<id;val++) suf2[val] = c[i]+suf[val];
        suf2[v[i]] = suf[v[i]];

        suf[id-1] = suf2[id-1];
        for(int val=id-2;val>=0;val--) suf[val] = min(suf[val+1],suf2[val]);
    }

    cout << suf[0] << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
