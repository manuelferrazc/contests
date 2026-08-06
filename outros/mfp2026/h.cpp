#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;


int main() { _
	int n,q;
	cin >> n >> q;

	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];

	while(q--) {
		int p;
		cin >> p;

		// o primeiro maior (p seria indice id-0.5)
		int id = lower_bound(v.begin(),v.end(),p) - v.begin();

		int ans = INT_MAX;
		if(id==n) ans = p-v[n-2];
		else if(id==0) ans = v[1]-p;
		else {
			ans = v[id]-v[id-1];
			if(id>1) ans = min(ans,p-v[id-2]);
			if(id<n-1) ans = min(ans,v[id+1]-p);
		}

		cout << ans << '\n';
	}

	return 0;
}
