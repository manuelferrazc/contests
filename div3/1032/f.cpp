#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,s,x,ans=0,sum=0,mx=LLONG_MIN;
    cin >> n >> s >> x;

    map<ll,ll> m,m2;
    m[0] = 1;

    for(ll i=0;i<n;i++) {
        ll a;
        cin >> a;
        if(a>x) {
            m.clear();
            m[0] = 1;
            m2.clear();
            sum = 0;
            mx = LLONG_MIN;
        } else {
            if(a==x) {
                for(auto [p,q]:m) m2[p]+=q;
                m.clear();
            }
            sum+=a;
            mx = max(mx,a);
            if(mx==x and m2.count(sum-s)) ans+=m2[sum-s];
            m[sum]++;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
