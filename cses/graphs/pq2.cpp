#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> cc;
vector<vector<int>> cks;
array<int,3> v[200000]; // v[i][0] -> se pertence à um ciclo, [1] -> em qual ciclo tá, [2] -> qual indice
short color[200'000];
int to[200'000];
vector<int> adj[200'000];
int fast[200'000][18];

int dfs(int u) {
	if(color[u]==1) return u;
	else if(color[u]==2) return -1;

	color[u] = 1;

	int r = dfs(to[u]);
	color[u] = 2;

	if(r!=-1) {
		v[u][0] = 1;
		v[u][1] = cks.size();
		cc.push_back(u);
		
		if(r==u) {
			reverse(cc.begin(),cc.end());
			for(int i=0;i<(int)cc.size();i++) v[cc[i]][2] = i;
			cks.push_back(cc);
			cc.clear();

			return -1;
		}

		return r;
	}
	return -1;	
}

void dfs2(int u, deque<int> &dq) {
	dq.push_front(u);
	
	for(int i=0;(1ull<<i)<dq.size();i++) fast[u][i] = dq[1<<i];
	for(auto u2:adj[u]) dfs2(u2,dq);

	dq.pop_front();
}

int dist_ck(int p) {
	int k=0;
	for(int i=17;i>=0;i--) {
		if(fast[p][i]!=-1) {
			k+=1<<i;
			p = fast[p][i];
		}
	}
	return k;
}

int where(int p, int k) {
	for(int i=17;i>=0;i--) {
		if(fast[p][i]!=-1 and (1<<i)<=k) {
			k-=1<<i;
			p = fast[p][i];
		}
	}

	return p;
}

int main() { _
    int n,q;
	cin >> n >> q;
	
	for(int i=0;i<n;i++) color[i] = 0;

	for(int i=0;i<n;i++) {
		cin >> to[i];
		to[i]--;
		adj[to[i]].push_back(i);

		if(to[i]==i) {
			color[i] = 2;
			v[i][0] = 1;
			v[i][1] = cks.size();
			v[i][2] = 0;
			cks.push_back({i});
		} else v[i][0] = 0;
	}

	for(int i=0;i<n;i++) 
		if(color[i]==0) dfs(i);

	for(int i=0;i<n;i++) for(int j=0;j<18;j++) fast[i][j] = -1;
	for(int i=0;i<n;i++) {
		if(v[i][0]==0 and v[to[i]][0]) {
			deque<int> v2;
			v2.push_front(to[i]);
			dfs2(i,v2);
		}
	}
	
	while(q--) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;

		if(a==b) cout << 0 << '\n';
		else if(v[a][0] and v[b][0]) {
			if(v[a][1]!=v[b][1]) cout << -1 << '\n';
			else if(v[a][2]<=v[b][2]) cout << v[b][2]-v[a][2] << '\n';
			else cout << cks[v[a][1]].size()-v[a][2]+v[b][2] << '\n';
		} else if(v[a][0]) cout << -1 << '\n';
		else if(v[b][0]) {
			int dist = dist_ck(a);
			a = where(a,dist);

			if(v[a][1]!=v[b][1]) cout << -1 << '\n';
			else if(v[a][2]<=v[b][2]) cout << v[b][2]-v[a][2]+dist << '\n';
			else cout << cks[v[a][1]].size()-v[a][2]+v[b][2]+dist << '\n';
		} else {
			int da = dist_ck(a), db = dist_ck(b);

			if(da<=db or where(a,da-db)!=b) cout << -1 << '\n';
			else cout << da-db << '\n';
		}
	}

	return 0;
}
