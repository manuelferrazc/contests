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

    ll v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    int ans[n];
    ans[0] = 1;

    int x = 2;
    for(int i=1;i<n;i++) {
        int qe = v[i]-v[i-1]-1;
        // cout << qe << ' ';
        if(qe==i) {
            ans[i] = x;
            x++;
        } else {

            ans[i] = ans[i-qe-1];
        }
    }
    // cout << '\n';

    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    // t=1;
    while(t--) solve();
    return 0;
}
