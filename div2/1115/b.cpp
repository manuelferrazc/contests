#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void ans(int i) {
	cout << i << '\n';
}

void solve() {
	int n;
	string s;
	cin >> n >> s;

	if(n<3) return ans(s[0]==s[1]);

	list<char> l;
	for(char c:s) l.push_back(c);

	auto i0 = l.begin(), i1 = l.begin();
	
	int ans2=0;
	bool ok = true;

	while(true) {
		//for(auto it = l.begin();it!=l.end();it++) {
		//	if(it==i0) cout << 'Z';
		//	if(it==i1) cout << 'U';
		//	cout << *it;
		//}
		//cout << '\n';
		if((i0==l.end() or next(i0)==l.end()) and (i1==l.end() or next(i1)==l.end())) break;
		while(i0!=l.end() and next(i0)!=l.end() and (*i0=='1' or *next(i0)=='1')) i0++;
		while(i1!=l.end() and next(i1)!=l.end() and (*i1=='0' or *next(i1)=='0')) i1++;
//for(auto it = l.begin();it!=l.end();it++) {
//			if(it==i0) cout << 'Z';
//			if(it==i1) cout << 'U';
//			cout << *it;
//		}
//		cout << '\n';

		if((i0==l.end() or next(i0)==l.end()) and (i1==l.end() or next(i1)==l.end())) break;
		else if(i0==l.end() or next(i0)==l.end()) {
			if(ok) {
				ans2++;
				ok = false;
			} else {
				if(l.front()=='0') {
					l.pop_front();
					ans2+=2;
				} else if(l.back()=='0') {
					l.pop_back();
					i0 = l.end();
					ans2+=2;
				} else return ans(-1);
			}
			auto x = i1;
			i1++;
			if(i0==x) i0++;
			l.erase(x);
		} else if(i1==l.end() or next(i1)==l.end()) {
			if(ok) {
				ans2++;
				ok = false;
			} else {
				if(l.front()=='1') {
					l.pop_front();
					ans2+=2;
				} else if(l.back()=='1') {
					l.pop_back();
					i1 = l.end();
					ans2+=2;
				} else return ans(-1);
			}
			auto x = i0;
			i0++;
			if(i1==x) i1++;
			l.erase(x);
		} else {
			ans2+=2;
			auto x = i0;
			i0++;
			l.erase(x);
			x = i1;
			if(i0==x) i0++;
			i1++;
			l.erase(x);
		}
	}

	ans(ans2);
}

int main() { 
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
