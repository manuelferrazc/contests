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
        }
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push(pair(0,0));

    int dist[n];
    for(int &i:dist) i=INT_MAX;
    dist[0] = 0;

    int k;
    cin >> k;
    map<int,vector<int>> m;
    for(int i=0;i<k;i++) {
        int x;
        cin >> x;
        m[x-1].push_back(i);
    }

    // int ans = INT_MAX;
    while(not pq.empty()) {
        auto [tr,u] = pq.top();
        pq.pop();
        
        if(dist[u]<tr) continue;
        
        /*
         * ff -> momento do tempo que a aresta tá viva
         * ss -> pra quais vertices essas arestas vão
         */
        for(auto it = adj[u].begin();it!=adj[u].end();it++) {
            // se a maquina nunca leva pra esse momento, ele é inútil 
            if(m.count(it->ff)==0) continue;

            // it2 -> memor número de viagens que preciso pra chegar em it->ff, dado que estou na tr-esima viagem
            auto it2 = lower_bound(m[it->ff].begin(),m[it->ff].end(),tr);
            if(it2==m[it->ff].end()) continue;

            for(auto v:it->ss) {
                if(dist[v]>*it2+1) {
                    dist[v] = *it2+1;

                    // if(v==n-1) ans = min(ans,tr+1);
                    pq.push(pair(dist[v],v));
                }
            }
        }

    }

    if(dist[n-1]==INT_MAX) cout << -1 << '\n';
    else cout << dist[n-1] << '\n';

    return 0;
}
