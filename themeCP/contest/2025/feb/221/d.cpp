#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,c,d;
vector<ll> q;

bool check(ll k) {
    ll s=0,qtd=d;
    for(ll i=0;i<min(d,n);i++) {
        s+=q[i]*(min(d/(k+1),qtd));
        qtd-=d/(k+1);
        if(qtd>0 and d%(k+1)>i) {s+=q[i];qtd--;}
        if(s>=c) return true;
        if(qtd<=0) return false;
    }
    return false;
}

void solve() {
    cin >> n >> c >> d;
    q.resize(n);
    for(auto &i:q) cin >> i;
    sort(q.rbegin(),q.rend());
    ll s=0;
    for(ll i=0;i<min(n,d);i++) s+=q[i];
    if(s>=c) {
        cout << "Infinity\n";
        return;
    }
    s=q[0]*d;
    if(s<c) {
        cout << "Impossible\n";
        return;
    }

    ll l=0,r=10'000'000'000'000'000, ans=LLONG_MIN;
    while(l<=r) {
        ll m = (l+r)>>1;
        if(check(m)) {
            ans = max(ans,m);
            l=m+1;
        } else r=m-1;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
