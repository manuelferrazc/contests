#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

// BIT 2D
//
// BIT de soma, update incrementa posicao
// Tem que construir com um vetor com todos os pontos
// que vc quer um dia atualizar (os pontos q vc vai chamar update)
//
// Complexidades:
// construir - O(n log(n))
// update e query - O(log^2(n))

template<class T = int> struct bit2d {
	vector<int> X;
	vector<vector<int>> Y, t;

	int ub(vector<int>& v, T x) {
		return upper_bound(v.begin(), v.end(), x) - v.begin();
	}
	bit2d(vector<pair<T, T>> v) {
		// for (auto [x, y] : v) X.push_back(x);
        for(int i=0;i<(int)v.size();i++) X.push_back(v[i].ff);
		sort(X.begin(), X.end());
		X.erase(unique(X.begin(), X.end()), X.end());

		t.resize(X.size() + 1);
		Y.resize(t.size());
		sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
			return a.second < b.second; });
		for (int k=0;k<(int)v.size();k++) {
            int x = v[k].ff;
            int y = v[k].ss;
            for (int i = ub(X, x); i < t.size(); i += i&-i)
			    if (!Y[i].size() or Y[i].back() != y) Y[i].push_back(y);
        }

		for (int i = 0; i < t.size(); i++) t[i].resize(Y[i].size() + 1);
	}

	void update(T x, T y, T v) {
		for (int i = ub(X, x); i < t.size(); i += i&-i)
			for (int j = ub(Y[i], y); j < t[i].size(); j += j&-j) t[i][j] += v;
	}

	T query(T x, T y) {
		T ans = 0;
		for (int i = ub(X, x); i; i -= i&-i)
			for (int j = ub(Y[i], y); j; j -= j&-j) ans += t[i][j];
		return ans;
	}
	T query(T x1, T y1, T x2, T y2) {
		return query(x2, y2)-query(x2, y1-1)-query(x1-1, y2)+query(x1-1, y1-1);
	}
};

void solve(int n, int m) {
    int v[n+1];
    int p[n+1];
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        p[v[i]] = i;
    }

    vector<pair<int,int>> op;
    int rem[m];
    for(int i=1;i<=n;i++) op.emplace_back(i,p[i]);
    for(int i=0;i<m;i++) cin >> rem[i];

    bit2d<int> bt(op);
    for(int i=1;i<=n;i++) bt.update(i,p[i],1);

    ll ans = 0;
    for(int i=1;i<=n;i++) 
        ans+=bt.query(i+1,1,n+1,p[i]-1);

    for(int i=0;i<m;i++) {
        cout << ans << '\n';

        bt.update(rem[i],p[rem[i]],-1);
        ans -= bt.query(rem[i]+1,0,n+1,p[rem[i]]-1);
        ans -= bt.query(0,p[rem[i]]+1,rem[i]-1,n+1);
    }
}

int main() { _
    int n,m;

    while(cin >> n >> m) 
        solve(n,m);

    return 0;
}
