#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n, ans=0,acc=0;
    cin >> n;

    vector<ll> v(n);
    for(ll &i:v) {
        cin >> i >> acc;
        ans+=acc;
    }

    acc=0;
    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++) {
        acc+=v[i];
        ans-=acc;
    }

    cout << ans << '\n';

    return 0;
}
