#include <algorithm>
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
    sort(v.begin(),v.end());

    ll ans=n-2,l=0;

    for(ll r=2;r<n;) {
        if(l==r-1) r++;
        else if(v[l]+v[l+1]>v[r]) {
            ans=min(ans,n-r+l-1);
            r++;
        } else l++;
    }
    cout << ans << '\n';
}

int main() { 
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}