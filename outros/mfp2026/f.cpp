#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;

typedef long double ld;

int main() { _
	int n;
	cin >> n;
	ld cem = 100;
	vector<ld> v(n), prob;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		v[i] = x/cem;
	}

	for(int m=0;m<(1<<n);m++) {
		ld p=1;
		for(int i=0;i<n;i++) {
			if(m&(1<<i)) p*=v[i];
			else p*=(1-v[i]);
		}

		prob.push_back(p);
	}

	sort(prob.rbegin(),prob.rend());

	ld ans=0;
	for(ll i=0;i<prob.size();i++) {
		ans+= (i+1)*prob[i];
	}

	cout << fixed << setprecision(10) << ans << '\n';


	return 0;
}
