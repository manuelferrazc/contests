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
    ll init = 0;
    
    int v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    for(int i=1;i<n;i++) init+=abs(v[i]-v[i-1]);

    ll ans = init-max(abs(v[0]-v[1]),abs(v[n-2]-v[n-1]));

    for(int i=1;i<n-1;i++) 
        ans = min(ans,init-abs(v[i-1]-v[i])-abs(v[i]-v[i+1])+abs(v[i-1]-v[i+1]));
    

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
