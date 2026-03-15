#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,h;
pair<int,int> v[2000];

ll qtd[2000];

#define MAX 20000
#define MAX2 12

namespace sparse {
    int n;
	pair<int,int> m[MAX2][2*MAX], v[2*MAX];
	pair<int,int> op(pair<int,int> a, pair<int,int> b) { return max(a, b); }
	void build(int n2, pair<int,int>* v2) {
		n = n2;
		for (int i = 0; i < n; i++) v[i] = v2[i];
		while (n&(n-1)) n++;
		for (int j = 0; (1<<j) < n; j++) {
			int len = 1<<j;
			for (int c = len; c < n; c += 2*len) {
				m[j][c] = v[c], m[j][c-1] = v[c-1];
				for (int i = c+1; i <  c+len; i++) m[j][i] = op(m[j][i-1], v[i]);
				for (int i = c-2; i >= c-len; i--) m[j][i] = op(v[i], m[j][i+1]);
			}
		}
	}
	pair<int,int> query(int l, int r) {
		if (l == r) return v[l];
		int j = __builtin_clz(1) - __builtin_clz(l^r);
		return op(m[j][l], m[j][r]);
	}
}

void solve() {
    cin >> n >> h;

    for(int i=0;i<n;i++) cin >> v[i].ff;
    for(int i=0;i<n;i++) v[i].ss = i;

    for(ll i=0;i<n;i++) {
        int d = v[i].ff;
        qtd[i] = h-d;
        for(int j=i-1;j>=0;j--) {
            d = max(d,v[j].ff);
            qtd[i]+=h-d;
        }

        d = v[i].ff;
        for(int j=i+1;j<n;j++) {
            d = max(d,v[j].ff);
            qtd[i]+=h-d;
        }
    }

    sparse::build(n,v);

    ll ans = *max_element(qtd,qtd+n);
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            ll act = qtd[i]+qtd[j];

            auto [fds,id] = sparse::query(i,j);
            act -= qtd[id];

            ans = max(ans,act);
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
