#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int n,m;
	cin >> n >> m;

	vector<ll> dist(n,LLONG_MAX);
	dist[0] = 0;
	vector<vector<pair<int,ll>>> adj(n);

	while(m--) {
		int a,b;
		ll c;
		cin >> a >> b >> c;
		a--;
		b--;

		adj[a].push_back(make_pair(b,c));
	}
	
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push(make_pair(0LL,0));
	
	while(not pq.empty()) {
		auto [c,v] = pq.top();
		pq.pop();
		
		if(dist[v]<c) continue;
		
		for(auto [u,w]:adj[v]) {
			if(dist[v]+w<dist[u]) {
				dist[u] = dist[v]+w;
				pq.push(make_pair(dist[u],u));
			}
		}
	}
	
	for(ll i:dist) cout << i << ' ';
	cout << '\n';

	return 0;
}
