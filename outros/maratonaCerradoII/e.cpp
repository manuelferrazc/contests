#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define _ ios_base::sync_with_stdio();cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;



int main() { _
	int n;
	const int maxn = 10000001;
	cin >> n;

	map<ll,ll> m;
	ll *cr = new ll[maxn];
	iota(cr,cr+maxn,0);
	for(int i=2;i<maxn;i++) {
		if(cr[i]!=i) continue;
		for(ll j=i+i;j<maxn;j+=i) cr[j] = i;
	}

	for(int fds=0;fds<n;fds++) {
		int x;
		cin >> x;
		while(x>1) {
			m[cr[x]]++;
			x/=cr[x];
		}
	}

	delete[] cr;

	priority_queue<ll> pq;
	for(auto [a,b]:m) {
		ll p = a;
		p*=b;
		pq.push(p);
	}

	ll ans = 0;
	while(pq.size()) {
		ans+=pq.top();
		pq.pop();
		if(pq.size()) pq.pop();
	}

	cout << ans << '\n';

	return 0;
}
