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
	int n;
	cin >> n;

	list<int> a,b;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}

	while(a.size() and a.front()==b.front()) {
		a.pop_front();
		b.pop_front();
	}

	while(a.size() and a.back()==b.back()) {
		a.pop_back();
		b.pop_back();
	}
	
	bool ok = false;
	if(a.size()) {
		a.push_back(a.front());
		a.pop_front();

		if(a==b) ok = true;

		for(int i=0;i<2;i++) {
			a.push_front(a.back());
			a.pop_back();
		}

		if(a==b) ok = true;
	} else ok = true;

	if(ok) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
