#include <bits/stdc++.h>

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


#define MAX 500000
const int UPD = 5e5+10, LOG = 19;
const int MAXS = 2*MAX + UPD*LOG;

namespace perseg {
	int seg[MAXS];
	int rt[UPD], L[MAXS], R[MAXS], cnt, t;
	int n;

	int build(int p, int l, int r) {
		if (l == r) return seg[p] = INT_MAX;
		L[p] = cnt++, R[p] = cnt++;
		int m = (l+r)/2;
		return seg[p] = min(build(L[p], l, m), build(R[p], m+1, r));
	}
	void build(int n2) {
		n = n2;
		rt[0] = cnt++;
		build(0, 0, n-1);
	}
	int query(int a, int b, int p, int l, int r) {
		if (b < l or r < a) return INT_MAX;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return min(query(a, b, L[p], l, m),query(a, b, R[p], m+1, r));
	}
	int query(int a, int b, int tt) {
		return query(a, b, rt[tt], 0, n-1);
	}
	int update(int a, int x, int lp, int p, int l, int r) {
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		if (a <= m)
			return seg[p] = min(update(a, x, L[lp], L[p]=cnt++, l, m),seg[R[p]=R[lp]]);
		return seg[p] = min(seg[L[p]=L[lp]],update(a, x, R[lp], R[p]=cnt++, m+1, r));
	}
	int update(int a, int x, int tt=t) {
		update(a, x, rt[tt], rt[++t]=cnt++, 0, n-1);
		return t;
	}
};


int main() { _
	int n,q,l,r;
	cin >> n >> q;

	int v[n];
	pair<int,int> v2[n];
	for(int i=0;i<n;i++) {
		cin >> v[i];
		v2[i] = {v[i],i};
	}

	sort(v2,v2+n);

	perseg::build(n);

	int times[1+n];
	times[0] = 0;

	for(int i=0;i<n;i++) {
		auto it = lower_bound(v2,v2+n,make_pair(v[i],i));
		if(it!=v2 and (it-1)->ff==v[i]) {
			int last = (it-1)->ss, dist = i-last;
			perseg::update(last,dist);
			times[i+1] = times[i]+1;
		} else times[i+1] = times[i];

	}
	
	ostringstream out;
	
	while(q--) {
		cin >> l >> r;

		int x = perseg::query(l-1,r-1,times[r]);

		if(x==INT_MAX) out << -1 << '\n';
		else out << x << '\n';
		// out << res << '\n';
	}

    // for (int res : results) {
    // }

    cout << out.str();

    return 0;
}
