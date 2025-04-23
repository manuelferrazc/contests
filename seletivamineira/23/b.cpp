#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    ll n,x,ans=0;
    cin >> n >> x;

    vector<pair<ll,ll>> v(n);
    for(pair<ll,ll> &p:v) cin >> p.ff >> p.ss;
    ll act=1;
    for(ll i=0;i<n;i++) {
        ll d = v[i].ff-act;
        d%=x;
        ans+=d;
        ans+=1+v[i].ss-v[i].ff;
        act = v[i].ss+1;
    }

    cout << ans << '\n';
    return 0;
}
