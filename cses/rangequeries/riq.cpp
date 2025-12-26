#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")
// #pragma GCC optimize ("O3")

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

// query(a, b, t) retorna a query de [a, b] na versao t
// update(a, x, t) faz um update v[a]+=x a partir da
// versao de t, criando uma nova versao e retornando seu id
// Por default, faz o update a partir da ultima versao
//
// build - O(n)
// query - O(log(n))
// update - O(log(n))

const int MAX = 2e5+10, UPD = 2e5+10, LOG = 19;
const int MAXS = 2*MAX+UPD*LOG;

namespace perseg {
	int seg[MAXS];
	int rt[UPD], L[MAXS], R[MAXS], cnt, t;
	int n;

	int build(int p, int l, int r) {
		if (l == r) return seg[p] = 0;
		L[p] = cnt++, R[p] = cnt++;
		int m = (l+r)/2;
		return seg[p] = build(L[p], l, m) + build(R[p], m+1, r);
	}
	void build(int n2) {
		n = n2;
		rt[0] = cnt++;
		// build(0, 0, n-1);
	}
	int query(int a, int b, int p, int l, int r) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, L[p], l, m) + query(a, b, R[p], m+1, r);
	}
	int query(int a, int b, int tt) {
		return query(a, b, rt[tt], 0, n-1);
	}
	int update(int a, int x, int lp, int p, int l, int r) {
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		if (a <= m)
			return seg[p] = update(a, x, L[lp], L[p]=cnt++, l, m) + seg[R[p]=R[lp]];
		return seg[p] = seg[L[p]=L[lp]] + update(a, x, R[lp], R[p]=cnt++, m+1, r);
	}
	int update(int a, int x, int tt=t) {
		update(a, x, rt[tt], rt[++t]=cnt++, 0, n-1);
		return t;
	}
};

int main() { _
    int n,q;
    cin >> n >> q;

    perseg::build(n);

    int v[n];
    for(int i=0;i<n;i++) cin >> i[v];

	pair<int,int> m[n];
    for(int i=0;i<n;i++) m[i] = pair(v[i],i);

	sort(m,m+n);

    vector<pair<int,int>> rt;
	rt.push_back(pair(0,0));

	for(int i=0;i<n;i++) {
		if(rt.back().ff==m[i].ff) rt.back().ss = perseg::update(m[i].ss,1);
		else rt.push_back(pair(m[i].ff,perseg::update(m[i].ss,1)));
    }

	int ans[q];

	for(int i=0;i<q;i++) {

	// }
    // while(q--) {
        int l,r,mi,mx;
        cin >> l >> r >> mi >> mx;
        l--;
        r--;

        int qma=0,qmi=0;

        auto it = upper_bound(rt.begin(),rt.end(),pair(mx+1,-1));
		it--;
		auto it2 = lower_bound(rt.begin(),rt.end(),pair(mi,-1));
        it2--;

		qma = perseg::query(l,r,it->ss);
        qmi = perseg::query(l,r,it2->ss);

        // cout << qma-qmi << '\n';
		ans[i] = qma-qmi;
		// printf("%d\n",qma-qmi);
    }

	for(int i=0;i<q;i++) cout << ans[i] << '\n';
    
    return 0;
}
