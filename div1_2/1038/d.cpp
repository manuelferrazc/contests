#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> act(n,INT_MAX),next(n,INT_MAX);
    act[0] = 0;

    for(int t=0;;t++) {
        if(act.back()!=INT_MAX) {
            cout << t << ' ' << act.back() << '\n';
            return;
        }
        for(int i=0;i<n;i++) {
            if(act[i]==INT_MAX) continue;
            next[i] = min(next[i],act[i]+1);
            
            int &x = next[adj[i][t%adj[i].size()]];
            x = min(x,act[i]);
        }
        for(int i=0;i<n;i++) {
            act[i] = next[i];
            next[i] = INT_MAX;
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
