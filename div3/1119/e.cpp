#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct sat {
	int n,tot;
	vector<vector<int>> g;
	vector<int> vis,comp,id,ans;
	stack<int> s;
	
	sat() {}
	sat(int n_) : n(n_), tot(n), g(2*n) {}

	int dfs(int i, int &t) {
		int lo = id[i] = t++;
		s.push(i), vis[i] = 2;
		for(int j:g[i]) {
			if(!vis[j]) lo = min(lo,dfs(j,t));
			else if(vis[j]==2) lo = min(lo,id[j]);
		}
		if(lo==id[i]) while(1) {
			int u = s.top();s.pop();
			vis[u] = 1;
			comp[u] = i;
			if ((u>>1)<n and ans[u>>1]==-1) ans[u>>1] = ~u&1;
			if(u==i) break;
		}
		return lo;
	}

	void add_impl(int x, int y) {
		x = x>=0 ? 2*x : -2*x-1;
		y = y>=0 ? 2*y : -2*y-1;
		//cout << g.size() << ' ' << x << ' ' << y << '\n';
		g[x].push_back(y);
		g[y^1].push_back(x^1);
	}
	void add_cl(int x, int y) {
		add_impl(~x,y);
	}
	void add_true(int x) {
		add_impl(~x,x);
	}
	void add_false(int x) {
		add_impl(x,~x);
	}

	void at_most_one(vector<int> v) {
		g.resize(2*(tot+v.size()));
		for(int i=0;i<v.size();i++) {
			add_impl(tot+i,~v[i]);
			if(i) {
				add_impl(tot+i,tot+i-1);
				add_impl(v[i],tot+i-1);
			}
		}
		tot += v.size();
	}

	pair<bool,vector<int>> solve() {
		ans = vector<int>(n,-1);
		int t=0;
		vis = comp = id = vector<int>(2*tot,0);
		for(int i=0;i<2*tot;i++) if(!vis[i]) dfs(i,t);
		for(int i=0;i<tot;i++)
			if(comp[2*i]==comp[2*i+1]) return {false,{}};
		return {true,ans};
	}
};

#define MAX 200'100

int st[4*MAX];
void build(int p, int l, int r) {
	st[p] = 0;
	if(l==r) return;
	int m = (l+r)/2;
	build(2*p,l,m);
	build(2*p+1,m+1,r);
}

void op(int p, int l, int r, int lq, int rq) {
	if(st[p] or r<lq or rq<l) return;
	if(lq<=l and r<=rq) {
		st[p] = 1;
		return;
	}

	int m = (l+r)/2;
	op(2*p,l,m,lq,rq);
	op(2*p+1,m+1,r,lq,rq);
}

int get(int p, int l, int r, int i) {
	if(l==r or st[p]) return st[p];
	int m = (l+r)/2;
	if(i<=m) return get(2*p,l,m,i);
	return get(2*p+1,m+1,r,i);
}

void solve() {
	int n;
	cin >> n;
	build(1,0,n-1);
	sat s(n);
	
	int v[n];
	for(int i=0;i<n;i++) cin >> v[i];
	
	if(n==1) {
		if(v[0]<=0) cout << 1;
		else cout << -1;
		cout << '\n';
		return;
	}


	for(int i=0;i<n;i++) {
		int x = v[i];
		if(x==-1) continue;
		if(x==0) s.add_true(i);
		else {
			int l = i-x;
			int r = i+x;
			if(l<0 and r>=n) {
				cout << -1 << '\n';
				return;
			}

			if(l<0) s.add_true(r);
			else if(r>=n) s.add_true(l);
			else {
				assert(l>=0 and r<n);
				//cout << "l,r = " << l << ' ' << r << '\n';
				s.add_cl(l,r);
			}
			
			l = max(l+1,0);
			r = min(r-1,n-1);

			op(1,0,n-1,l,r);
		}
	}

	for(int i=0;i<n;i++) if(get(1,0,n-1,i)) s.add_false(i);
	
	auto [ok,ans] = s.solve();
	if(ok==false) cout << -1;
	else {
		for(int i:ans) cout << i;
	}

	cout << '\n';
}

int main() { 
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
