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

void solve() {
	int n;
	string s;
	cin >> n >> s;

	int q=0;
	for(int i=0;i<n;i++) if(s[i]=='1') q++;
	if(q&1) return no();

	if(q==2) 
		for(int i=1;i<n;i++) if(s[i]=='1' and s[i-1]=='1') return no();
	
	cout << "YES\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
