#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void ans(bool ok = false) {
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}

void solve() {
	int n;
	string a,b;
	cin >> n >> a >> b;

	stack<char> s1,s2;

	for(int i=0;i<n;i++) {
		if(a[i]==b[i]) {
			if(a[i]=='(') {
				s1.push('(');
				s2.push('(');
			} else {
				if(s1.empty() or s2.empty()) return ans();
				s1.pop();
				s2.pop();
			}
		} else {
			if(s1.size()<s2.size()) swap(s1,s2);
			if(s1.empty()) return ans();
			s1.pop();
			s2.push('(');
		}
	}

	return ans(s1.size()==0 and s2.size()==0);
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
