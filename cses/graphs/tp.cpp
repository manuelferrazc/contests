#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[100'000];

int no() {
	cout << "IMPOSSIBLE\n";
	return 0;
}

int main() { _
    int n,m;
	cin >> n >> m;

	for(int i=0;i<m;i++) {
		int a,b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	list<int> l;
	l.push_back(0);
	
	do {
		int v = l.back();
		if(adj[v].empty()) return no();

		l.push_back(adj[v].back());
		adj[v].pop_back();
	} while(l.back()<n-1);

	for(auto it = l.begin();it!=l.end();) {
		if(adj[*it].empty()) {
			it++;
			continue;
		}

		int tg = *it;
		auto it2 = next(it);

		int act = tg;
		do {
			if(adj[act].empty()) return no();
			int v = act;
			act = adj[act].back();
			adj[v].pop_back();
			l.insert(it2,act);
		} while(act!=tg);
	}

	for(int i=0;i<n;i++) if(adj[i].size()) return no();

	for(int i:l) cout << i+1 << ' ';
	cout << '\n';

	return 0;
}
