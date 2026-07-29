#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
	cout << "YES\n";
}

bool ok(int *v, int n, int k) {
	int v2[n+2];
	fill(v2,v2+n+2,-1);

	for(int i=1;i<=n;i++) {
		if(v[i]<k) {
			if(v2[i-1]!=-1) return false;
			v2[i-1] = v[i];
		} else {
			if(v2[i+1]!=-1) return false;
			v2[i+1] = v[i];
		}
	}

	for(int i=1;i<=n;i++) if(v2[i]==-1) return false;
	return true;
}

void solve() {
	int n;
	cin >> n;
	int v[n+2];
	v[0] = v[n+1] = 0;
	for(int i=1;i<=n;i++) cin >> i[v];
	set<int> s;
	for(int i=1;i<=n;i++) s.insert(v[i]+1);
	for(int i=1;i<=n;i++) s.insert(v[i]-1);
	for(int i=1;i<=n;i++) s.erase(v[i]);
	
	for(int k:s) if(ok(v,n,k)) return no();

	cout << "NO\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
