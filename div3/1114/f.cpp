#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void ans(bool ok) {
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}

void solve() {
	int n;
	cin >> n;

	int a[n],b[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];

	sort(a,a+n);
	sort(b,b+n);

	int xa=0,xb=0;
	bool ok = true;
	for(int i=0;i<n;i++) {
		xa^=a[i];
		xb^=b[i];
		if(a[i]!=b[i]) ok = false;
	}

	if(ok) return ans(true);
	if(xa==xb) return ans(false);

	int x = xa^xb;
	for(int i=0;i<n;i++) a[i]^=x;
	sort(a,a+n);
	if(a[0]!=0) return ans(false);
	
	ok = false;
	for(int i=0;i<n;i++) {
		if(b[i]==x) {
			b[i] = 0;
			ok = true;
			break;
		}
	}

	if(ok==false) return ans(false);
	sort(b,b+n);
	for(int i=1;i<n;i++) if(b[i]!=a[i]) return ans(false);
	ans(true);
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
