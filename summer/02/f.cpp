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

    vector<int> adj[n];
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(n<3) {
        cout << n << '\n';
        for(int i=1;i<=n;i++) cout << i << ' ' << 0 << '\n';
        return;
    }

    queue<int> q;

    int dist[n];
    int qtd[n];
    for(int i=0;i<n;i++) {
        if(adj[i].size()==1) {
            q.push(i);
            dist[i] = 0;
        } else {
            qtd[i] = adj[i].size();
            dist[i] = INT_MAX;
        }
    }

    while(q.empty()==false) {
        int v = q.front();
        q.pop();

        for(auto u:adj[v]) {
            if(dist[u]!=INT_MAX) continue;

            qtd[u]--;
            if(qtd[u]==1) {
                dist[u] = dist[v]+1;
                q.push(u);
            }
        }
    }

    int mx = -1,v1=-1,v2=-1;
    for(int i=0;i<n;i++) {
        if(dist[i]>mx) {
            mx = dist[i];
            v1 = i;
            v2 = -1;
        } else if(dist[i]==mx) v2 = i;
    }

    v1++;
    if(v2==-1) {
        cout << mx+1 << '\n';
        for(int i=0;i<=mx;i++) cout << v1 << ' ' << i << '\n';
    } else if(mx&1) {
        v2++;
        cout << mx+1 << '\n';
        for(int i=1;i<=mx;i+=2) {
            cout << v1 << ' ' << i << '\n';
            cout << v2 << ' ' << i << '\n';
        }
    } else {
        v2++;
        cout << mx+2 << '\n';
        for(int i=1;i<=mx+1;i+=2) {
            cout << v1 << ' ' << i << '\n';
            cout << v2 << ' ' << i << '\n';
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
