#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

template<typename T> int matching(T& s, T& t) {
	vector<int> p = pi(s);
    int j=0;
	for (int i = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) break;
	}
	return j;
}

void solve() {
    string s;
    cin >> s;
    string r = s;
    reverse(r.begin(),r.end());
    int x = matching(r,s);
    cout << s + r.substr(x) << '\n';
}

int main() { _
    string s,r;
    cin >> s;

    r = s;
    reverse(r.begin(),r.end());    
    cout << s + r.substr(matching(r,s)) << '\n';
    
    return 0;
}
