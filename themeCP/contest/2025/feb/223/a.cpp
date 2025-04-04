#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,k,q,i;
    cin >> n >> k >> q;

    ll c=0,s=0,ans=0;
    for(ll a=0;a<n;a++) {
        cin >> i;
        if(i>q) {
            ans+=s;
            s=c=0;
            continue;
        }
        c++;
        if(c>=k) s+=c-k+1;
    }

    if(s)ans+=s;
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
