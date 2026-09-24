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
	string s;
	cin >> s;

	stack<int> st,nst;
	int n=0;
	
	for(char c:s) {
		if(c=='+') {
			n++;
			bool b = false;
			while(st.size() and st.top()>=n) {
				st.pop();
				b = true;
			}

			if(b and (st.empty() or st.top()!=n-1)) st.push(n-1);
		}
		else if(c=='-') {
			if(n==0) return no();
			if(nst.size() and nst.top()==n) nst.pop();
			n--;
		}
		else if(c=='1') { // sorted
			if(nst.size()) return no();
			if(st.empty() or st.top()<n) st.push(n);
		} else { // unsorted
			if(n<=1 or (st.size() and st.top()>=n)) return no();
			if(nst.empty() or nst.top()<n) nst.push(n);
		}
	}

	cout << "YES\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
