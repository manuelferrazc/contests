#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> cost,price;
vector<vector<ll>> recipe;

ll get(ll p) {
    if(cost[p]!=-1LL) return cost[p];

    cost[p] = 0;
    for(auto i:recipe[p]) cost[p]+=get(i);

    return cost[p] = min(cost[p],price[p]);
}

void solve() {
    ll n,k;
    cin >> n >> k;

    cost.assign(n,-1);
    price.assign(n,-1);
    recipe.assign(n,vector<ll>());

    for(ll i=0;i<n;i++) cin >> price[i];
    for(ll i=0;i<k;i++) {
        ll x;
        cin >> x;
        cost[x-1] = price[x-1] = 0;
    }

    for(ll i=0;i<n;i++) {
        ll m;
        cin >> m;
        if(m==0) cost[i]=price[i];

        while(m--) {
            ll sla;
            cin >> sla;
            recipe[i].push_back(sla-1);
        }
    }

    for(ll i=0;i<n;i++) cout << get(i) << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
