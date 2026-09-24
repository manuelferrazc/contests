#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define ff first
#define ss second

using ll = long long int;
using ld = long double;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
#define int ll


signed main() {
	int n, K;
	cin >> n >> K;
	
	while(n--) {
		int h;
		cin >> h;

		if(h%4) {
			cout << -1 << '\n';
			continue;
		}

		int k = K;
		
		bool ok = true;
		vector<int> ans;

		while(h) {
			if(k==2) {
				if(h==4 or h==8 or h==12) ans.push_back(min(h,8ll));
				else ok = false;
				break;
			}

			bool ok2 = false;

			ll kmax = (1ll<<(k+1))*k - 4;
			ll kmin = (1ll<<(k+1))*(k-1);

			if(kmin<=h) {
				h = max(0ll,h-kmax);
				ans.push_back(1ll<<(k+1));
				k--;
				continue;
			}

			for(int t = k;t>=2;t--) {
				kmax = (1ll<<(t))*(t-1);
				kmin = (1ll<<(t))*(t-2);

				if(kmin<=h) {
					h = max(0ll,h-kmax);
					ans.push_back(1ll<<t);
					k--;
					ok2=true;
					break;
				}
			}

			if(ok2==false) {
				
				ok = false;
				break;
			}
		}


		if(ok==false) {
			cout << -1 << '\n';
			continue;
		}

		cout << ans.size() << ' ';
		for(int i:ans) cout << i << ' ';
		cout << '\n';
	}

	return 0;
}

