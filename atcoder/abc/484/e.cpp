#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 300100

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	void build(int n2, int* v2) {
		n = n2, v = v2;
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p]*(r-l+1);
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

//ll st[4*MAX];

//ll add(int p, int l, int r, int i) {
//	if(i<l or r<i) return st[p];
//	if(l==r) return st[p]++;

//	int m = (l+r)/2;
//	return st[p] = add(2*p,l,m,i) + add(2*p+1,m+1,r,i);
//}

//ll get(int p, int l, int r, int lq, int rq) {
//	if(rq<l or r<lq) return 0;
//	if(lq<=l and r<=rq) return st[p];

//	int m = (l+r)/2;
//	return get(2*p,l,m,lq,rq) + get(2*p+1,m+1,r,lq,rq);
//}

int main() { _
	int n;
	ll l,r;
	cin >> n >> l >> r;

	ll v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	vector<ll> pref;
	ll s=0;
	pref.push_back(0);
	pref.push_back(LLONG_MIN);
	pref.push_back(LLONG_MAX);

	for(int i=0;i<n;i++) {
		s += v[i];
		pref.push_back(s);
	}

	sort(pref.begin(),pref.end());
	pref.erase( unique(pref.begin(),pref.end()) , pref.end());

	//cout << prefs: ;
	//for(auto i:pref) cout << i << ' ';
	//cout << '\n';

	ll ans = 0;
	s=0;

	seg::build(n+10,nullptr);

	auto it = lower_bound(pref.begin(),pref.end(),0ll) - pref.begin();
	seg::update(it,it,1);

	for(int i=0;i<n;i++) {
		//cout << seg: ;
		//for(int i=0;i<pref.size();i++) cout << seg::query(i,i) << ' ';
		//cout << '\n';
		s += v[i];

		// #pref tq l <= s - pref <= r
		// #pref tq s - pref <= r   ->   s-r <= pref

		it = lower_bound(pref.begin(),pref.end(), s-r) - pref.begin();

		//ans += get(1,0,n+1,it,n+1);

		// #pref tq l <= s-pref  ->  pref <= s - l
		
		auto it2 = upper_bound(pref.begin(),pref.end(),s-l) - pref.begin() - 1;

		//cout << it1, it2 =  << it << ' ' << it2 << endl;
		if(it<=it2) ans += seg::query(it,it2);
		//cout << ans << ' ' << seg::query(it,it2) << endl;

		it = lower_bound(pref.begin(),pref.end(),s) - pref.begin();
		seg::update(it,it,1);
	}

	cout << ans << '\n';

	return 0;
}
