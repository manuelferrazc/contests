#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 300000
#define MAX2 19

namespace sparse {
	int m[MAX2][2*MAX], n, v[2*MAX];
	int op(int a, int b) { return min(a, b); }
	void build(int n2, int* v2) {
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
	int query(int l, int r) {
		if (l == r) return v[l];
		int j = __builtin_clz(1) - __builtin_clz(l^r);
		return op(m[j][l], m[j][r]);
	}
}

int main() { _
    int n;
    cin >> n;

    int v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    sparse::build(n,v);
    ll a=0,b=-1;
    ll ans = 1;

    while(b<n) {
        b++;

        while(a<b and sparse::query(a,b)<(b-a+1)) a++;
        
        ll base = b-a+1;
        ll heig = sparse::query(a,b);
        ans = max(ans,min(base,heig));
    }

    cout << ans << '\n';

    return 0;
}
