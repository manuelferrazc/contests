#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


const int MAX = 2e5+10, UPD = 2e5+10, LOG = 19;
const int MAXS = 2*MAX+UPD*LOG;

namespace perseg {
	ll seg[MAXS];
	int rt[UPD], L[MAXS], R[MAXS], cnt, t;
	int n;

	ll build(int p, int l, int r) {
		if (l == r) return seg[p] = 0;
		L[p] = cnt++, R[p] = cnt++;
		int m = (l+r)/2;
		return seg[p] = build(L[p], l, m) + build(R[p], m+1, r);
	}
	void build(int n2) {
		n = n2;
		rt[0] = cnt++;
		build(0, 0, n-1);
	}
	ll query(int a, int b, int p, int l, int r) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, L[p], l, m) + query(a, b, R[p], m+1, r);
	}
	ll query(int a, int b, int tt) {
		return query(a, b, rt[tt], 0, n-1);
	}
	ll update(int a, int x, int lp, int p, int l, int r) {
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


    map<int,vector<int>> m;

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        m[x].push_back(i);
    }

    perseg::build(n);

    vector<pair<int,int>> v;
    for(auto it = m.rbegin();it!=m.rend();it++) {
        v.push_back({it->ff,0});

        for(auto i:it->ss) v.back().ss = perseg::update(i,1);
    }

    reverse(v.begin(),v.end());

    while(q--) {
        int lq,rq;
        cin >> lq >> rq;

        lq--;
        rq--;

        int l=1,r=n,ans = 1;

        while(l<=r) {
            int m2 = (l+r)>>1;

            auto it = lower_bound(v.begin(),v.end(),pair(m2,-1));
            if(it==v.end()) {
                r = m2-1;
                continue;
            }

            int val = perseg::query(lq,rq,it->ss);

            if(val>=m2) {
                ans = m2;
                l=m2+1;
            } else r=m2-1;
        }

        cout << ans << '\n';
    }

    return 0;
}
