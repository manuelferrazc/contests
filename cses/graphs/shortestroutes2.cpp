#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m,q;

void djks(vector<vector<ll>> &adj, vector<ll> &dist, int o) {
	dist[o] = 0;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push(make_pair(0LL,o));
	
	while(not pq.empty()) {
		auto [c,v] = pq.top();
		pq.pop();
		
		if(dist[v]<c) continue;
		
		for(int u=0;u<n;u++) {
			ll w = adj[v][u];
			if(w!=LLONG_MAX and dist[v]+w<dist[u]) {
				dist[u] = dist[v]+w;
				pq.push(make_pair(dist[u],u));
			}
		}
	}
}

int main() { _
	cin >> n >> m >> q;

	vector<vector<ll>> dist(n,vector<ll>(n,LLONG_MAX));
	vector<vector<ll>> adj(n,vector<ll>(n,LLONG_MAX));

	while(m--) {
		int a,b;
		ll c;
		cin >> a >> b >> c;
		a--;
		b--;

		adj[a][b] = min(adj[a][b],c);
		adj[b][a] = min(adj[b][a],c);
	}
	
	for(int i=0;i<n;i++) djks(adj,dist[i],i);	
	
	while(q--) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;

		if(dist[a][b]==LLONG_MAX) cout << -1 << '\n';
		else cout << dist[a][b] << '\n';
	}

	return 0;
}
