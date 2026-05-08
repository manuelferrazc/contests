#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
	cin >> n;

	set<int> s;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	
	ll ans = n**s.rbegin();

	ll act = 0;
	set<ll> mx;
	n--;
	mx.insert(*s.rbegin());
	while(mx.count(act)) act++;
	ans += act;
	s.erase(*s.rbegin());

	while(n--) {
		if(s.size()) {
			mx.insert(*s.begin());
			s.erase(*s.begin());

			while(mx.count(act)) act++;
		}

		ans+=act;
	}

	cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
