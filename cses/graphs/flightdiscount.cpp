#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct st {
	pair<ll,int> p;
	bool disc;

	st(ll a, int b, bool c) {
		p.ff = a;
		p.ss = b;
		disc = c;
	}

};
bool operator>(const st p, const st o) {
	return p.p>o.p;
}

bool operator<(const st p,const st o) {
	return p.p<o.p;
}
	
int main() { _
    int n,m;
	cin >> n >> m;

	vector<vector<pair<int,ll>>> adj(n);

	for(int i=0;i<m;i++) {
		int a,b;
		ll c;
		cin >> a >> b >> c;

		adj[a-1].push_back(make_pair(b-1,c));
	}

	vector<ll> dn(n,LLONG_MAX), dc(n,LLONG_MAX);
	dn[0] = dc[0] = 0;
	priority_queue<st,vector<st>,greater<st>> pq;
	pq.push(st(0,0,false));

	while(not pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int v = p.p.ss;
		ll c = p.p.ff;
		if(p.disc and c>dc[v]) continue;
		if((not p.disc) and c>dn[v]) continue;
		
		for(auto [u,w]:adj[v]) {
			// cout << "babab\n";
			if(p.disc) {
				if(dc[u]>w+dc[v]) {
					dc[u] = w+dc[v];
					pq.push(st(dc[u],u,true));
				}
			} else {
				if(dc[u]>w/2+dn[v]) {
					dc[u] = w/2+dn[v];
					pq.push(st(dc[u],u,true));
				}
				if(dn[u]>w+dn[v]) {
					dn[u] = w+dn[v];
					pq.push(st(dn[u],u,false));
				}
			}
		}
	}

	cout << min(dn.back(),dc.back()) << '\n';


	return 0;
}
