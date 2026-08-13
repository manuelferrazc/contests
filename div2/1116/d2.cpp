#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

set<string> st;

void dfs(string &s) {
	if(st.count(s)) return;
	st.insert(s);
	
	int n = s.size();
	for(int i=0;i<n-2;i++) for(int j=i+2;j<n;j++) {
		if(s[i]==s[j]) {
			string s2(n,',');
			for(int k=0;k<i;k++) s2[k] = s[k];
			for(int k=i;k<=j;k++) s2[k] = s[j-(k-i)];
			for(int k=j+1;k<n;k++) s2[k] = s[k];
			dfs(s2);
		}
	}
}

void solve() {
	int n;
	string s;
	cin >> n >> s;
	st.clear();

	dfs(s);
	cout << st.size() << '\n';
	for(string ss:st) cout << ss << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
