#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int m,d;
	string s;
	cin >> m >> d >> s;
	int suf[m],pref[m];

	if(s[0]=='.') pref[0] = 1000000;
	else pref[0] = 0;
	for(int i=1;i<m;i++) {
		if(s[i]=='.') pref[i] = pref[i-1]+1;
		else pref[i] = 0;
	}

	if(s.back()=='.') suf[m-1] = 10000000;
	else suf[m-1] = 0;
	for(int i=m-2;i>=0;i--) {
		if(s[i]=='.') suf[i] = suf[i+1]+1;
		else suf[i] = 0;
	}

	int ans=0;
	for(int i=0;i<m;i++) if(min(pref[i],suf[i])>d) ans++;

	cout << ans << '\n';
    return 0;
}
