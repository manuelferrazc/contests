#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
	cout << "NO\n";
}

void yes(int i) {
	cout << "YES\n";
}

void solve() {
	int n;
	cin >> n;

	int v[n+1];
	for(int i=0;i<n;i++) cin >> v[i+1];

	int q1=0;
	int q12=0;

	int diff[n+1];
	fill(diff,diff+n+1,INT_MAX);

	for(int i=1;i<=n;i++) {
		if(v[i]==1) q1++;
		if(v[i]!=3) q12++;
		
		if(q1>=i-q1) diff[i] = q12-(i-q12); // qtd de (1,2) - qtd de 3
		// negativo = tem mais tres
	}

	int mp[n+1];
	mp[1] = diff[1];
	for(int i=2;i<=n;i++) mp[i] = min(mp[i-1],diff[i]);

	//for(int i=1;i<=n;i++) cout << diff[i] << ' ';
	//cout << '\n';
	if(mp[n-2]==INT_MAX) return no();

	q12 = 0;
	int q3 = 0;
	if(v[1]==3) q3++;
	else q12++;

	for(int i=2;i<n;i++) {
		if(v[i]==3) q3++;
		else q12++;

		int d = q3-q12;
		if(mp[i-1]!=INT_MAX and mp[i-1]+d<=0) return yes(i);
	}

	no();
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
