#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ull p[19];

#define abs(a,b) (max(a,b)-min(a,b))

void solve() {
	ull a,n;
	cin >> a >> n;

	vector<ull> d(n);
	for(int i=0;i<n;i++) cin >> d[i];

	string as = to_string(a);
	int sz = as.size();
	bool big = false;
	ull val = 0;

	bool ok = true;
	int last = -1;
	
	for(int i=0;i<sz;i++) {
		if(big) val+=d[0]*p[sz-i-1];
		else {
			auto it = lower_bound(d.begin(),d.end(),as[i]-'0');
			if(it==d.end()) {
				ok = false;
				break;
			}
			val += *it*p[sz-i-1];
			if(*it!=d[n-1]) last = i;
			if(*it+'0'>as[i]) big = true;
		}
	}

	ull ans = ULLONG_MAX;

	if(ok) ans = abs(a,val);
	else if(last!=-1) {
		ok = true;
		big = false;
		val = 0;

		for(int i=0;i<sz;i++) {
			if(big) val+=d[0]*p[sz-i-1];
			else {
				auto it = lower_bound(d.begin(),d.end(),as[i]-'0');
				if(i==last) it++;
				
				val += *it*p[sz-i-1];
				if(*it+'0'>as[i]) big = true;
			}
		}
		if(ok) ans = min(ans,abs(a,val));
	}
	
	val = 0;
	int x = 0;
	if(d[0]==0 and n==1) x=-1;
	else if(d[0]==0) x++;
	
	if(x!=-1) {
		val = d[x]*p[sz];
		for(int i=0;i<sz;i++) val+=d[0]*p[sz-i-1];
		ans = min(ans,abs(a,val));
	}
	val = 0;
	for(int i=0;i<sz-1;i++) val += d[n-1]*p[sz-i-2];
	if(sz>1) ans = min(ans,abs(a,val));

	ok = true;
	val = 0;
	bool small = false;
	last = -1;

	for(int i=0;i<sz;i++) {
		if(small) val += d[n-1]*p[sz-i-1];
		else {
			auto it = lower_bound(d.begin(),d.end(),as[i]-'0');
			
			if((it==d.begin() and as[i]-'0'!=*it)) {
				ok = false;
				break;
			}

			if(it==d.end() or as[i]-'0'!=*it) it--;

			val += *it*p[sz-i-1];

			if(*it==as[i]-'0' and *it!=d[0]) last = i;
			else if(*it<as[i]-'0') small = true;
		}
	}


	
	if(ok) ans = min(ans,abs(a,val));
	else if(last!=-1) {
		val = 0;
		small = false;
		ok = true;
		for(int i=0;i<sz;i++) {
			if(small) val += d[n-1]*p[sz-i-1];
			else {
				auto it = lower_bound(d.begin(),d.end(),as[i]-'0');

				if(*it==d[0] and as[i]-'0'!=*it) {
					ok = false;
					break;
				}

				if(as[i]-'0'!=*it) it--;
				if(i==last) it--;
				val+= *it*p[sz-i-1];

				if(*it<as[i]-'0') small = true;
			}
		}

		if(ok) ans = min(ans,abs(a,val));
	}

	cout << (ans) << '\n';
}

int main() { _
	p[0] = 1;
	for(int i=1;i<19;i++) p[i] = p[i-1]*10;

	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
