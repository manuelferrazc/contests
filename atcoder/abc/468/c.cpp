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

	int v[n];
	iota(v,v+n,1);

	int p[n],q[n];
	for(int i=0;i<n;i++) cin >> p[i];
	for(int i=0;i<n;i++) cin >> q[i];

	int ans=0;

	do {
		bool ok = true;
		for(int i=0;i<n;i++) {
			if(v[i]!=p[i]) {
				if(v[i]<p[i]) ok = false;
				break;
			}
			if(i==n-1) ok = false;
		}

		if(ok==false) continue;
		for(int i=0;i<n;i++) {
			if(v[i]!=q[i]) {
				if(v[i]>q[i]) ok = false;
				break;
			}
			if(i==n-1) ok = false;
		}

		if(ok) ans++;

	} while (next_permutation(v,v+n));

	cout << ans << '\n';

    return 0;
}
