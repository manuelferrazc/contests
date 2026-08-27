#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n;
	cin >> n;

	ll v[n];
	for(int i=0;i<n;i++) cin >> v[i];
	sort(v,v+n);
	ll s=0;
	for(int i=0;i<n-1;i++) s+=v[i];
	if(v[n-1]!=0 and (n==1 or s<n)) cout << "Donkey\n";
	else cout << "Puss in Boots\n";

	exit(0);
}
