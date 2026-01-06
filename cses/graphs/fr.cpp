#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int k;

struct Price {
	int qtd=0;
	map<ll,int> m;

	bool contains(ll dist) {
		return m.count(dist);
	}

	void add(ll dist, int q) {
		q = min(q,k);

		qtd+=q;
		m[dist]+=q;
		while(m.size() and qtd-m.rbegin()->ss>=k) {
			qtd-=m.rbegin()->ss;
			m.erase(prev(m.end()));
		}
	}

	bool good(ll dist) {
		if(qtd<k) return true;

		ll acc = 0;
		for(auto [a,b]:m) {
			if(a<dist) acc+=b;
			else break;
		}

		return acc<k;

	}
};

int main() { _
    int n,m;
	cin >> n >> m >> k;

	vector<pair<int,int>> adj[n];
	while(m--) {
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;

		adj[a].push_back(pair(b,c));
	}

	Price p[n];
	p[0].add(0,1);

	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push({0,0});

	while(pq.size()) {
		auto [dist,v] = pq.top();
		pq.pop();
		
		if(not p[v].contains(dist)) continue;
		
		for(auto [u,w]:adj[v]) {
			ll nd = w+dist;
			if(p[u].contains(nd)) p[u].add(nd,p[v].m[dist]);
			else if(p[u].good(nd)) {
				p[u].add(nd,p[v].m[dist]);
				pq.push(pair(nd,u));
			}
		}
	}

	int qtd = k;

	for(auto [a,b]:p[n-1].m) {
		while(qtd and b) {
			cout << a << ' ';
			b--;
			qtd--;
		}
		if(qtd==0) break;
	}

	cout << '\n';

	return 0;
}
