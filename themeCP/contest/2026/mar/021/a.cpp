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
    int mx=0,q=0;

    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(v[i]>mx) {
            mx = v[i];
            q=1;
        } else if(v[i]==mx) q++;
    }

    if(q==n) {
        cout << -1 << '\n';
        return;
    }

    vector<int> b,c;

    for(int i=0;i<n;i++) {
        if(v[i]==mx) c.push_back(v[i]);
        else b.push_back(v[i]);
    }

    cout << b.size() << ' ' << c.size() << '\n';

    for(int i:b) cout << i << ' ';
    cout << '\n';

    for(int i:c) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
