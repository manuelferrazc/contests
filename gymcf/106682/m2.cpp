#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
	int n,m;
	cin >> n >> m;

	ll v[n];
	for(int i=0;i<n;i++) cin >> v[i];
	ll v2[n];
	for(int i=0;i<n;i++) v2[i] = 0;

	while(m--) {
		int op;
		cin >> op;

		if(op==1) {
			ll b,qtd;
			cin >> b >> qtd;
			b--;

			for(int i=b;i>=0 and qtd>=0;i--) {
				ll av = v[i] - v2[i];
				ll placed = min(av,qtd);

				qtd -= placed;
				v2[i] += placed;
			}
		} else {
			int l,r;
			cin >> l >> r;
			
			l--;
			r--;
			ll ans = 0;

			for(int i=l;i<=r;i++) {
				ans+=v2[i];
				v2[i] = 0;
			}

			cout << ans << '\n';
		}
	}

	return 0;
}
