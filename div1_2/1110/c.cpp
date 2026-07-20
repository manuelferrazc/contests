#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
	cout << "No\n";
}

void solve() {
	ll n,k;
	cin >> n >> k;
	if(n==1) {
		if(k==1) cout << "Yes\n0\n";
		else cout << "No\n";
		return;
	}	
	ll kn = k^n;

	bool sk[n];
	fill(sk,sk+n,false);
	sk[0] = true;
	for(int i=0;i<35;i++) {
		if(((kn>>i)&1) and (1ll<<i)>n) return no();
		if((kn>>i)&1 and (1ll<<i)<n) sk[(1ll<<i)] = true;
	}

	vector<int> v;
	for(int i=0;i<n;i++) {
		if(sk[i]==false) {
			//if(sk2==-1) sk2 = i;
			/*else*/ v.push_back(i);
		}
	}
	int x=n;
	int s = v.size();
	for(int i=0;i<n;i++) if(sk[i]) v.push_back(i);
	for(int i = s;i<n-1;i++) {
		x ^= v[i+1];
	}

	if(x!=k) return no();

	cout << "Yes\n";
	for(int i=0;i<n;i++) cout << v[i] << ' ';
	cout << '\n';

}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
