#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

pair<ll,ll> check(map<ll,set<ll>> &m, ll x) {
    for(auto it = m.begin();it!=m.end();it++) {
        
        auto it2 = m.lower_bound(x-it->ff);
        if(it2==m.end() or x-it->ff!=it2->ff) continue;
        if(it2->ff==it->ff) {
            if(it->ss.size()==1ULL) continue;
            return make_pair(*it->ss.begin(),*it->ss.rbegin());
        } else return make_pair(*it->ss.begin(),*it2->ss.begin());
    }

    return make_pair(-1LL,-1LL);
}

int main() { _
    ll n,x;
    cin >> n >> x;
    
    map<ll,set<ll>> m;
    set<ll> s;
    for(ll i=0;i<n;i++) {
        ll a;
        cin >> a;
        m[a].insert(i+1);
        s.insert(a);
    }

    for(ll i:s) {
        auto it = m.lower_bound(i);
        if(it->ff>=x) break;
        auto p = *it;
        if(it->ss.size()==1LL) {
            m.erase(it);
            auto ans = check(m,x-p.ff);
            if(ans.ff!=-1) {
                cout << *p.ss.begin() << ' ' << ans.ff << ' ' << ans.ss << '\n';
                return 0;
            }
        } else {
            ll id = *p.ss.begin();
            m[it->ff].erase(*p.ss.begin());
            auto ans = check(m,x-p.ff);
            if(ans.ff!=-1LL) {
                cout << id << ' ' << ans.ff << ' ' << ans.ss << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
