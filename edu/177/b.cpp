#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll sum;
ll n,k,x;
vector<ll> v;

bool bb(ll i) {
    ll q = sum*(i/n);
    if(i%n) q+=accumulate(v.begin(),v.begin()+i%n,0LL);
    return q>=x;
}

void solve() {
    cin >> n >> k >> x;
    v.resize(n);
    for(ll &i:v) cin >> i;
    // reverse(v.begin(),v.end());
    sum = accumulate(v.begin(),v.end(),0LL);
    
    ll l=0,r=n*k,ans=0;
    while(l<=r) {
        ll m = (l+r)/2;
        if(bb(m)) {
            ans = m;
            r=m-1;
        } else l=m+1;
    }

    // if(bb(0)) cout << "ababa ";

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
