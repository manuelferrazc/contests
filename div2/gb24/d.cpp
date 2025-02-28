#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef tree<
pair<ll,ll>,
null_type,
less<pair<ll,ll>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const ll m = 998244353LL;

ll fexp(ll n, ll e=m-2) {
    if(e==1LL) return n;
    else if(not e) return 1LL;

    ll r = fexp(n,e/2LL)%m;
    r = (r*r)%m;
    if(e&1LL) r = (r*n)%m;

    return r%m;
}

void solve() {
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n),b(n);
    ordered_set ma,mb;

    // a - b
    vector<ll> u(n);
    ll lix = 0;
    for(auto &i:a) {cin >> i;ma.insert({i,lix++});}
    for(auto &i:b) {cin >> i;mb.insert({i,lix++});}
    ll prod = 1;
    for(ll i=0;i<n;i++) {
        auto it = ma.find_by_order(i)->ff, i2 = mb.find_by_order(i)->ff;
        u[i] = it-i2;
        prod = (prod*min(it,i2))%m;
    }

    cout << prod << ' ';
    ll x,o;
    while(q--) {
        cin >> o >> x;
        x--;
        if(o==1) { // ax = ax + 1
            ll act = a[x];
            auto it = (ll)ma.order_of_key({act+1,-1LL});
            it--;
            if(u[it]<0LL) {
                prod = (prod*fexp(act))%m;
                act++;
                prod = (prod*act)%m;
            } u[it]++;
            ma.erase(ma.find_by_order(it));
            ma.insert({++a[x],lix++});
        } else { // bx = bx + 1
            ll act = b[x];
            auto it = (ll)mb.order_of_key({act+1,-10LL});
            it--;
            if(u[it]>0LL) {
                prod = (prod*fexp(act))%m;
                act++;
                prod = (prod*act)%m;
            } u[it]--;
            mb.erase(mb.find_by_order(it));
            mb.insert({++b[x],lix++});
        }
        cout << prod << ' ';
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
