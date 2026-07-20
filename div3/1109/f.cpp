#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct st {
	int mi;
	int ma;
	deque<int> q;

	st(int k) {
		mi = k;
		ma = k;
		q.push_back(k);
	}

	void merge(st * o,bool back) {
		if(back) {
			for(int k:o->q) {
				mi = min(mi,k);
				ma = max(ma,k);
				q.push_back(k);
			}
		} else {
			for(int i = o->q.size()-1;i>=0;i--) {
				mi = min(mi,o->q[i]);
				ma = max(ma,o->q[i]);
				q.push_front(o->q[i]);
			}
		}
	}
};

int val[200'000];

st* clear(list<st*> &l) {
	while(l.size()) {
		if(l.back()!=nullptr) delete l.back();
		l.pop_back();
	}
	return nullptr;
}

st* dfs(int v, vector<int> *adj) {
	if(adj[v].empty()) return new st(val[v]);

	list<st*> l;
	
	bool ok = true;
	int mi = INT_MAX;
	for(int i=0;i<adj[v].size();i++) {
		l.push_back(dfs(adj[v][i],adj));
		if(l.back()==nullptr) ok = false;
		else mi = min(mi,l.back()->mi);
	}

	if(ok==false) return clear(l);

	while(l.front()->mi!=mi) {
		l.push_back(l.front());
		l.pop_front();
	}

	for(auto it = l.begin();next(it)!=l.end();it++) {
		auto it2 = next(it);
		if((*it)->ma>(*it2)->mi) ok = false;
	}

	if(ok==false) return clear(l);

	while(l.size()>1ull) {
		auto it = l.begin();
		auto it2 = next(it);

		if((*it)->q.size()>=(*it2)->q.size()) {
			(*it)->merge(*it2,true);
			delete *it2;
			l.erase(it2);
		} else {
			(*it2)->merge(*it,false);
			delete *it;
			l.erase(it);
		}
	}

	return l.front();
}

void solve() {
	int n;
	cin >> n;

	vector<int> adj[n];
	for(int i=1;i<n;i++) {
		int p;
		cin >> p;
		p--;

		adj[p].push_back(i);
	}

	for(int i=0;i<n;i++) cin >> val[i];

	st* r = dfs(0,adj);
	if(r==nullptr) cout << "NO\n";
	else {
		cout << "YES\n";
		delete r;
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
