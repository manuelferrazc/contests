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

    /*
     * vertices 0,...,n-1 => pokémons
     * vértices n,...,2*n-1 => valores do 0-ésimo atributo
     * vértices 2*n,...,3*n-1 => valores do 1-ésimo atributo
     * vértices (j+1)*n,...,(j+2)*n-1 => valores do j-ésimo atributo
     */ 

    vector<pair<int,ll>> adj[n+n*m];

    int c[n];
    for(int i=0;i<n;i++) cin >> i[c];

    int a[n][m];
    vector<pair<int,int>> order[m];

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        cin >> a[i][j];
        order[j].push_back(pair(a[i][j],i));
    }

    for(int i=0;i<m;i++) sort(order[i].begin(),order[i].end());

    // for(int i=0;i<m;i++) {
    //     println("atributo {}",i);
    //     for(ull j = 0;j<order[i].size();j++) {
    //         print("({},{})  ",order[i][j].ff,order[i][j].ss);
    //     }
    //     println("");
    // }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            auto &v = order[j];

            auto it = lower_bound(v.begin(),v.end(),pair(a[i][j],i));
            int pos = it-v.begin();

            adj[i].push_back({(j+1)*n+pos,c[i]});
            adj[(j+1)*n+pos].push_back({i,0});
            
            if(pos) 
                adj[(j+1)*n+pos].push_back({(j+1)*n+pos-1,0});
            
            if(pos!=n-1) 
                adj[(j+1)*n+pos].push_back({(j+1)*n+pos+1,v[pos+1].ff-a[i][j]});
        }
    }
    
    // for(int i=0;i<n*(m+1);i++) {
    //     cout << i << '\n';
    //     for(auto [a,b]:adj[i]) print("({} {})  ",a,b);
    //     cout << '\n';
    // }
    
    using pli = pair<ll,int>;
    
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    
    ll dist[n+n*m];
    pq.push({0,n-1});
    for(int i=0;i<n+n*m;i++) dist[i] = LLONG_MAX;
    dist[n-1] = 0;
    
    while(not pq.empty() and true) {
        auto [w,v] = pq.top();
        // cout << v << " -> " << 2 << '\n';
        pq.pop();

        if(w!=dist[v]) continue;

        for(auto [u,c2]:adj[v]) {
            if(dist[u]>w+c2) {
                dist[u] = w+c2;
                pq.push({dist[u],u});
            }
        }
    }

    // for(auto x:dist) cout << x << ' ';
    // cout << '\n';

    cout << dist[0] << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
