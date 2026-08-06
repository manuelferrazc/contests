#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
#define int ll
typedef long long ll;

ll n,k;
ll dist[1001];
vector<pair<ll,ll>> adj[1001];

void dfs(int v) {
	for(auto [u,w]:adj[v]) {
		if(dist[u]==LLONG_MAX) {
			dist[u] = dist[v]+w;
			dfs(u);
		}
	}
}

ll dfs(int v, int tg, int p=-1) {
	if(v==tg) return dist[tg];

	ll r=-1;
	for(auto [u,w]:adj[v]) {
		if(u==p) continue;
		ll x= dfs(u,tg,v);
		if(x==-1) continue;

		r = min(x,max(dist[v],dist[tg]-dist[v]));
//		cout << "(" << v+1 << "," << dist[v] << "," << dist[tg]-dist[v] << ")   ";
		break;
	}
	
	return r;
}

ll dmax(int v, int p, bool diam = false) {
//	cout << "\n\n\n";
//	cout << v+1 << ' ' << p+1 << '\n';
	fill(dist,dist+n+1,LLONG_MAX);
	dist[v] = 0;
	dist[p] = 0;
//	cout << v+1 << '\n';
	dfs(v);
//	for(int i=0;i<n;i++) cout << dist[i] << ' ';
//	cout << '\n';
	int v2 = v;
	for(int i=0;i<n;i++) if(dist[i]!=LLONG_MAX and dist[v2]<dist[i]) v2 = i;
	if(v2==v) return 0;

	fill(dist,dist+n+1,LLONG_MAX);
	dist[p] = 0;
	dist[v2] = 0;
	dfs(v2);
//	cout << v2+1 << '\n';
//	for(int i=0;i<n;i++) cout << dist[i] << ' ';
//	cout << '\n';
	int v3 = v2;
	for(int i=0;i<n;i++) if(dist[i]!=LLONG_MAX and dist[i]>dist[v3]) v3 = i;
	if(diam) return dist[v3];
//	cout << v3+1 << '\n';
	int x = dfs(v2,v3);
//	cout << x << '\n';
	return x;
}

signed main() { _
	cin >> n >> k;

	vector<pair<int,int>> e;
	for(int i=1;i<n;i++) {
		ll a,b,w;
		cin >> a >> b >> w;
		a--;b--;
		w = min(w,k);
		adj[a].push_back(pair(b,w));
		adj[b].push_back(pair(a,w));
		e.push_back(pair(a,b));
	}
	
	ll ans = min(2*k,dmax(0,1000,true));
//	cout << ans << '\n';
	//return 0;
	for(auto [a,b]:e) {
		ans = min(
			ans,
			k + dmax(a,b) + dmax(b,a)
		);
		//cout << "a,b = " << a << ' ' << b << ", dmax(a,b),dmax = " << dmax(a,b) << ' ' << dmax(b,a) << '\n'; 
	}

	cout << ans << '\n';

	return 0;
}
