#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> lis(vector<int> &v) {
	int n = v.size(), m = -1;
	vector<int> d(n+1,INT_MAX);
	vector<int> l(n);
	d[0] = INT_MIN;

	for(int i=0;i<n;i++) {
		int t = lower_bound(d.begin(),d.end(),v[i])-d.begin();
		d[t] = v[i], l[i] = t, m = max(m,t);
	}
	int p=n;
	vector<int> ret;
	while(p--) if(l[p]==m) {
		ret.push_back(v[p]);
		m--;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}

int main() { _
	int n;
	cin >> n;

	vector<int> p(n);
	for(int i=0;i<n;i++) cin >> p[i];

	vector<int> l1 = lis(p);

	vector<int> p2;
	for(int i=0;i<n;i++) {
		auto it = lower_bound(l1.begin(),l1.end(),p[i]);
		if(it==l1.end() or *it!=p[i]) p2.push_back(p[i]);
	}
	
	vector<int> l2 = lis(p2);

	cout << l1.size()+l2.size() << '\n';
    return 0;
}
