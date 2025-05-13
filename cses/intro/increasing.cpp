#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    ll n,ans=0;
    cin >> n;

    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    for(ll i=1;i<n;i++) {
        if(v[i]<v[i-1]) {
            ans+=v[i-1]-v[i];
            v[i] = v[i-1];
        }
    }

    cout << ans << '\n';
    
    return 0;
}
