#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll get(ll* v, int a, int b) {
	if(a==0) return v[b];
	return v[b]-v[a-1];
}

void solve() {
	int n,k;
	cin >> n >> k;

	ll v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	ll sp[n];
	sp[0] = v[0];
	for(int i=1;i<n;i++) sp[i] = v[i]+sp[i-1];

	cout << 0;

	for(int i=1;i<n-1;i++) {
		if(v[i+1]-v[i-1]<=k) {
			cout << " 0";
			continue;
		}

		ll l = i+1,r=n-1;

		// ultima posicao q a soma e menor q a pa
		ll ok = i+1;

		while(l<=r) {
			ll m = (l+r)/2;

			ll val = v[i-1]+k*(m-i);

			if(v[m]>val) { // preciso operar o v[m]
				ok = m;
				l = m+1;
			} else r = m-1;
		}

		// ok eh o ultimo q tenho q operar

		ll pa = (v[i-1] + (v[i-1] + k*(ok-i)) )*(ok-i+1) / 2;
		cout << ' ' << get(sp,i+1,ok)+v[i-1]-pa;

	}

	cout << ' ' << 0 << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
