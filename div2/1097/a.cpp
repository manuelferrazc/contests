#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
   	int n;
   	cin >> n;

   	ll v[n+1];
   	for(int i=0;i<n;i++) cin >> v[i];
	v[n] = 0;

   	int ans = 0;
   	if(v[n-1]>0) ans++;

   	for(int i=n-2;i>=0;i--) {
		v[i] = max(v[i],v[i+1]+v[i]);
   		if(v[i]>0) ans++;
	}

	cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
