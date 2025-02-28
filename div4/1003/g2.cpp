#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

bool check(set<ll> &p, ll n) {
    for(auto i:p) 
        if(n%i==0) return p.count(n/i);
    return false;
}

int main() {
    ll n;
    cin >> n >> n;

    vector<bool> c(n+1,true);
    set<ll> p;
    for(ll i=2;i<=n;i++) {
        if(c[i] == false) continue;
        p.insert(i);
        for(ll j=i+i;j<=n;j+=i) {
            c[j] = false;
        }
    }

    ll ans=0;
    vector<ll> v(n);
    for(auto &i:v) cin >> i;

    for(ll i=0;i<n;i++) {
        for(ll j=i;j<n;j++) {
            if(check(p,lcm(v[i],v[j]))) {
                ans++;
                // cout << v[i] << ' ' << v[j] << '\n';
            }
        }
    }

    cout << ans << '\n';

    return 0;
}