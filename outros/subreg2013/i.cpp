#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
	int n,c,t1,t2;
	cin >> n >> c >> t1 >> t2;

	vector<int> v(2*n);
	for(int i=0;i<n;i++) cin >> v[i];

	for(int i=0;i<n;i++) v[n+i] = c+v[i];
	vector<pair<int,int>> adj[n+n];
	for(int i=0;i<2*n;i++) {
		auto it = upper_bound(v.begin(),v.end(),v[i]+t1);
		if(it!=v.end()) adj[i].push_back(pair(it-v.begin(),t1));

		auto it2 = upper_bound(v.begin(),v.end(),v[i]+t2);
		if(it2!=v.end() and it!=it2) adj[i].push_back(pair(it2-v.begin(),t2));
		else if(it2!=v.end()) adj[i].back().ss = min(adj[i].back().ss,t2);
	}

	vector<vector<int>> dist(2*n,vector<int>(2*n,INT_MAX));

	for(int i=2*n-1;i>=0;i--) {
		dist[i][i] =0;
		for(auto [u,w]:adj[i]) {
			for(int sla = i+1;sla<2*n;sla++)
				if(dist[u][sla]!=INT_MAX)
					dist[i][sla] = min(dist[i][sla],dist[u][sla]+w);

		}
	}

	int ans = INT_MAX;
	for(int i=0;i<n;i++) {
		for(int j = i+n;j<2*n;j++) ans = min(ans,dist[i][j]);
	}

	cout << ans << '\n';

	return 0;
}
