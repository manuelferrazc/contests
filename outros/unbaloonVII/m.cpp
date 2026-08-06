#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;

typedef long double ld;

bool eq(ld x, ld y) {
	return abs(x-y)<=1e-10;
}

ld s(ld x, ld p, ld d) {
	return p*min(1+x,d)+(1-p)*(1+x);
}

int main() { 
	int n;
	cin >> n;
	int dist[n];
	for(int i=0;i<n;i++) cin >> dist[i];

	ld v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	ld l=0, r=1e18;

	while(true) {
		//cout << l << ' ' << r << ' ';
		ld m = (l+r)/2;

		ld x = s(m,v[n-1],dist[n-1]);
		for(int i=n-2;i>=0;i--) x = s(x,v[i],dist[i]);
		//cout << x << ' ' << m << '\n';
		if(eq(x-m,0)) {
			cout << fixed << setprecision(10) << m << '\n';
			break;
		} else if(x>m) l = m;
		else r = m;
	}

	return 0;
}
