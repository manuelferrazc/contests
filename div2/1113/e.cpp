#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void yes() {
	cout << "Yes\n";
}

void solve() {
	ll n,m,d;
	cin >> n >> m >> d;

	ll p[m], r[m];
	for(int i=0;i<m;i++) cin >> p[i] >> r[i];

	ll sr[m];
	map<ll,ll> x;
	sr[0] = r[0];
	x[p[0]] = r[0];
	for(int i=1;i<m;i++) {
		sr[i] = sr[i-1]+r[i];
		x[p[i]] = sr[i];
	}

	auto qtia = [&] (ll a, int i) -> ll { // pegando |a| dps do prefixo p[i]
		ll ret = d*(a-p[i]);
		auto it = x.upper_bound(a);
		if(it!=x.begin()) {
			it--;
			ret+=it->ss;
			ret-=x[p[i]];
		}

		ll rem = a-n;
		if(rem>0) {
			it = x.upper_bound(rem);
			if(it!=x.begin()) {
				it--;
				ret += it->ss;
			}
		}
		return ret;
	};

	auto qta = [&] (ll a, int i,bool db = false) -> ll {
		ll ret = d*a;
		if(db) cout << "ret1 = " << ret << ", i = " << i << ", p[i] = " << p[i] << ", a = " << a << '\n';
		ret += sr[i];
		//if(db) cout << "mod = " << a%(p[i]+1) << '\n';
		//if(it!=x.begin()) {
		//	it--;
		//	ret += it->ss;
		//}
		return ret;
	};

	//cout << "map: ";
	//for(auto [a,b]:x) cout << "(" << a << "," << b << ") ";
	//cout << '\n';

	for(int i=0;i<m;i++) {
		for(int j=0;j<m;j++) {
			if(qtia(p[j]+p[i]+1,j)<qta(p[i],i)) {
				//ll sla = qta(p[j]-1,i,false);
				//cout <<i<< ' '<< p[j] << ' ' << qtia(p[j]-1,j) << ' ' << sla << '\n';
				return yes();
			}
			//ll qd = (p[j]+p[i])/(p[i]+1);
			//qd*=p[i];
			//if(qd-1<=n and qtia(qd-1,j)<qta(qd-1,i)) return yes();
		}
		//if(qta(n,i)>d*n+sr[m-1]) return yes();
	}

	cout << "No\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
