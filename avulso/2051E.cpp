#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve(){
    ll n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++) cin >> v[i].ff;
    for(ll i=0;i<n;i++) cin >> v[i].ss;
    sort(v.begin(),v.end());
    map<ll,ll> m;
    set<ll> s = {0LL};
    for(auto &p:v) {
        s.insert(p.ff);
        s.insert(p.ss);
    }
    ll ans = LLONG_MIN,i=0,qtd=0;
    for(auto price:s) {
        while(i<n and v[i].ff<price) {
            if(not m.count(v[i].ss)) m.insert({v[i].ss,0});
            m.at(v[i].ss)++;
            qtd++;
            i++;
        }
        while(qtd and m.begin()->ff<price) {
            auto p = m.begin();
            qtd-=p->ss;
            m.erase(p);
        }
        if(qtd>k) continue;
        ll lucro = (n-i+qtd)*price;
        ans = max(ans,lucro);
    }
    cout << ans << '\n';
}

int main() { _
    int n;
    cin >> n;
    while(n--) solve();
    return 0;
}
