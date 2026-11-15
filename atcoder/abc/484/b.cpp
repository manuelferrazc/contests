#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	
}

int main() { _
	set<int> s;
	int n;
	cin >> n;

	while(n--) {
		int x;
		cin >> x;
		s.insert(x);
	}

	if(*s.rbegin()!=9) cout << -1 << '\n';
	else cout << *s.begin() << '\n';

	return 0;
}
