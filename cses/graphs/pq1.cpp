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

	fast[u][0] = to[u];
	for(int i=1;(1ull<<i)<dq.size();i++) fast[u][i] = dq[1<<i];

	for(auto u2:adj[u]) dfs2(u2,dq);

	dq.pop_front();
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
			dfs2(i,v2);
		}
	}
	
	while(q--) {
		int p,k;
		cin >> p >> k;
		p--;

		for(int i=17;i>=0;i--) {
			if(fast[p][i]!=-1 and (1<<i)<=k) {
				k-=1<<i;
				p = fast[p][i];
			}
		}
		
		if(k==0) cout << p+1 << '\n';
		else if(k==1) cout << to[p]+1 << '\n';
		else {
			p = to[p];
			k--;

			int ck = v[p][1],id = v[p][2];
			k+=id;
			k%=cks[ck].size();

			cout << cks[ck][k]+1 << '\n';
		}
	}

	return 0;
}
