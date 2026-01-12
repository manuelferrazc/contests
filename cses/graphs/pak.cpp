#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int p[100'000];

int get(int a) {
	return p[a] = (p[a]==a?a:get(p[a]));
}

vector<int> adj[100'000];
int color[100'000];
int d[100'000];

struct T {
	int h=0;
	vector<int> comp;
};

list<vector<int>> comp;

T * dfs(int v, int dep) {
	d[v] = dep;
	color[v] = 1;

	T * ret = new T;
	ret -> h = dep;
	ret -> comp.push_back(v);

	for(int u:adj[v]) {
		if(color[u]==2) {
			int x = get(u);
			if(color[x]==1) ret->h = min(ret->h,d[x]);
		}
		else if(color[u]==1) ret->h = min(ret->h,d[u]);
		else {
			T* aux = dfs(u,dep+1);
			if(aux->h>dep) comp.push_back(aux->comp);
			else {
				p[u] = v;
				if(ret->comp.size()<aux->comp.size()) swap(ret,aux);
				ret->h = min(ret->h,aux->h);
				for(auto i:aux->comp) ret->comp.push_back(i);
			}

			delete aux;
		}
	}

	color[v] = 2;
	return ret;
}

int main() { _
    int n,m;
	cin >> n >> m;

	while(m--) {
		int a,b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	for(int i=0;i<n;i++) color[i] = 0;
	for(int i=0;i<n;i++) p[i] = i;

	for(int i=0;i<n;i++) if(color[i]==0) {
		T* p = dfs(i,0);
		comp.push_back(p->comp);
		delete p;
	}

	m = 1;
	for(vector<int> &v:comp) {
		for(auto i:v) color[i] = m;
		m++;
	}

	cout << comp.size() << '\n';
	for(int i=0;i<n;i++) cout << color[i] << ' ';
	cout << '\n';

	return 0;
}
