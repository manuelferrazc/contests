#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
    
ll n,k;
vector<ll> s;

bool check(ll d) {
    ll act = LLONG_MIN, qtd=0;
    
    while(qtd<k) {
        auto it = lower_bound(s.begin(),s.end(),act+d);
        if(it==s.end()) return false;
        qtd++;
        act = *it;
    }
    return true;
}

int main() { _
    cin >> n >> k;
    s.resize(n);
    for(auto &i:s) cin >> i;

    ll m,l = 1, r=1e10,ans=LLONG_MIN;

    while(l<=r) {
        m=(l+r)>>1LL;

        if(check(m)) {
            ans=max(ans,m);
            l=m+1;
        } else r=m-1;
    }

    cout << ans << '\n';

    return 0;
}
