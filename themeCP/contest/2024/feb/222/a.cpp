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
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    for(int i=0;i<n;i++) {
        vector<bool> vis(n,false);
        int u = i;
        while(true) {
            if(vis[u]) {
                cout << u+1 << ' ';
                break;
            }
            vis[u] = true;
            u = v[u]-1;
        }
    }

    cout << '\n';
}

int main() { _
    solve();
    return 0;
}
