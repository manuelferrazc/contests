#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;


int main() { _
	int n,m,k,ans=0;
	cin >> n >> m >> k;

	bool r[n+1];
	fill(r,r+n+1,false);
	for(int i=0;i<m;i++) {
		int x;
		cin >> x;
		r[x] = true;
	}

	int last = 0; // ultima protegida
	for(int i=1;i<=n;i++) {
		if(r[i] or i==n) {
			if(last<i) ans++;
			last = i;
		} else if(i-last>k) {
			ans++;
			last = i+k;
		}
	}

	cout << ans << '\n';

	return 0;
}
