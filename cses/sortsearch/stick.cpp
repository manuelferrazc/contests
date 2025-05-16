#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll calc(vector<ll> &v, ll x) {
    ll r=0;
    for(ull i=0;i<v.size();i++) r+=abs(v[i]-x);
    return r;
}

int main() { _
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    sort(v.begin(),v.end());

    
    cout << min(calc(v,v[n/2]),calc(v,v[n/2+1])) << '\n'; 

    return 0;
}
