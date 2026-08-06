#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
	//#pragma GCC target("avx2")

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;

// :(
//#define int ll
#define MAX 30'000'000
const ll mod = 1'000'000'007ll;
ll N;

namespace seg {
	int seg[MAX], lazy[MAX], R[MAX], L[MAX], ptr;
	int get_l(int i) {
		if(i>=MAX or i<=0) exit(0);
		if(L[i]==0) L[i] = ptr++;
		return L[i];
	}
	int get_r(int i) {
		if(i<=0 or i>=MAX) exit(0);
		if(R[i]==0) R[i] = ptr++;
		return R[i];
	}

	void build() {ptr=2;}

	void prop(int p, ll l, ll r) {
		if(p>=MAX) exit(1); // o erro eh essa condicao (???????????)
		if(l>r) exit(1);
		if(lazy[p]==0) return;
		ll qtd = r-l+1;
		if(qtd<=0) exit(1);
		qtd%=mod;
		seg[p] += qtd*lazy[p]%mod;
		seg[p]%=mod;

		if(l!=r) {
			int ls = get_l(p);
			lazy[ls] = (lazy[ls]+lazy[p])%mod;
			ls = get_r(p);
			lazy[ls] = (lazy[p]+lazy[ls])%mod;
		}
		lazy[p] = 0;
	}
	int query(ll a, ll b, int p=1,ll l=0, ll r = N-1) {
		//if(p==1) cout << "r = " << r << '\n';
		prop(p,l,r);
		if(b<l or r<a) return 0;
		if(a<=l and r<=b) return seg[p];
		if(l>r or a>b) exit(1);
		ll m = (l+r)/2;
		ll ls = get_l(p);
		ll rs = get_r(p);
		return (query(a,b,ls,l,m)+query(a,b,rs,m+1,r))%mod;
	}
	int update(ll a, ll b,int x, int p=1, ll l=0, ll r=N-1) {
		//if(p==1) cout << "l,r = " << a << ' ' << b << '\n';
		prop(p,l,r);
		if(a>b or l>r) exit(1);
		if(b<l or r<a) return seg[p];
		if(a<=l and r<=b) {
			lazy[p] = (x+lazy[p])%mod;
			//cout << "sla" << x;
			prop(p,l,r);
			//cout << ' ' << seg[p] << '\n';
			return seg[p];
		}
		ll m = (l+r)/2;
		return seg[p] = (update(a,b,x,get_l(p),l,m)+update(a,b,x,get_r(p),m+1,r))%mod;
	}
};

// primeiro q tem k
ll left(ll n,ll k) {
	ll l = 1, r = n;
	ll ans = -1;
	//cout << "left :" << n << ' ' << k << '\n';
	while(l<=r) {
		ll m = (l+r)/2;
		assert(m!=0);
		if(m==0) exit(0);
		ll qtd = n/m;
	//	cout << m << ' ' << qtd << '\n';
		if(qtd<=k) {
			if(qtd==k) ans = m;
			r = m-1;
		} else l = m+1;
	}
	//cout << "ret " << ans << '\n';
	return ans;
}

// ultimo q tem k
ll right(ll n, ll k) {
	ll l = 1, r = n;
	ll ans = -1;
	while(l<=r) {
		ll m = (l+r)/2;
		assert(m!=0);
		if(m==0) exit(0);
		ll qtd = n/m;
		if(qtd>=k) {
			if(qtd==k) ans = m;
			l = m+1;
		} else r = m-1;
	}
	return ans;
}

signed main() { _
	ll n; int q;
	cin >> n >> q;
	N = n+1;
	//assert(q<=100'000);

	seg::build();

	while(q--) {
		int op;
		ll l,r;
		cin >> op >> l >> r;
		assert(l<=r);

		if(op==1) cout << seg::query(l,r) << '\n';
		else {
			ll k,x;
			cin >> k >> x;

			ll l2 = left(n,k);
			ll r2 = right(n,k);
			if(l2==-1 or r2==-1) continue;
			l = max(l,l2);
			r = min(r,r2);
			//cout << "l = " << l << ", r = " << r << ", x = " << x << ", k = " << k << '\n';
			if(r<l) {
				//cout << "penis\n";
				continue;
			}
			assert(l<=r);
			seg::update(l,r,x);
		}
		//for(int i=1;i<=n;i++) cout << seg::query(i,i) << ' ';
		//cout << '\n';
	}

	return 0;
}
