#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define c first
#define x first
#define r second
typedef long long ll;
typedef unsigned long long ull;

map<ll,ll> mm;

ll bb(pair<ll,ll> &p, ll x) {
    ll l = 1,r=400'010;
    ll ans=0;
    while(l<=r) {
        ll y=(l+r)/2;

        if((((x-p.x)*(x-p.x))+(y*y))<=(p.r*p.r)) {
            ans=max(ans,y);
            l=y+1;
        } else r=y-1;
    }
    return ans;
}

void c(pair<ll,ll> &p) {
    for(ll i = p.c-p.r;i<=p.c+p.r;i++) {
        ll qtd = 2*bb(p,i)+1;
        if(mm.count(i)) mm.at(i) = max(mm.at(i),qtd);
        else mm.insert(make_pair(i,qtd));
    }
}

void solve() {
    ll n,m;
    cin >> n >> m;
    mm.clear();

    vector<pair<ll,ll>> v(n);
    for(auto &i:v) cin >> i.c;
    for(auto &i:v) cin >> i.r;

    for(auto &i:v) c(i);

    ll ans=0;
    for(auto &i:mm) ans+=i.second;

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
