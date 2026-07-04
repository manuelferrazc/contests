#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int x,y,l,r,a,b;
	cin >> x >> y >> l >> r >> a >> b;

	int ans = 0;
	for(int i=a;i<b;i++) {
		if(l<=i and i<r) ans+=x;
		else ans+=y;
	}

	cout << ans << '\n';

    return 0;
}
