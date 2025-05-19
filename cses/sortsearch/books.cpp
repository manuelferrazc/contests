#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,s=0;
    cin >> n;

    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    sort(v.rbegin(),v.rend());

    for(ll i=1;i<n;i++) s+=v[i];

    if(s>v[0]) cout << s+v[0] << '\n';
    else cout << (v[0]<<1) << '\n';

    return 0;
}
