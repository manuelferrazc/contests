#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k,ans=0;
    cin >> n >> k;

    map<int,int> m;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        m[x]++;
    }

    for(int i=0;i<k;i++) if(not m.count(i)) ans++;

    if(m.count(k)) ans+=max(0,m[k]-ans);

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
