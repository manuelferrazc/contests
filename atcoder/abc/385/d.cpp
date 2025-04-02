#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main() { _
    ll n,m,x,y;
    cin >> n >> m >> x >> y;
    map<ll,ordered_set> ml,mc;
    for(ll i=0;i<n;i++) {
        ll a,b;
        cin >> a >> b;
        if(not ml.count(a)) ml.insert({a,ordered_set()});
        ml.at(a).insert(b);
        if(not mc.count(b)) mc.insert({b,ordered_set()});
        mc.at(b).insert(a);
    }
    ll ans=0;
    while(m--) {
        string s;
        ll d;
        cin >> s >> d;

        if(s[0]=='U') {
            if(not ml.count(x)) {
                y+=d;
                continue;
            }
            ordered_set &p = ml.at(x);
            auto it = p.lower_bound(y);
            while(it!=p.end() and *it<=y+d) {
                auto aux = it;
                mc.at(*it).erase(x);
                if(not mc.at(*it).size()) mc.erase(*it);

                it++;
                p.erase(aux);
                ans++;
            }
            if(not p.size()) ml.erase(x);
            y+=d;
        } else if(s[0]=='D') {
            if(not ml.count(x)) {
                y-=d;
                continue;
            }
            ordered_set &p = ml.at(x);
            auto it = p.lower_bound(y-d);
            while(it!=p.end() and *it<=y) {
                auto aux = it;
                mc.at(*it).erase(x);
                if(not mc.at(*it).size()) mc.erase(*it);

                it++;
                p.erase(aux);
                ans++;
            }
            if(not p.size()) ml.erase(x);

            y-=d;
        } else if(s[0]=='L') {
            if(not mc.count(y)) {
                x-=d;
                continue;
            }
            ordered_set &p = mc.at(y);
            auto it = p.lower_bound(x-d);
            while(it!=p.end() and *it<=x) {
                auto aux = it;
                ml.at(*it).erase(y);
                if(not ml.at(*it).size()) ml.erase(*it);

                it++;
                p.erase(aux);
                ans++;
            }
            if(not p.size()) mc.erase(y);
            x-=d;
        } else if(s[0]=='R') {
            if(not mc.count(y)) {
                x+=d;
                continue;
            }
            ordered_set &p = mc.at(y);
            auto it = p.lower_bound(x);
            while(it!=p.end() and *it<=x+d) {
                auto aux = it;
                ml.at(*it).erase(y);
                if(not ml.at(*it).size()) ml.erase(*it);
                it++;
                p.erase(aux);
                ans++;
            }
            if(not p.size()) mc.erase(y);
            x+=d;
        } 
    }
    cout << x << ' ' << y << ' ' << ans << '\n';

    return 0;
}
