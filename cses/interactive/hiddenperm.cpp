#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() {
	int n;
	cin >> n;

	vector<int> v(n,1);
	iota(v.begin(),v.end(),1);

	for(int i=1;i<=n;i++) {
		int l=0,r=v.size()-2,ans=v.size();

		while(l<=r) {
			int m = (l+r)>>1;
			cout << "? " << i << ' ' << v[m] << '\n';
			cout.flush();
			string s;
			cin >> s;

			if(s[0]=='Y') {
				ans = m;
				l=m+1;
			} else 
			r=m-1;
			// cout << l << r << '\n';
		}

		// cout << "ababa\n";

		int j = v.back();
		v.pop_back();
		v.insert(v.begin()+ans,j);
		// for(int i:v) cout << i << ' ';
	// cout << '\n';
	}

	cout << "! ";
	for(int i:v) cout << i << ' ';
	cout << '\n';
	cout.flush();

	return 0;
}
