#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,x;
    cin >> n >> x;
    
    if(n<4) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    map<ll,pair<ll,ll>> ma;
    map<ll,ll> md;

    for(ll i=2;i<n;i++) {
        md[v[i]] = i;
    }

    if(v[0]+v[1]<x) ma.insert(make_pair(v[0]+v[1],make_pair(0,1)));

    for(ll i=2;i<n-1;i++) {
        if(md[v[i]]==i) md.erase(v[i]);
        for(auto it = md.begin();it!=md.end();it++) {
            if(ma.count(x-v[i]-it->ff)) {
                auto it2 = ma.lower_bound(x-v[i]-it->ff);
                cout << it2->ss.ff+1 << ' ' << it2->ss.ss+1 << ' ' << i+1 << ' ' << it->ss+1 << '\n';
                return 0;
            }
        }

        for(ll j=0;j<i;j++) {
            if(v[j]+v[i]<x and not ma.count(v[j]+v[i])) ma.insert(make_pair(v[j]+v[i],make_pair(j,i)));
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
