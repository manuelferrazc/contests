#include <bits/stdc++.h>
#include <type_traits>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

const ll s = 1e6;

int main() { _
    ll n,k;
    cin >> n >> k;
    
    map<ll,pair<ll,ll>> c,t;

    ll l,r,g;
    while(n--) {
        cin >> l >> r >> g;
        if(not c.count(l)) c.insert({l,{0,0}});
        auto &p = c.at(l);
        p.ff++;
        p.ss+=g;

        if(not t.count(r)) t.insert({r,{0,0}});
        auto &q = t.at(r);
        q.ff++;
        q.ss+=g;
    }

    ll ans = 0;
    pair<ll,ll> act = {0,0};

    for(ll i=1;i<=s;i++) {
        if(c.count(i)) {
            auto &p = c.at(i);
            act.ff+=p.ff;
            act.ss+=p.ss;
            c.erase(i);
        }

        if(act.ff<=k) ans = max(ans,act.ss);
        
        if(t.count(i)) {
            auto &p = t.at(i);
            act.ff-=p.ff;
            act.ss-=p.ss;
            t.erase(i);
        }
    }

    cout << ans << '\n';
    return 0;
}
