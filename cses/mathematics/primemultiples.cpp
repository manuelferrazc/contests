#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
	ll n,k;
	cin >> n >> k;

	vector<ull> p(k);
	for(int i=0;i<k;i++) cin >> p[i];
	sort(p.begin(),p.end());

	p.erase(unique(p.begin(),p.end()),p.end());
	k = p.size();

	ll ans = 0;

	for(int m=1;m<(1<<k);m++) {
		ull num = 1;
		int q=0;
		bool overflow = false;

		for(int i=0;i<k;i++) {
			if(m&(1<<i)) {
				ull num2 = num*p[i];
				q++;

				if(num2%num or num2%p[i] or num2/num!=p[i]) {
					overflow = true;
					break;
				}
				num = num2;
			}
		}

		if(overflow) continue;
		if(q&1) ans += n/num;
		else ans -= n/num;
	}

	cout << ans << '\n';

	return 0;
}
