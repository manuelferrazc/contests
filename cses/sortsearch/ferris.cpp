#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,x,ans=0;
    cin >> n >> x;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    sort(v.begin(),v.end());

    ll a=0,b=n-1;

    while(a<b) {
        if(v[a]+v[b]<=x) a++;
        b--;
        ans++;
    }

    if(a==b) ans++;

    cout << ans << '\n';
    return 0;
}
