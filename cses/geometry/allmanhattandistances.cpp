#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void print(__int128 x) {
    if (x > 9) print(x / 10);
    cout << (int)(x % 10);
}

int main() { _
	__int128 ans=0, sx=0, sy=0;
	int n;
	cin >> n;

	__int128 x[n],y[n];

	for(int i=0;i<n;i++) {
		ll a,b;
		cin >> a >> b;
		x[i] = a;
		y[i] = b;
		sx+=x[i];
		sy+=y[i];
	}

	sort(x,x+n);
	sort(y,y+n);

	for(ll i=0;i<n;i++) {
		sx-=x[i];
		ans+=sx-x[i]*(__int128)(n-i-1);

		sy-=y[i];
		ans+=sy-y[i]*(__int128)(n-i-1);
	}
	
	print(ans);
	cout << '\n';

	return 0;
}
