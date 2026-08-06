#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;


int main() { _
	ll n,m;
	cin >> n >> m;

	vector<int> c(m+1,0);
	ll s=0;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		c[x]++;
		s+=x;
	}

	for(int i=0;i<m;i++) {
		while(c[i]) {
			c[i]--;
			s-=i;
		}

		cout << s << ' ';
	}

	cout << '\n';

	return 0;
}
