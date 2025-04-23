#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> v;

vector<ll> count(ll i) {
    vector<ll> r(v.size(),0);
    r[i] = v[i];
    ll act = v[i];
    for(ull j=i+1;j<v.size();j++) {
        if(v[j]<act) act = v[j];
        r[j] = act;
    }
    act = v[i];
    for(ll j=i-1;j>=0;j--) {
        if(v[j]<act) act = v[j];
        r[j] = act;
    }
    return r;
}

int main() { _
    ll n;
    cin >> n;
    v.resize(n);
    for(ll &i:v) cin >> i;

    ll m=0;
    vector<ll> ans;
    for(ll i=0;i<n;i++) {
        auto sla = count(i);
        ll ss = accumulate(sla.begin(),sla.end(),0LL);
        if(ss>m) {
            m = ss;
            ans = sla;
        }
    }

    for(ll i:ans) cout << i << ' ';
    cout << '\n';
    return 0;
}
