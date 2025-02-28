#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
 
 
int main() { _
    ll n,s;
    cin >> n >> s;
    vector<ll> v(n), sp(n+1);
    sp[0]=0;
    for(ll i=0;i<n;i++) {
        cin >> v[i];
        sp[i+1] = sp[i]+v[i];
    }
 
    ll ans=0, l=0,r=1;
    while(r<=n) {
        if(l>=r) r++;
        else {
            if(sp[r]-sp[l]<=s) {
                ans+=(r-l+1)*(r-l)/2;
                r++;
            } else l++;
        }
    }
 
    cout << ans << '\n';
 
    return 0;
}