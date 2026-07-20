#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	ll h,w;
	cin >> h >> w;

	ll bsla = 25*h*h;
	w*=10000;

	if(bsla<=w) cout << "Yes\n";
	else cout << "No\n";

    return 0;
}
