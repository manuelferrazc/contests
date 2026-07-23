#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define _ ios_base::sync_with_stdio();cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for(int i=1,j=0;i<s.size();i++) {
		while(j and s[j]!=s[i]) j = p[j-1];
		if(s[j]==s[i])j++;
		p[i]=j;
	}
	return p;
}

template<typename T> map<int,int> matching(vector<int> &p,T &s, T &t) {
	map<int,int> match;
	for(int i=0,j=0;i<t.size();i++) {
		while(j and s[j]!=t[i]) {
			if(not match.count(j)) match[j] = i;
			j = p[j-1];
		}
		if(s[j]==t[i]) j++;
		else if(not match.count(j)) match[j] = i;
		if(j==s.size()) {
			if(not match.count(j)) match[j] = i;
			j=p[j-1];
		}
		if(i==t.size()-1 and not match.count(j)) match[j] = i;
	}
	return match;
}

int main() { _
	int n,q;
	cin >> n >> q;

	string s;
	cin >> s;

	vector<int> p = pi(s);

	while(q--) {
		string t;
		cin >> t;
		map<int,int> m = matching(p,s,t);

		print("s = {}, f = {}, rets = ",s,t);
		for(auto [a,b] : m) print("({} {}) ",a,b);
		println();
	}

	return 0;
}
