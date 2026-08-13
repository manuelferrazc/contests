#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n,k;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<char> s2(2*n);
	for(int i=0;i<2*n;i++) {
		if(s[i]=='1' and s[(i+1)%(2*n)]=='0') s2[i] = '0';
		else if(s[i]=='1') s2[i] = '1';
		else if(s[(i-1+2*n)%(2*n)]=='1') s2[i] = '1';
		else s2[i] = '0';
	}

	int q1=0,q2=0;

	for(int i=0;i<2*n;i+=2) q1+= s2[i]=='1';
	for(int i=1;i<2*n;i+=2) q2 += s2[i]=='1';

	cout << q2 << ' ' << q1 << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
