#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 2500
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
ll d[MAX];
vector<pair<int, int>> ar; // vetor de arestas
vector<int> w;

int p[MAX];

int bellman_ford(int a) {
	for (int i = 0; i < n; i++) d[i] = LINF;
	d[a] = 0;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < m; j++) {
			if (d[ar[j].second] > d[ar[j].first] + w[j]) {
				p[ar[j].ss] = ar[j].ff;
				if (i == n) return ar[j].ff;

				d[ar[j].second] = d[ar[j].first] + w[j];
			}
		}

	return -1;
}

int main() { _
    cin >> n >> m;
	for(int i=0;i<m;i++) {
		int a,b,c;
		cin >> a >> b >> c;

		ar.push_back(pair(a-1,b-1));
		w.push_back(c);
	}

	int v = bellman_ford(0);
	if(v==-1) cout << "NO\n";
	else {
		cout << "YES\n";
		vector<bool> onq(n,false);

		list<int> q;
		while(true) {
			q.push_front(v);
			if(onq[v]) break;
			onq[v] = true;
			v = p[v];
		}

		while(q.front()!=q.back()) q.pop_back();

		for(int i:q) cout << i+1 << ' ';
		cout << '\n';

	}

	return 0;
}
