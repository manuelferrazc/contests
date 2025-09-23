#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

int d[MAX], p[MAX], pp[MAX];

void set_root(int i) { p[i] = pp[i] = i, d[i] = 0; }

void add_leaf(int i, int u) {
	p[i] = u, d[i] = d[u]+1;
	pp[i] = 2*d[pp[u]] == d[pp[pp[u]]]+d[u] ? pp[pp[u]] : u;
}

int kth(int i, int k) {
	int dd = max(0, d[i]-k);
	while (d[i] > dd) i = d[pp[i]] >= dd ? pp[i] : p[i];
	return i;
}

int lca(int a, int b) {
	if (d[a] < d[b]) swap(a, b);
	while (d[a] > d[b]) a = d[pp[a]] >= d[b] ? pp[a] : p[a];
	while (a != b) {
		if (pp[a] != pp[b]) a = pp[a], b = pp[b];
		else a = p[a], b = p[b];
	}
	return a;
}

int dist(int a, int b) { return d[a]+d[b]-2*d[lca(a,b)]; }

vector<int> g[MAX];

void build(int i, int pai=-1) {
	if (pai == -1) set_root(i);
	for (int j : g[i]) if (j != pai) {
		add_leaf(j, i);
		build(j, i);
	}
}

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int c = 0;

void dfs(int a, int p = -1) {
    c++;
    for(int i:g[a]) {
        if(i==p) continue;

        dfs(i,a);
    }
}

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    
    // int n = 1+ rand()%100000, m = 1+rand()%100000;
    int n = 100000,m = 100000;
    cout << n << ' ' << m << '\n';

    for(int i=0;i<n;i++) cout << 1+rand()%100000 << ' ';
    cout << '\n';
    
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    shuffle(v.begin(),v.end(),rng);

    for(int i=1;i<n;i++) {
        int pos = uniform(0,i-1);
        cout << v[i] << ' ' << v[pos] << '\n';

        g[v[i]-1].push_back(v[pos]-1);
        g[v[pos]-1].push_back(v[i]-1);
        // v.push_back(i);
    }

    dfs(0);
    if(c!=n) {
        cout << "NÂO É ÁRVORE!!!\n";
        exit(1);
    }

    while(m--) {
        int a = uniform(1,n);
        int b = uniform(1,n);

        cout << a << ' ' << b << ' ';
        int dd = dist(a-1,b-1);

        cout << uniform(1,dd+1) << '\n';
    }

    return 0;
}