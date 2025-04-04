#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<ull> v(n);
    for(auto &i:v) cin >> i;
    v.push_back(0);

    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++) v[i]+=v[i-1];

    ull ans=0;
    for(int i=0;i<=k;i++) {
        ans=max(ans,v[n]-(v[n]-v[n-i])-v[2*(k-i)]);
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
