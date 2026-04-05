#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int v[7];
    for(int i=0;i<7;i++) cin >> i[v];

    sort(v,v+7);

    int ans = v[6];
    for(int i=0;i<6;i++) ans-=v[i];

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
