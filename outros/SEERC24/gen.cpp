#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(int argc, char ** argv) { _
	srand(atoi(argv[1]));

	int n = 1+rand()%10;
	int q = 1+rand()%10;

	cout << n << ' ' << q << '\n';

	for(int i=0;i<n;i++) cout << (char)(rand()%26+'a');
	cout << '\n';

	while(q--) {
		int op = rand()%2+1;
		int r = rand()%n+1;
		int l = 1+rand()%r;

		if(op==1) cout << op << ' ' << l << ' ' << r << '\n';
		else cout << op << ' ' << r << '\n';
	}

	exit(0);
}
