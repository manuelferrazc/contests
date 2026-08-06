#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no(int i = 0) {
	cout << " No\n";
}

void solve() {
	int n,m;
	cin >> n >> m;

	int a[n],b[m];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	sort(a,a+n);
	sort(b,b+m);

	if(m*2>n or b[0]<a[0] or b[m-1]>a[n-1]) return no(1);

	for(int i=0;i<m;i++) if(b[i]<a[i]) return no(2);
	for(int i=m-1;i>=0;i--) if(b[i]>a[n-m+i]) return no(3);
	cout << "Yes\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
