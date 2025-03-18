#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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


void solve() {
    ll n,c;
    cin >> n >> c;
    vector<ll> sp(n),v(n);
    sp.resize(n);
    for(auto &i:v) cin >> i;
    v[0]+=c;
    ordered_set s;
    s.insert({v[0],0});
    sp[0] = v[0];
    ll m=0;
    for(ll i=1;i<n;i++) {
        if(v[i]>v[m]) m=i;
        s.insert({v[i],i});
        sp[i] = sp[i-1]+v[i];
    }

    for(ll i=0;i<n;i++) {
        s.erase({v[i],i});
        if(i==m) cout << 0 << ' ';
        else {
            ll x=0;
            if(i) x=sp[i-1];
            ll qtd=s.size()-s.order_of_key(make_pair(v[i]+x+1,-1));
            cout << i + qtd << ' ';
            // lembrar: uma segtree binaria, outra de seoma no vetor ordenado, uma busca binaria ??
        }
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
