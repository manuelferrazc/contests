#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll k, n;
vector<ll> v;

bool check(ll g) {
    ll ans=0;
    for(auto i:v) ans+=min(i,g);
    return ans>=g*k;
}

int main() { _
    cin >> k >> n;
    v.resize(n);
    for(auto &i:v) cin >> i;

    ll l=0,r=1e13, ans=0;

    while(l<=r) {
        ll m=(l+r)>>1;
        
        if(check(m)) {
            ans=max(ans,m);
            l=m+1;
        } else r=m-1;
    }

    cout << ans << '\n';
    return 0;
}
