#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace __gnu_pbds;
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

template <class T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,
					tree_order_statistics_node_update>;

struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
	int upper_bound(ll x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};

void solve() {
	int n;
	cin >> n;

	vector<ll> vx,vy;
	vector<pair<int,int>> v(n);

	for(int i=0;i<n;i++) {
		int x,y;
		cin >> x >> y;
		v[i] = pair(x,y);
		
		vx.push_back(x);
		vy.push_back(y);
	}

	Bit left(n+2),right(n+2);
	
	sort(v.begin(),v.end());
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());

	vector<int> cnt(n+1,0);
	vector<int> cnt2(n+1,0);

	for(int i=0;i<n;i++) {
		cnt[v[i].ss]++;
		if(cnt[v[i].ss]==1) right.update(v[i].ss,1);
	}

	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());

	ll ans = 0;
	int a = 0;

	set<int> rig;
	for(int i=0;i<n;i++) rig.insert(v[i].ss);
	int ma = -1, mi = INT_MAX;

	for(int i=0;i<vx.size();i++) {
		while(a<n and v[a].ff <= vx[i]) {
			cnt[v[a].ss]--;
			cnt2[v[a].ss]++;
			ma = max(ma,v[a].ss);
			mi = min(mi,v[a].ss);
			
			if(cnt[v[a].ss]==0) {
				right.update(v[a].ss,-1);
				rig.erase(v[a].ss);
			}
			if(cnt2[v[a].ss]==1) left.update(v[a].ss,1);
			a++;
		}
		
		if(ma==mi or ma==-1 or rig.empty()) continue;

		ll qtd = vy.size();
		
		ll l = ma;
		ll r = *rig.rbegin();

		if(l<r) {
			ll lixo = right.query(l+1,n+1);
			qtd -= lixo;
		} else if(l>r) {
			ll lixo = left.query(r+1,n+1);
			qtd -= lixo;
		}

		l = mi;
		r = *rig.begin();
		if(l<r) {
			ll lixo = left.query(0,r-1);
			qtd -= lixo;
		} else if(l>r) {
			ll lixo = right.query(0,l-1);
			qtd -= lixo;
		}

		if(qtd) ans += qtd-1;
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
