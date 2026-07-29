#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define _ ios_base::sync_with_stdio();cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;

struct Mat {
	ll m[2][2];

	Mat(bool I) {
		m[0][1] = m[1][0] = 0;
		m[0][0] = m[1][1] = (ll)I;
	}

	Mat operator*(Mat &o) {
		Mat ret(false);
		for(int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				for(int k=0;k<2;k++) ret.m[i][j] += m[i][k]*o.m[k][j];
				ret.m[i][j]%=mod;
			}
		}
		return ret;
	}
};

Mat fexp(Mat m, ll e) {
	Mat ret(true);
	while(e) {
		if(e&1) ret = ret*m;
		e>>=1;
		m = m*m;
	}
	return ret;
}

ll fexp(ll x, ll e) {
	ll r = 1;
	while(e) {
		if(e&1) r = (r*x)%mod;
		e>>=1;
		x = x * x % mod;
	}
	return r;
}

void solve() {
	ll a,b,n,m,vn,vm;
	cin >> a >> b >> n >> m >> vn >> vm;

	Mat mat(false);
	mat.m[0][0] = a;
	mat.m[0][1] = b;
	mat.m[1][0] = 1;

	ll binv = fexp(b,mod-2);
	Mat inv(0);
	inv.m[0][0] = (mod - (a*binv%mod))%mod;
	inv.m[0][1] = binv;
	inv.m[1][0] = 1;

	Mat A = fexp(mat,m-n);
	ll x = A.m[0][0];
	ll y = A.m[0][1];

	// vm = x*vn + y*f(n-1)
	// vm - x*vn = y*f(n-1)
	// f(n-1) = (vm - x*vn)/y

	ll fn1 = (mod + vm - (x*vn%mod))%mod;
	fn1 = fn1*fexp(y,mod-2)%mod;

	Mat B = fexp(inv,n-1);
	// B = [i j]
	//     [k l]
	ll i = B.m[0][0];
	ll j = B.m[0][1];
	ll k = B.m[1][0];
	ll l = B.m[1][1];

	// f(0) = i*f(n-1) + j*f(n)
	// f(1) = k*f(n-1) + l*f(n)
	ll f0 = i*fn1 + j*vn;
	ll f1 = k*fn1 + l*vn;
	
	f0%=mod;
	f1%=mod;

	cout << f0 << ' ' << f1 << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	
	return 0;
}
