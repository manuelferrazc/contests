#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 100000
#define MAX2 17

vector<vector<int> > g(MAX);
int n, p;
int pai[MAX2][MAX];
int in[MAX], out[MAX];

void dfs(int k) {
	in[k] = p++;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (in[g[k][i]] == -1) {
			pai[0][g[k][i]] = k;
			dfs(g[k][i]);
		}
	out[k] = p++;
}

void build(int raiz) {
	for (int i = 0; i < n; i++) pai[0][i] = i;
	p = 0, memset(in, -1, sizeof in);
	dfs(raiz);

	// pd dos pais
	for (int k = 1; k < MAX2; k++) for (int i = 0; i < n; i++)
		pai[k][i] = pai[k - 1][pai[k - 1][i]];
}

bool anc(int a, int b) { // se a eh ancestral de b
	return in[a] <= in[b] and out[a] >= out[b];
}

int lca(int a, int b) {
	if (anc(a, b)) return a;
	if (anc(b, a)) return b;

	// sobe a
	for (int k = MAX2 - 1; k >= 0; k--)
		if (!anc(pai[k][a], b)) a = pai[k][a];

	return pai[0][a];
}



namespace perseg {
	const int MAX1 = 2e5+10, UPD = 1e5+10, LOG = 18;
	const int MAXS = 2*MAX1+UPD*LOG;
	ll seg[MAXS];
	int rt[UPD], L[MAXS], R[MAXS], cnt, t;
	int n;

	ll build(int p, int l, int r) {
		if (l == r) return seg[p] = 0;
		L[p] = cnt++, R[p] = cnt++;
		int m = (l+r)/2;
		return seg[p] = build(L[p], l, m) + build(R[p], m+1, r);
	}
	void build(int n2) {
		n = n2;
		rt[0] = cnt++;
		build(0, 0, n-1);
	}
	ll query(int a, int b, int p, int l, int r) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, L[p], l, m) + query(a, b, R[p], m+1, r);
	}
	ll query(int a, int b, int tt) {
		return query(a, b, rt[tt], 0, n-1);
	}
	ll update(int a, int x, int lp, int p, int l, int r) {
		if (l == r) return seg[p] = seg[lp]+x;
		int m = (l+r)/2;
		if (a <= m)
			return seg[p] = update(a, x, L[lp], L[p]=cnt++, l, m) + seg[R[p]=R[lp]];
		return seg[p] = seg[L[p]=L[lp]] + update(a, x, R[lp], R[p]=cnt++, m+1, r);
	}
	int update(int a, int x, int tt=t) {
		update(a, x, rt[tt], rt[++t]=cnt++, 0, n-1);
		return t;
	}
};

int lx = 0;

void dfs2(vector<int> &in2, vector<int> &out2, int v, int pr=-1) {
	in2[v] = lx++;

	for(int u:g[v]) {
		if(u==pr) continue;

		dfs2(in2,out2,u,v);
	}

	out2[v] = lx++;
}

int main() { 
    int q;
	cin >> n >> q;

	vector<pair<int,int>> w(n);
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		w[i] = {x,i};
	}

	sort(w.begin(),w.end());

	for(int i=1;i<n;i++) {
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	build(0);

	perseg::build(2*n);
	
	vector<int> inn(n),outt(n);
	dfs2(inn,outt,0);
	
	for(auto [p,v]:w) {
		perseg::update(inn[v],p);
		perseg::update(outt[v],-p);
	}

    
    return 0;
}
