#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void yes() {
	cout << "YES\n";
}

void solve() {
	string a,b;
	cin >> a >> b;
	int n = a.size();
	
	for(int i=0;i<n-1;i++) 
		if(a[i]=='0' and b[i]=='0' and a[i+1]=='1' and b[i+1]=='1') return yes();
	cout << "NO\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
