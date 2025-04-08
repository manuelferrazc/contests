#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,k;
vector<ll> v;

bool bb(ll mex) {
    set<ll> s;
    ll qtd=0;
    for(ll i=0;i<n;i++) {
        if(v[i]>=mex) continue;
        s.insert(v[i]);
        if(s.size()==mex) {
            s.clear();
            qtd++;
            if(qtd==k) return true;
        }
    }

    return false;
}

void solve() {
    cin >> n >> k;
    v.resize(n);
    for(ll &i:v) cin >> i;    

    ll l=1,r=n,ans=0;
    while(l<=r) {
        ll m = (l+r)>>1;
        if(bb(m)) {
            ans = m;
            l=m+1;
        } else r=m-1;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
