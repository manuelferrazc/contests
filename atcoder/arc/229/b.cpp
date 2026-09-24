#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void ans(int a) {
	cout << a << '\n';
}

void solve() {
	int n;
	cin >> n;
	ll v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	for(int i=0;i<n-1;i++) if(v[i]<2*v[i+1]) return ans(-1);
	
	ll rem[n];
	fill(rem,rem+n,0ll);

	ll ans2=0;

	for(int i=n-1;i>=0;i--) {
		if(v[i]==0) continue;
		if(i==n-1) ans2++;
		else ans2+=v[i];

		ll qtd = v[i];
		ll r = 0;
		
		for(int j=i;j>=0;j--) {
			v[j]-=qtd;
			qtd = 2*qtd+1;
		}

		for(int j=i-1;j>=0;j--) {
			v[j] = max(v[j],2*v[j+1]);
		}
	}

	ans(ans2);
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
