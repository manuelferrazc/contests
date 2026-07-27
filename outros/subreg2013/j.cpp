#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 20'000
#define MAX2 16

vector<vector<int>> g(MAX);
int n, p;
int pai[MAX2][MAX];
int mp[MAX2][MAX];
int in[MAX], out[MAX];

void dfs(int k) {
	in[k] = p++;
	for(int i=0;i<(int)g[k].size();i++) {
		if(in[g[k][i]]==-1) {
			pai[0][g[k][i]] = k;
			dfs(g[k][i]);
		}
	}
	out[k] = p++;
}

void build(int raiz=0) {
	for(int i=0;i<n;i++) pai[0][i] = i;
	p=0,memset(in,-1,sizeof in);
	dfs(raiz);

	for(int k=1;k<MAX2;k++) for(int i=0;i<n;i++)
		pai[k][i] = pai[k-1][pai[k-1][i]];
}

bool anc(int a, int b) {
	return in[a]<=in[b] and out[a]>=out[b];
}

int lca(int a, int b) {
	if(anc(a,b)) return a;
	if(anc(b,a)) return b;

	for(int k=MAX2-1;k>=0;k--) 
		if(not anc(pai[k][a],b)) a= pai[k][a];
	return pai[0][a];
}

void dfs2(vector<pair<int,int>> *adj,int v,int pp=-1,int w = -1) {
	mp[0][v] = w;
	for(int j=1;j<MAX2;j++) {
		if(mp[j-1][pai[j-1][v]]!=-1) mp[j][v] = min(mp[j-1][v],mp[j-1][pai[j-1][v]]);
		else mp[j][v] = mp[j-1][v];
	}

	for(auto [u,w2]:adj[v])
		if(u!=pp) dfs2(adj,u,v,w2);
}


int p2[MAX];
int r[MAX];

int get(int a) {
	return p2[a] = (p2[a]==a? a : get(p2[a]));
}

bool unir(int a, int b) {
	a = get(a);
	b = get(b);

	if(a==b) return false;
	if(r[b]>r[a]) swap(a,b);
	if(r[b]==r[a]) r[a]++;
	p2[b] = a;

	return true;
}

int main() { _
	int m,s;
	cin >> n >> m >> s;

	for(int i=0;i<n;i++) p2[i] = i;
	for(int i=0;i<n;i++) r[i] = 1;

	priority_queue<array<int,3>> pq;

	for(int i=0;i<m;i++) {
		int a,b,w;
		cin >> a >> b >> w;
		a--;
		b--;
		pq.push({w,a,b});
	}

	vector<pair<int,int>> adj[n];

	while(pq.size()) {
		auto [w,a,b] = pq.top();
		pq.pop();

		if(unir(a,b)) {
			g[a].push_back(b);
			g[b].push_back(a);

			adj[a].push_back(pair(b,w));
			adj[b].push_back(pair(a,w));
			// cout << "arestas " << a << ' ' << b << '\n';
		}
	}

	build();
	dfs2(adj,0);

	//for(int i=0;i<n;i++) {
	//	cout << "i = " << i << '\n';
	//	for(int j=0;j<4;j++) cout << "(" << pai[j][i] << ',' << mp[j][i] << "), ";
	//	cout << '\n';
	//}

	while(s--) {
		int l,h;
		cin >> l >> h;
		l--;
		h--;

		int lc = lca(l,h);
		int ans = INT_MAX;
		
		for(int k=MAX2-1;k>=0;k--) {
			if(anc(lc,pai[k][l])) {
				if(mp[k][l]!=-1) ans = min(ans,mp[k][l]);
				l = pai[k][l];
			}

			if(anc(lc,pai[k][h])) {
				if(mp[k][h]!=-1) ans = min(ans,mp[k][h]);
				h = pai[k][h];
			}
		}
		//cout << l << ' ' << h << ' ' << lc << ' ';
		cout << ans << '\n';

	}

	return 0;
}
