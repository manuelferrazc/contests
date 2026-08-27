#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	ll n,k;
	ull s;
	cin >> n >> k >> s;

	while(n--) {
		ull ant = 0;
		for(ll i=0;i<k;i++) ant += s&(1ull<<i);

		for(ll i=k;i<=60;i++) {
			bool si = ((s>>i)&1ull) == 1ull;
			bool antik = ((ant>>(i-k))&1ull) == 1ull;

			if(si != antik) ant += 1ull<<i;
		}

		s = ant%(1ull<<32);
	}

	cout << s << '\n';

	exit(0);
}
