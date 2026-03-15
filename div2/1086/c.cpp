#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

using ld = long double;

void solve() {
    int n;
    cin >> n;

    pair<int,int> v[n];
    for(int i=n-1;i>=0;i--) cin >> v[i].ff >> v[i].ss;

    ld ans = v[0].ff;

    for(int i=1;i<n;i++) {
        ld cansado = 1-((ld)(v[i].ss))/(ld)100;

        ans = max(ans,cansado*ans+v[i].ff);
    }

    cout << fixed << setprecision(13) << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
