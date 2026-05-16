#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int x,q;
	cin >> x >> q;

	priority_queue<int> left;
	priority_queue<int,vector<int>,greater<int>> right;

	while(q--) {
		int a,b;
		cin >> a >> b;
		if(a>b) swap(a,b);

		if(b<=x) {
			left.push(a);
			left.push(b);
			right.push(x);
			x = left.top();
			left.pop();
		} else if(x<=a) {
			right.push(a);
			right.push(b);
			left.push(x);
			x = right.top();
			right.pop();
		} else {
			left.push(a);
			right.push(b);
		}

		cout << x << '\n';
	}

	return 0;
}
