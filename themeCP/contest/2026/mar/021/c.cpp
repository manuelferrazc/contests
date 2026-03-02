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

    int k[n];
    ll lc = 1;
    for(int i=0;i<n;i++) {
        cin >> k[i];
        lc = lcm(lc,k[i]);
    }

    ll sol[n];
    ll s=0;
    for(int i=0;i<n;i++) {
        sol[i] = lc/k[i];
        s+=sol[i];
    }

    for(int i=0;i<n;i++) {
        if(sol[i]*k[i]<=s) {
            cout << -1 << '\n';
            return;
        }
    }

    for(int i=0;i<n;i++) cout << sol[i] << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
