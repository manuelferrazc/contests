#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int n,m;
	cin >> n >> m;

	set<int> c[n],r[n];

	while(m--) {
		int cc,rr;
		cin >> rr >> cc;
		cc--;
		rr--;
	
		vector<int> torem;
		for(int i:c[cc]) torem.push_back(i);

		for(int i:r[rr]) {
			c[i].erase(rr);
		}
		r[rr].clear();

		for(int i:torem) {
			r[i].erase(cc);
		}
		c[cc].clear();

		c[cc].insert(rr);
		r[rr].insert(cc);

		//for(int i=0;i<n;i++) {
		//	cout << "col " << i << ": ";
		//	for(int sla:c[i]) cout << sla << ' ';
		//	cout << '\n';
		//}
		//for(int i=0;i<n;i++) {
		//	cout << "row " << i << ": ";
		//	for(int cu:r[i]) cout << cu << ' ';
		//	cout << '\n';
		//}
//		cout << '\n';
	}

	int ans = 0;
	for(int i=0;i<n;i++) ans += c[i].size();
	cout << ans << '\n';

    return 0;
}
