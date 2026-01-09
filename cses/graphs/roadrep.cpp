#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int p[100'000];
int r[100'000];

int get(int a) {
	return p[a] = (p[a]==a ? a : get(p[a]));
}

bool unionn(int a, int b) {
	a = get(a);
	b = get(b);
	if(a==b) return false;

	if(r[a]<r[b]) swap(a,b);
	if(r[a]==r[b]) r[a]++;
	p[b] = a;

	return true;
}

struct edge {
	int u,v;
	int w;

	bool operator<(const edge &o) {
		return w<o.w;
	}
};

int main() { _
    int n,m;
	cin >> n >> m;

	for(int i=0;i<n;i++) r[i] = 1;
	for(int i=0;i<n;i++) p[i] = i;

	edge v[m];
	for(int i=0;i<m;i++) cin >> v[i].u >> v[i].v >> v[i].w;

	sort(v,v+m);

	ll ans = 0;
	int qtd = 1;
	for(int i=0;i<m;i++) {
		auto [u1,u2,w] = v[i];

		if(unionn(u1-1,u2-1)) {
			ans+=w;
			qtd++;
		}
	}

	if(qtd<n) cout << "IMPOSSIBLE\n";
	else cout << ans << '\n';

	return 0;
}
