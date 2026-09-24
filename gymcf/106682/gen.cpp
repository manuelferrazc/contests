#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAXN 1000
#define MAXM 7000
#define MAXV 1'000'000'000

int main(int argc, char**argv) { _
	srand(atoi(argv[1]));

	int n = 1 + rand()%MAXN;
	int m = 1 + rand()%MAXM;

	cout << n << ' ' << m << '\n';

	for(int i=0;i<n;i++) cout << 1+rand()%MAXV << ' ';
	cout << '\n';

	while(m--) {
		int op = 1 + rand()%2;

		if(op==1) {
			int v = 1+rand()%MAXV;

			int b = 1 + rand()%n;

			cout << op << ' ' << b << ' ' << v << '\n';
		} else {
			int r = 1+rand()%n;
			int l = 1+rand()%r;

			cout << op << ' ' << l << ' ' << r << '\n';
		}
	}

	return 0;
}
