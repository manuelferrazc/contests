#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,t;
    cin >> n >> t;

    map<int,vector<int>> adj[n];
    vector<int> v[n];

    for(int i=0;i<t;i++) {
        int q;
        cin >> q;

        int a,b;
        while(q--) {
            cin >> a >> b;
            a--;
            b--;

            adj[a][i].push_back(b);
            adj[b][i].push_back(a);

            if(v[a].empty() or v[a].back()!=i) v[a].push_back(i);
        }
    }

    for(int i=0;i<n;i++) {
        cout << i << ": ";
        for(auto a:v[i]) cout << a << ' ';
        cout << '\n';
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push(pair(0,0));

    int dist[n];
    for(int &i:dist) i=INT_MAX;
    dist[0] = 0;

    int k;
    cin >> k;
    int m[k];
    for(int i=0;i<k;i++) {
        cin >> m[i];
        m[i]--;
    }

    while(not pq.empty()) {
        auto [tr,u] = pq.top();
        pq.pop();

        if(dist[u]<tr) continue;

        auto it = lower_bound(v[u].begin(),v[u].end(),tr);

        for(;it!=v[u].end();it++) {
            cout << u << ' ' << m[*it] << ": \n";
            for(auto u2:adj[u][m[*it]]) {
                cout << u2 << ' ';
                if(dist[u2]>*it+1) {
                    cout << "sim\n";
                    dist[u2] = *it+1;
                    pq.push(pair(*it+1,u2));
                }
                else cout << "não\n";
            }
        }
    }

    // for(int i=0;i<n;i++) cout << i << ' ' << dist[i] << '\n';

    if(dist[n-1]==INT_MAX) cout << -1 << '\n';
    else cout << dist[n-1]-1 << '\n';

    return 0;
}
