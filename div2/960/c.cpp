#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &i:v) cin >> i;
    ll s = accumulate(v.begin(),v.end(),0LL);

    set<ll> o1,o2;
    for(ll i=0;i<n;i++) {
        if(o1.count(v[i])) o2.insert(v[i]);
        else o1.insert(v[i]);

        if(o2.size()) v[i] = *o2.rbegin();
        else v[i] = 0;
    }
    s+=accumulate(v.begin(),v.end(),0LL);

    o1.clear();
    o2.clear();

    for(ll i=0;i<n;i++) {
        if(o1.count(v[i])) o2.insert(v[i]);
        else o1.insert(v[i]);

        if(o2.size()) v[i] = *o2.rbegin();
        else v[i] = 0;
    }
    
    for(ll i=0;i<n;i++) {
        s+=v[i]*(n-i);
    }

    cout << s << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();
    return 0;
}