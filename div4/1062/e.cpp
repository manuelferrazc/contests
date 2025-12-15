#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,k,x;
ll ans[200'000];
ll v[200'000];

bool copy(vector<int> &p) {
    for(int i=0;i<k;i++) ans[i] = p[i];
    return true;
}

bool ok(ll m) {
    ll mx = -1;
    vector<int> pos;

    for(int i=0;v[0]-i>=m;i++) {
        pos.push_back(i);
        mx = i;
        if(pos.size()==k) return copy(pos);
    }

    for(int i=1;i<n;i++) {
        for(int j=max(v[i-1]+m,mx+1);j<=v[i]-m;j++) {
            pos.push_back(j);
            mx = j;
            if(pos.size()==k) return copy(pos);
        }
    }

    for(int i=x;i-v[n-1]>=m and i>mx;i--) {
        pos.push_back(i);
        if(pos.size()==k) return copy(pos);
    }

    return false;
}

void solve() {
    cin >> n >> k >> x;

    for(int i=0;i<n;i++) cin >> i[v];
    sort(v,v+n);

    ll l = 0, r = x;
    while(l<=r) {
        ll m = (l+r)>>1;
        if(ok(m)) l=m+1;
        else r=m-1;
    }

    for(int i=0;i<k;i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
