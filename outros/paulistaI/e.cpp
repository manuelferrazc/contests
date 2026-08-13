#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAX 100'100

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l = 0, int r = n-1) {
		lazy[p] = 1;
		if(l==r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p,l,m)+build(2*p+1,m+1,r);
	}
	void build(int n2, int *v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if(lazy[p]==1) return;
		if(l!=r) lazy[2*p] *= -1, lazy[2*p+1] *= -1;
		seg[p]*=-1;
		lazy[p] = 1;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p,l,r);
		if(a<=l and r<=b) return seg[p];
		if(b<l or r<a) return 0;
		int m = (l+r)/2;
		return query(a,b,2*p,l,m)+query(a,b,2*p+1,m+1,r);
	}

	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p,l,r);
		if(a<=l and r<=b) {
			lazy[p] *= x;
			prop(p,l,r);
			return seg[p];
		}
		if(b<l or r<a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a,b,x,2*p,l,m)+update(a,b,x,2*p+1,m+1,r);
	}

};

namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	int peso[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p=-1, int f=1) {
		v[pos[k]=t++] = peso[k]; sz[k] = 1;
		for(auto &i:g[k]) if(i!=p) {
			pai[i] = k;
			h[i] = (i==g[k][0] ? h[k] : i);
			build_hld(i,k,f);
			sz[k] += sz[i];

			if(sz[i] > sz[g[k][0]] or g[k][0]==p) swap(i,g[k][0]);
		}
		if(p*f == -1) build_hld(h[k] = k, -1,t=0);
	}
	void build(int root=0) {
		t=0;
		build_hld(root);
		seg::build(t,v);
	}
	void update_path(int a, int b, int x) {
		if(pos[a]<pos[b]) swap(a,b);
		if(h[a]==h[b]) return (void)seg::update(pos[b],pos[a],x);
		seg::update(pos[h[a]],pos[a],x); update_path(pai[h[a]],b,x);
	}
	ll query_subtree(int a) {
		return seg::query(pos[a],pos[a]+sz[a]-1);
	}
};

vector<pair<int,int>> g2[MAX];

void dfs(int v2, int p=-1, int val = 0) {
	hld::peso[v2] = val;
	for(auto [u,w]:g2[v2]) {
		if(p!=u) dfs(u,v2,w);
	}
}

int main() { _
	int n,q;
	cin >> n >> q;

	ll s=0;

	for(int i=1;i<n;i++) {
		int a,b,w;
		cin >> a >> b >> w;
		a--;b--;

		s+=w;
		hld::g[a].push_back(b);
		hld::g[b].push_back(a);

		g2[a].push_back({b,w});
		g2[b].push_back({a,w});
	}

	dfs(0);
	hld::build(0);

	while(q--) {
		int a,b;
		cin >> a >> b;
		a--;b--;

		hld::update_path(0,a,-1);
		hld::update_path(0,b,-1);

		cout << (s-hld::query_subtree(0))/2 << '\n';
	}

	exit(0);
}
