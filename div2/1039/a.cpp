#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,c,ans=0;
    cin >> n >> c;
    vector<ll> v(n);

    for(ll i=0;i<n;i++) cin >> v[i];

    while(v.size()) {
        sort(v.begin(),v.end());
        auto it = upper_bound(v.begin(),v.end(),c);
        if(it==v.begin()) {
            ans+=v.size();
            break;
        }

        it--;
        swap(*it,v.back());
        v.pop_back();
        for(ll &i:v) i+=i;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
