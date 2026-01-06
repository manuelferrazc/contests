#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;

template<typename t>
void set_val(t *v, int n, t x) {
	for(int i=0;i<n;i++) v[i] = x;
}

int main() { _
    int n,m;
	cin >> n >> m;

	vector<pair<int,int>> adj[n];
	while(m--) {
		int a,b,c;
		cin >> a >> b >> c;
		adj[a-1].push_back(pair(b-1,c));
	}

	int qtd[n];
	int mi[n];
	int ma[n];
	ll dist[n];
	
	set_val(qtd,n,0);
	set_val(mi,n,0);
	set_val(ma,n,0);
	set_val(dist,n,LLONG_MAX);
	
	qtd[0] = 1;
	mi[0] = ma[0] = dist[0] = 0;

	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push({0,0});

	while(not pq.empty()) {
		auto [d,v] = pq.top();
		pq.pop();

		if(d>dist[v]) continue;

		for(auto [u,w]:adj[v]) {
			if(dist[u]>dist[v]+w) {
				mi[u] = mi[v]+1;
				ma[u] = ma[v]+1;
				qtd[u] = qtd[v];
				dist[u] = dist[v]+w;
				pq.push({dist[u],u});
			} else if(dist[u]==dist[v]+w) {
				mi[u] = min(mi[u],mi[v]+1);
				ma[u] = max(ma[u],ma[v]+1);
				qtd[u] = (qtd[u]+qtd[v])%mod;
			}
		}
	}

	cout << dist[n-1] << ' ' << qtd[n-1] << ' ' << mi[n-1] << ' ' << ma[n-1] << '\n';

	return 0;
}
