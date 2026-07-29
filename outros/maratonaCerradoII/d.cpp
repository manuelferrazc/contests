#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define _ ios_base::sync_with_stdio();cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int n,q;
	cin >> n >> q;

	string s;
	cin >> s;

	vector<int> v(26,INT_MAX);
	for(int i=0;i<n;i++) 
		if(v[s[i]-'a']==INT_MAX) v[s[i]-'a'] = i;

	vector<int> v2(26,INT_MAX);
	for(int i=0;i<26;i++) 
		for(int j=0;j<26;j++) if(i!=j) v2[i] = min(v2[i],v[j]);

	while(q--) {
		string t;
		cin >> t;
		int m = t.size();

		int ans = max(n,m);
		for(int i=0;i<m;i++) {
			if(v2[t[i]-'a']==INT_MAX) continue;
			ans = max(ans,m-i + n-v2[t[i]-'a']);
		}

		cout << ans << '\n';
	}

	return 0;
}
