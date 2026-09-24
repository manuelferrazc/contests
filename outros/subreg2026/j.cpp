#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll LINF= 0x3f3f3f3f3f3f3f3fll;

template<int MI=int(-1e9), int MA = int(1e9)> struct lichao {
	struct line {
		ll a,b;
		array<ll,2> ch;
		line (ll a_=0, ll b_ = LINF) : a(a_), b(b_), ch({-1,-1}) {}
		ll operator()(ll x) { return a*x + b; }
	};

	vector<line> ln;
	int ch(int p, int d) {
		if(ln[p].ch[d]==-1) {
			ln[p].ch[d] = ln.size();
			ln.emplace_back();
		}
		return ln[p].ch[d];
	}

	lichao() { ln.emplace_back(); }

	ll query(int x, int p=0, int l=MI, int r=MA) {
		ll ret = ln[p](x);
		if (ln[p].ch[0]==-1 and ln[p].ch[1]==-1) return ret;
		int m = l + (r-l)/2;
		if(x<=m) return min(ret,query(x,ch(p,0),l,m));
		return min(ret,query(x,ch(p,1),m+1,r));
	}

	void push(line s, int p, int l, int r) {
		int m = l+ (r-l)/2;
		bool L = s(l)<ln[p](l);
		bool M = s(m)<ln[p](m);
		bool R = s(r)<ln[p](r);
		if(M) swap(ln[p].a, s.a), swap(ln[p].b, s.b);
		if(s.b==LINF) return;
		if(L!=M) push(s,ch(p,0),l,m);
		else if(R!=M) push(s,ch(p,1),m+1,r);
	}

	void insert(line s, int a=MI, int b=MA, int p=0, int l=MI, int r=MA) {
		if(a<=l and r<=b) return push(s,p,l,r);
		if(b<l or r<a) return;
		int m = l+ (r-l)/2;
		insert(s,a,b,ch(p,0),l,m);
		insert(s,a,b,ch(p,1),m+1,r);
	}
};

#define MAX 100'000

int main() { _
	int n,m,a,b;
	cin >> n >> m >> a >> b;
	a--;
	b--;

	lichao<0,MAX-1> lt;

	vector<array<ll,4>> g[n];
	for(int i=0;i<m;i++) {
		ll u,l,r,x,k;
		cin >> u >> l >> r >> x >> k;
		u--;
		l--;
		r--;

		g[u].push_back({l,r,x,k});
	}

	lt.insert({0,0},0,0);
	
	priority_queue<
		pair<ll,int>,
		vector<pair<ll,int>>,
		greater<pair<ll,int>>
		> pq;
	
	pq.push(pair(0ll,0));
	ll dist[n];
	fill(dist,dist+n,LINF);
	dist[0] = 0;

	set<int> nvis;
	for(int i=0;i<n;i++) nvis.insert(i);

	while(not pq.empty()) {
		auto [d,u] = pq.top();
		pq.pop();

		if(d>dist[u]) continue;
		// cout << u << ' ' << d << '\n';
		nvis.erase(u);

		for(auto [l,r,x,k]:g[u]) {
			ll c = d + x -l*k;
			lt.insert({k,c},l,r);
			
			auto dl = lt.query(l);
			if(dl<LINF and dl<dist[l]) {
				dist[l] = dl;
				pq.push(pair(dl,l));
			}
		}

		auto it = nvis.upper_bound(u);
		if(it!=nvis.end()) {
			int u2 = *it;
			ll dd = lt.query(u2);
			if(dd<LINF and dist[u2]>dd) {
				dist[u2] = dd;
				pq.push(pair(dd,u2));
			}
		}

		if(it!=nvis.begin()) {
			it--;
			int u2 = *it;
			ll dd = lt.query(u2);
			if(dd<LINF and dist[u2]>dd) {
				dist[u2] = dd;
				pq.push(pair(dd,u2));
			}
		}
	}

	if(dist[a]==LINF or dist[b]==LINF) cout << -1 << '\n';
	else cout << dist[a]+dist[b] << '\n';

	return 0;
}
