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

	vector<int> adj[n];
	vector<int> v(n,0);
	while(m--) {
		int a,b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		v[b-1]++;
	}
	
	queue<int> q;
	for(int i=0;i<n;i++) if(v[i]==0) q.push(i);

	vector<int> ans;
	while(q.size()) {
		ans.push_back(q.front()+1);
		
		for(auto i:adj[q.front()]) {
			v[i]--;
			if(v[i]==0) q.push(i);
		}
		q.pop();
	}

	if(ans.size()==n) for(int i:ans) cout << i << ' ';
	else cout << "IMPOSSIBLE";
	
	cout << '\n';

	return 0;
}
