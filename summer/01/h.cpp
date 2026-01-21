#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


const int MAX = 1e6+10, UPD = 3e5+10, LOG = 19;
const int MAXS = 2*MAX + 4*UPD*LOG;

namespace perseg {
	int seg[MAXS];
    int lazy[MAXS];
	int rt[UPD], L[MAXS], R[MAXS], cnt, t;
	int n;

	int build(int p, int l, int r) {
		if (l == r) return seg[p] = 0;
		L[p] = cnt++, R[p] = cnt++;
		int m = (l+r)/2;
		return seg[p] = max(build(L[p], l, m), build(R[p], m+1, r));
	}
	void build(int n2) {
		n = n2;
		rt[0] = cnt++;
		build(0, 0, n-1);
	}
	int query(int a, int b, int p, int l, int r) {
		if (b < l or r < a) return -INF;
		if (a <= l and r <= b) return lazy[p] + seg[p];
		int m = (l+r)/2;
		int ret = lazy[p] + max(query(a, b, L[p], l, m), query(a, b, R[p], m+1, r));
		return ret;
	}
	int query(int a, int b, int tt) {
		return query(a, b, rt[tt], 0, n-1);
	}
	int update(int a, int b, int x, int lp, int p, int l, int r) {
		tie(seg[p], lazy[p], L[p], R[p]) = {seg[lp], lazy[lp], L[lp], R[lp]};
		if (b < l or r < a) return seg[p] + lazy[p];
		if (a <= l and r <= b) return seg[p] + (lazy[p] += x);

		int m = (l+r)/2;
		seg[p] = max(update(a, b, x, L[lp], L[p] = cnt++, l, m),
					 update(a, b, x, R[lp], R[p] = cnt++, m+1, r));
		lazy[p] = lazy[lp];
		return seg[p] + lazy[p];
	}
	int update(int a, int b, int x, int tt=t) {
		// assert(tt <= t);
		update(a, b, x, rt[tt], rt[++t]=cnt++, 0, n-1);
		return t;
	}
};

#define ff first
#define ss second

int main() { _
    int n,q;
    cin >> n >> q;

    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].ff >> v[i].ss;
    sort(v.rbegin(),v.rend());

    perseg::build(1000001);

    map<int,int> m;
    m[1e7] = 0;
    for(int i=0;i<n;i++) {
        int x = perseg::update(v[i].ff,v[i].ss,1);
        m[v[i].ff] = x;
    }
    
    while(q--) {
        int q2;
        cin >> q2;

        int p[q2];
        for(int i=0;i<q2;i++) cin >> p[i];

        int ans = 0;
        int last = -1;

        for(int i=0;i<q2;i++) {
            auto it = m.upper_bound(last);

            ans += perseg::query(p[i],p[i],it->ss);
            last = p[i];
        }

        cout << ans << '\n';
    }
	exit(0);
}