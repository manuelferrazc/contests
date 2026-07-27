#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 100'000'000;

struct Mat {
	ll m[2][2];

	Mat() {
		m[0][0] = m[0][1] = m[1][0] = m[1][1] = 0;
	}

	Mat operator*(Mat o) {
		Mat r;

		for(int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				for(int k=0;k<2;k++) {
					r.m[i][j] += m[i][k]*o.m[k][j];
				}
				r.m[i][j] %= mod;
			}
		}
		return r;
	}
};

Mat fexp(Mat m, ll e) {
	Mat r;
	r.m[0][0] = r.m[1][1] = 1;

	while(e) {
		if(e&1) r = r*m;
		e>>=1;
		m = m*m;
	}
	return r;
}

int ans(ll n) {
	string st = to_string(n);
	reverse(st.begin(),st.end());
	while(st.size()>6) st.pop_back();
	while(st.size()<6) st.push_back('0');
	reverse(st.begin(),st.end());
	cout << st << '\n';

	return 0;
}

int main() { _
	ll n,k,l;
	cin >> n >> k >> l;
	n/=5;
	k%=mod;
	l%=mod;

	ll f2 = k*k+l;
	f2%=mod;

	if(n==1) return ans(k);
	if(n==2) return ans(f2);

	Mat m;
	m.m[0][0] = k;
	m.m[0][1] = l;
	m.m[1][0] = 1;

	Mat f = fexp(m,n-2);
	return ans((f.m[0][0]*f2 + f.m[0][1]*k)%mod);

	return 0;
}
