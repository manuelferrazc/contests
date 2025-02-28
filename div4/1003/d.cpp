#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;

    vector<ll> v(m);
    vector<ll> sc;

    ll ans=0;

    for(int i=0;i<n;i++) {
        for(auto &j:v) cin >> j;

        ll score=0,acc=0;
        for(int j=0;j<m;j++) {
            acc+=v[j];
            score+=acc;
        }
        ans+=score;
        sc.push_back(acc*m);
    }

    sort(sc.begin(),sc.end());
    for(int i=0;i<n;i++) ans+=sc[i]*i;
    
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
