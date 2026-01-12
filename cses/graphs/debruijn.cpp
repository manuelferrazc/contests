#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
	int n;
	cin >> n;
	for(int i=1;i<n;i++) cout << 0;

	int adj[1<<(n-1)][2];
	int nm1 = 1<<(n-1);

	for(int i=0;i<nm1;i++) {
		adj[i][0] = i/2;
		adj[i][1] = (i+nm1)/2;
	}

	list<pair<int,bool>> p;
	p.push_back({0,0});

	auto find = [&](list<pair<int,bool>> &l) {
		do {
			if(adj[l.back().ff][0]!=-1) {
				int next = adj[l.back().ff][0];
				adj[l.back().ff][0] = -1;
				l.push_back(pair(next,0));
			} else {
				int next = adj[l.back().ff][1];
				adj[l.back().ff][1] = -1;
				l.push_back(pair(next,1));
			}
		} while(l.back().ff!=l.front().ff);
	};

	find(p);

	for(auto it = next(p.begin());it!=p.end();) {
		if(adj[it->ff][1]!=-1) {
			list<pair<int,bool>> p2;
			p2.push_back(*it);
			find(p2);
			p2.pop_front();
			
			auto aux = it;
			aux++;
			for(auto sla:p2) p.insert(aux,sla);
		} else it++;
	}

	for(auto it = next(p.begin());it!=p.end();it++) cout << it->ss;
	cout << '\n';

	return 0;
}
