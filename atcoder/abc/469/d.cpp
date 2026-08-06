#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

pair<int,int> st[800'004];

pair<int,int> add(int p, int l, int r, int i, int x) {
	if(i<l or r<i) return st[p];
	if(l==r) {
		st[p].ff += x;
		st[p].ss = 1;
		return st[p];
	}

	int m = (l+r)/2;
	auto lp = add(2*p,l,m,i,x);
	auto rp = add(2*p+1,m+1,r,i,x);

	if(lp.ff==rp.ff) st[p] = pair(lp.ff,lp.ss+rp.ss);
	else st[p] = max(lp,rp);
	return st[p];
}

pair<int,int> get(int p, int l, int r, int lq, int rq) {
	if(rq<l or r<lq) return pair(INT_MIN,-1);
	if(lq<=l and r<=rq) return st[p];
	int m = (l+r)/2;
	auto lp = get(2*p,l,m,lq,rq);
	auto rp = get(2*p+1,m+1,r,lq,rq);

	if(lp.ff==rp.ff) return pair(lp.ff,lp.ss+rp.ss);
	else return max(lp,rp);
}


int main() { _
	int n,m;
	cin >> n >> m;

	set<int> adj[n];
	for(int i=0;i<m;i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	
	m = 0;
	for(int i=0;i<n;i++) {
		m+=adj[i].size();
		add(1,0,n-1,i,adj[i].size());
	}

	m/=2;

	ll ans = 0;
	for(int i=0;i<n-1;i++) {
		for(int j:adj[i]) add(1,0,n-1,j,-1);
		auto x = get(1,0,n-1,i+1,n-1);
		if(x.ff == m-adj[i].size()) ans += x.ss;
		for(int j:adj[i]) add(1,0,n-1,j,1);
	}

	cout << ans << '\n';

    return 0;
}
