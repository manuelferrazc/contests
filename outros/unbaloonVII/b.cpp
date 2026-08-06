#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;


int main() { _
	int n,q;
	cin >> n >> q;

	int v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	while(q--) {
		int op,l,r;
		cin >> op >> l >> r;
		l--;

		if(op==1) {
			int x;
			cin >> x;
			for(int i=l;i<r;i++) v[i]%=x;
		} else if(op==2) {
			int x;
			cin >> x;
			for(int i=l;i<r;i++) v[i] = max(v[i],x);
		} else {
			ll s=0;
			for(int i=l;i<r;i++) s+=v[i];
			cout << s << '\n';
		}
	}

	return 0;
}
