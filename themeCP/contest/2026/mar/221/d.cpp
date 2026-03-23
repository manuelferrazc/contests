#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m,k,w;
    cin >> n >> m >> k >> w;

    int v[w];
    for(int i=0;i<w;i++) cin >> v[i];
    sort(v,v+w);

    priority_queue<ll> qtd;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int vert = max(i-k+1,0);
            int endv = min(i+k-1,n-1) - k+1;
            vert = endv-vert+1;

            int hor = max(j-k+1,0);
            int endh = min(j+k-1,m-1) - k+1;
            hor = endh-hor+1;

            qtd.push(vert*hor);
        }
    }

    ll ans = 0;
    for(int i=w-1;i>=0;i--) {
        ans+=v[i]*qtd.top();
        qtd.pop();
    }
    
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
