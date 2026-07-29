#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 200000
#define MAX2 18

namespace sparse {
	int m[MAX2][2*MAX], n, v[2*MAX];
	int op(int a, int b) { return gcd(a, b); }
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
	
	int p[n];
	for(int i=0;i<n;i++) cin >> p[i];
	sparse::build(n,p);

	deque<int> pref;
	for(int i=1;i<n-1;i++) pref.push_back(i);
	int suf = n;
	ll ans = sparse::query(0,n-1);
	
	while(pref.size()) {
		ll minp = min(sparse::query(0,pref.front()),sparse::query(pref.front(),n-1));
		ll mins = min(sparse::query(0,pref.back()),sparse::query(pref.back(),n-1));

		ans+=min(minp,mins);

		if(minp<=mins) {
			pref.pop_front();
		} else pref.pop_back();
	}

	cout << ans << '\n';

    return 0;
}
