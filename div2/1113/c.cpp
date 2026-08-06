#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n;
	cin >> n;

	int v[2*n];
	int f[n],s[n];
	fill(f,f+n,-1);

	for(int i=0;i<2*n;i++) {
		int x;
		cin >> x;
		x--;
		v[i] = x;
		if(f[x]==-1) f[x] = i;
		else s[x] = i;
	}

	ll pref[2*n], suf[2*n];
	pref[0] = 1;
	for(int i=1;i<2*n;i++) {
		pref[i] = pref[i-1]+1;
		if(i==s[v[i]]) {
			ll l = i-f[v[i]]+1;

			if(f[v[i]]==0) pref[i] = max(pref[i],l*l);
			else pref[i] = max(pref[i],l*l+pref[f[v[i]]-1]);
		}
	}

	suf[2*n-1] = 1;
	

	cout << pref[2*n-1] << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
