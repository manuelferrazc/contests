#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;


int main() { _
	int n,q,k;
	cin >> n >> q >> k;

	while(q--) {
		int l,r;
		cin >> l >> r;
		if(k<l) continue;
		if(r<k) k -= r-l+1;
		else k = n - (r-k);
		//cout << k << '\n';
	}

	cout << k << '\n';

	return 0;
}
