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

    vector<set<int>> adj(n+2);
    for(int i=1;i<=n-1;i++) adj[i].insert(i+1);

    for(int i=1;i<=n;i++) {
        int x;
        cin >> x;
        if(x) adj[n+1].insert(i);
        else adj[i].insert(n+1);
    }

    if(adj[n].count(n+1)) {
        for(int i=1;i<=n+1;i++) cout << i << ' ';
        cout << '\n';
    } else if(adj[n+1].count(1)) {
        cout << n+1 << ' ';
        for(int i=1;i<=n;i++) cout << i << ' ';
        cout << '\n';
    } else {
        for(int i=1;i<n;i++) {
            if(adj[i].count(n+1) and adj[n+1].count(i+1)) {
                for(int j=1;j<=i;j++) cout << j << ' ';
                cout << n+1 << ' ';
                for(int j=i+1;j<=n;j++) cout << j << ' ';
                cout << '\n';
                return;
            }
        }
        cout << -1 << '\n'; 
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
