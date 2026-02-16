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

    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    int ans = 0;
    for(int i=1;i<n;i++) {
        if(v[i]==v[i-1] or v[i]+v[i-1]==7) {
            ans++;
            i++;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
