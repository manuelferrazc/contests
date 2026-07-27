#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;



int main() { _
	int n;
	cin >> n;
	set<ll> s;

	ll act = 0;
	//s.insert(0);
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		act+=x;
		s.insert(act);
	}

	int ans = 0;

	if(act%3==0) {
		ll l = act/3;
		for(ll i:s) {
			if(i+2*l>act) break;
			if(s.count(i+l) and s.count(i+2*l)) ans++;
		}
	}
	
	cout << ans << '\n';

	return 0;
}
