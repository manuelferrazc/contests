#include <algorithm>
#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,w,x,y;
    cin >> n >> w;
    vector<set<ll>> v(w,set<ll>());
    vector<pair<ll,ll>> bl(n);

    for(ll i=0;i<n;i++) {
        cin >> y >> x;
        y--;
        x--;
        v[y].insert(x);
        bl[i] = make_pair(x,y);
    }


    vector<vector<ll>> v2(w);
    ll min = LLONG_MAX;
    for(ll i=0;i<w;i++) {
        min = ::min(min,(ll)v[i].size());
        for(auto a:v[i]) v2[i].push_back(a);
    }


    vector<ll> del(min,LLONG_MIN);
    for(ll x=0;x<min;x++) 
        for(ll i=0;i<w;i++) del[x]=max(del[x],v2[i][x]);
    ll q,t,a;
    cin >> q;
    while(q--) {
        cin >> t >> a;
        a--;
        y = bl[a].ff;
        x = bl[a].ss;
        cout << x << ' ' << y << '\n';
        auto it = lower_bound(v2[y].begin(),v2[y].end(),x);
        ll pos = it-v2[y].begin();
        cout << pos << ' ' << min << '\n';
        if(pos>=min) cout << "Yes\n";
        else if(del[pos]<t) cout << "Yess\n";
        else  cout << "No\n";
    }
}

int main() { _
    solve();
    return 0;
}
