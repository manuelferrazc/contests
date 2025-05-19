#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,ans=0,s=0;
    cin >> n;

    vector<ll> v(n), c(n,0);
    for(ll &i:v) cin >> i;

    for(ll i=0;i<n;i++) {
        v[i] +=n*1000'000'000LL;
        v[i]%=n;
        s+=v[i];
        s%=n;
        if(s==0) ans++;
        ans+=c[s];
        c[s]++;
    }

    cout << ans << '\n';

    return 0;
}
