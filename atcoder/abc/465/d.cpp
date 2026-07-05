#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	ll x,y,k;
	cin >> x >> y >> k;

	map<ll,int> yy;
	for(ll i=y;;) {
		yy[i] = yy.size();
		if(i==0ll) break;
		i/=k;
	}

	int ans = INT_MAX;
	int qtd=0;
	for(ll i=x;;i/=k) {
		if(yy.count(i)) ans = min(ans,qtd+yy[i]);
		if(i==0ll) break;
		qtd++;
	}

	cout << ans << '\n';
}

int main() { 
	int t;
	cin >> t;
	while(t--) solve();

    return 0;
}
