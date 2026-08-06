#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;

const int mod = 998244353;

ll fexp(ll n,ll e) {
	ll r = 1;
	while(e) {
		if(e&1) r = (r*n)%mod;
		e>>=1;
		n = n*n%mod;
	}
	return r;
}

int main() { _
	int n;
	cin >> n;

	int v[n+1];
	for(int i=0;i<n;i++) cin >> v[i+1];

	ll ans = 0;

	for(int k=0;k<n;k++) {
		vector<int> adj(2*n+1,-1);
		for(int i=1;i<=n;i++) adj[i] = v[i]+k;

		vector<bool> color(2*n+1,0);
		int qtd=0;

		auto dfs = [&](this auto self,int u) -> bool {
			if(color[u]) return true;
			color[u] = true;
			if(adj[u]<0) return false;
			return self(adj[u]);
		};

		for(int i=1;i<=n;i++) if(color[i]==false) qtd+=dfs(i);
		
		ans += fexp(2,qtd)-1;
	}

	cout << ans%mod << '\n';

	return 0;
}
