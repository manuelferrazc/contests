#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
vector<int> adj[200'000];

pair<int,int> bfs(int v) {
    int l;

    queue<int> q;
    q.push(v);

    int dist[n];
    for(int i=0;i<n;i++) dist[i] = INT_MAX;
    dist[v] = 0;

    while(not q.empty()) {
        l = q.front();
        q.pop();

        for(auto u:adj[l]) {
            if(dist[u]==INT_MAX)  {
                dist[u] = dist[l]+1;
                q.push(u);
            }
        }
    }

    return pair(l,dist[l]);
}

int main() { _
    cin >> n;

    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int s = bfs(0).ff;

    cout << bfs(s).ss << '\n';

    return 0;
}
