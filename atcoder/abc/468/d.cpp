#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	string s;
	cin >> s;
	int n = s.size();

	int ans=0;

	for(int i=0;i<n;i++) {
		ans++;
		bool erro = false;
		for(int j=1;i+j<n and i-j>=0;j++) {
			if(s[i+j]==s[i-j]) ans++;
			else if(not erro) {
				ans++;
				erro = true;
			} else break;
		}
		
		if(i==n-1) break;
		ans++;
		erro = s[i]!=s[i+1];
		for(int j=1;i-j>=0 and i+j+1<n;j++) {
			if(s[i-j]==s[i+j+1]) ans++;
			else if(not erro) {
				ans++;
				erro = true;
			} else break;
		}
	}

	cout << ans << '\n';

    return 0;
}
