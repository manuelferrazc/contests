#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,m;
    cin >> n >> m;

    vector<ll> v(n);
    set<ll> sla;
    for(auto &i:v) {
        cin >> i;
        sla.insert(i);
    }

    vector<pair<ll,ll>> mod(m);
    for(auto &i:mod) {
        cin >> i.ff >> i.ss;
        i.ff--;
        sla.insert(i.ss);
    }

    map<ll,set<ll>> pc;
    for(ll i=0;i<m;i++) {
        if(not pc.count(mod[i].ff)) pc.insert({mod[i].ff,set<ll>()});
        pc.at(mod[i].ff).insert(i+1);
    }
    
    map<ll,set<pair<ll,ll>>> count;
    for(ll i=0;i<n;i++) {
        if(not pc.count(i)) {
            count[v[i]].insert({m,0});
            continue;
        }
        count[v[i]].insert(make_pair(*pc.at(i).begin()-1,0));
    }

    for(ll i=0;i<m;i++) {
        auto &s = count[mod[i].ss];
        auto it = pc[mod[i].ff].lower_bound(i+1);
        
        if(*it==*pc[mod[i].ff].rbegin()) s.insert(make_pair(m,i+1));
        else s.insert(make_pair(*pc[mod[i].ff].upper_bound(i+1)-1,i+1));
    }
    
    ll ans=0;
    for(auto i:sla) {
        auto &s = count[i];
        ll qtd=0,a=0;
        while(a<=m) {
            auto x = s.lower_bound({a,-1});
            if(x==s.end()) break;
            qtd+=(x->first)-max(a,x->ss)+1;
            a=x->first+1;
        }
        ans+=(qtd*(qtd-1LL))>>1LL;
        ans+=qtd*(m+1-qtd);
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;   
}
