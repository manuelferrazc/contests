#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
#define int ll

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform (int l, int r) {
	uniform_int_distribution<int> uid(l,r);
	return uid(rng);
}

#define MAX 1'000'000'000

signed main() { _
	int n = uniform(1,10);
	int f = uniform(1,MAX);

	cout << "1\n";
	cout << n << ' ' << f << '\n';
	for(int i=0;i<n;i++) {
		int a = uniform(1,MAX);
		int b = uniform(1,MAX);
		if(a>b) swap(a,b);
		if(a==b) {
			i--;
			continue;
		}

		cout << a << ' ' << b << '\n';
	}

	return 0;
}
