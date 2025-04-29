#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> v(n),b(m);
    for(ll &i:v) cin >> i;
    for(ll &i:b) cin >> i;

    map<ll,ll> mb;
    for(ll i:b) mb[i]++;
    ll q=0,ans=0;

    map<ll,ll> mvkaio; // era pra ser mv kk
    for(ll i=0;i<m;i++) {
        mvkaio[v[i]]++;
        if(mb.count(v[i]) and mvkaio[v[i]]<=mb[v[i]]) q++;
    }

    if(q>=k) ans++;

    for(ll i=m;i<n;i++) {
        mvkaio[v[i-m]]--;
        if(mb.count(v[i-m]) and mvkaio[v[i-m]]<mb[v[i-m]]) q--;
        if(mvkaio[v[i-m]]==0) mvkaio.erase(v[i-m]);

        mvkaio[v[i]]++;
        if(mb.count(v[i]) and mvkaio[v[i]]<=mb[v[i]]) q++;
        if(q>=k) ans++; 
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
