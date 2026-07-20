#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int n,m;
	cin >> n >> m;

	int ans[m];
	fill(ans,ans+m,-1);

	for(int i=0;i<n;i++) {
		int c,s;
		cin >> c >> s;
		ans[c-1] = max(ans[c-1],s);
	}

	for(int i=0;i<m;i++) cout << ans[i] << ' ';
	cout << '\n';

    return 0;
}
