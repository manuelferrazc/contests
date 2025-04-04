#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

set<ll> s;

bool check(ll n) {
    ll l=2,r=1'000'000'000LL;

    while(l<=r) {
        ll m = (l+r)>>1LL;
        ll c = 1LL+m+m*m;
        if(c==n) return true;
        else if(c<n) l = m+1;
        else r=m-1;
    }
    return false;
}

void solve() {
    ll n;
    cin >> n;

    if(s.count(n) or check(n)) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    for(ll k=2;k<=1'000'000;k++) {
        ll sum = 1+k+k*k,p=k*k;
        ll lim = 1'000'000'000'000'000'000LL;
        while(sum<lim and k<=(lim-sum)/p) {
            p*=k;
            sum+=p;
            s.insert(sum);
        }
    }
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}