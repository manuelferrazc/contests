#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n+1,0),acc(n+1,0);
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        v[x]++;
    }
    acc[0] = v[0];
    for(int i=1;i<n;i++) acc[i] = acc[i-1]+v[i];

    int i,r=0;
    for(i=0;i<n;i++) {
        if(v[i]==0) break;
        else r+=v[i]-1;
    }

    cout << 1 << ' ';
    for(int k=1;k<=n;k++) {
        auto it = partition_point(acc.begin(),acc.end(),[&](int itt) ->bool {
            return itt<=k;
        });

        if(k<=r) cout << i << ' ';
        else cout << max(1,i-(k-r)) << ' ';
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
