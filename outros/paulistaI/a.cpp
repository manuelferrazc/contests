#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n,q;
	cin >> n >> q;

	pair<int,int> balada[n]; // ff = custo, ss = estilo
	for(int i=0;i<n;i++) cin >> balada[i].ff >> balada[i].ss;

	map<int,vector<pair<int,int>>> m;
	for(int i=0;i<q;i++) {
		int c,s;
		cin >> c >> s;
		m[s].push_back({c,i});
	}

	priority_queue<pair<int,int>> pq;
	
	for(auto it = m.begin();it!=m.end();it++) {
		sort(it->ss.begin(),it->ss.end());
		pq.push({it->ss.back().ff,it->ff});
	}

	int ans[q];
	fill(ans,ans+q,-1);

	for(int i=0;i<n;i++) {
		pair<int,int> erro(-1,-1);

		while(pq.size()) {
			auto [a,b] = pq.top();
			if(balada[i].ff>a) break;
			pq.pop();

			if(b==balada[i].ss) {
				erro.ff = a;
				erro.ss = b;
				continue;
			}
			auto &v = m[b];
			int id = v.back().ss;
			ans[id] = i+1;
			v.pop_back();

			if(v.size()) pq.push({v.back().ff,b});
		}
		if(erro.ff!=-1) pq.push(erro);
	}
	
	for(int i=0;i<q;i++) cout << ans[i] << '\n';

	exit(0);
}
