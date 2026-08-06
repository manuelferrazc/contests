#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;

#define MAX 1'000'001

int main() { _
	int n;
	cin >> n;

	bool c[MAX];
	fill(c,c+MAX,false);
	for(int i=2;i<MAX;i++) {
		if(c[i]) continue;
		for(int j=i+i;j<MAX;j+=i) c[j] = true;
	}

	int ans = 0;
	for(int i=2;i<=n;i++) if(not c[i]) ans++;
	cout << ans << '\n';

	return 0;
}
