#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
	int n;
	cin >> n;

	int v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	stack<pair<int,int>> s;

	s.push(pair(0,-1));
	int ans = 1;

	for(int i=0;i<n;i++) {
		pair<int,int> l(-1,-1);
		while(s.top().ff>v[i]) {
			ans = max(ans,min(s.top().ff,i-s.top().ss));
			l = s.top();
			s.pop();
		}

		if(l.ff==-1) s.push(pair(v[i],i));
		else s.push(pair(v[i],l.ss));
	}

	while(s.size()>1) {
		ans = max(ans,min(s.top().ff,n-s.top().ss));
		s.pop();
	}

	cout << ans << '\n';

    return 0;
}
