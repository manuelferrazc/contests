#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m;
vector<string> v;

const pair<int,int> dd[] = {{1,0},{-1,0},{0,1},{0,-1}};

void bfs1(queue<pair<int,int>> &q,vector<vector<int>> &dist) {
	while(not q.empty()) {
		pair<int,int> p = q.front();
		q.pop();

		for(const auto &i:dd) {
			int x = p.ff+i.ff, y=p.ss+i.ss;
			if(x<0 or y<0 or x>=n or y>=m or v[x][y]=='#' or dist[x][y]!=INT_MAX) continue;
			dist[x][y] = dist[p.ff][p.ss]+1;
			q.push(make_pair(x,y));
		}
	}
}

void bfs2(vector<vector<int>> &dm, vector<vector<char>> &path, int i, int j) {
	queue<pair<int,int>> q;
	vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
	dist[i][j] = 0;

	q.push(make_pair(i,j));
	while(not q.empty()) {
		auto p = q.front();
		q.pop();

		for(int a=0;a<4;a++) {
			int x = p.ff+dd[a].ff,y=p.ss+dd[a].ss;
			if(x<0 or x>=n or y<0 or y>=m or v[x][y]=='#' or dist[x][y]!=INT_MAX) continue;

			dist[x][y]=dist[p.ff][p.ss]+1;
			if(dist[x][y]>=dm[x][y]) continue;
			if(a==0) path[x][y] = 'D';
			else if(a==1) path[x][y] = 'U';
			else if(a==2) path[x][y] = 'R';
			else path[x][y] = 'L';

			q.push({x,y});
		}
	}
}

int main() { 
    cin >> n >> m;
	v.resize(n);
	for(string &s:v) cin >> s;

	vector<vector<int>> dm(n,vector<int>(m,INT_MAX));
	queue<pair<int,int>> q;
	pair<int,int> s,e = {-1,-1};
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(v[i][j]=='M') {
				dm[i][j] = 0;
				q.push(make_pair(i,j));
			} else if(v[i][j]=='A') s = make_pair(i,j);
		}
	}

	bfs1(q,dm);

	vector<vector<char>> path(n,vector<char>(m,'x'));
	bfs2(dm,path,s.ff,s.ss);

	for(int i=0;i<n;i++) {
		if(v[i][0]=='A' or v[i][m-1]=='A') {
			cout << "YES\n0\n";
			return 0;
		}
	}
	for(int i=0;i<m;i++) {
		if(v[0][i]=='A' or v[n-1][i]=='A') {
			cout << "YES\n0\n";
			return 0;
		}
	}

	for(int i=0;i<n;i++) {
		if(v[i][0]=='.' and path[i][0]!='x') {
			e = make_pair(i,0);
			break;
		}
		if(v[i][m-1]=='.' and path[i][m-1]!='x') {
			e = make_pair(i,m-1);
			break;
		}
	}

	for(int i=0;i<m;i++) {
		if(v[0][i]=='.' and path[0][i]!='x') {
			e = make_pair(0,i);
			break;
		}

		if(v[n-1][i]=='.' and path[n-1][i]!='x') {
			e = make_pair(n-1,i);
			break;
		}
	}

	if(e.ff==-1) cout << "NO\n";
	else {
		string st;
		int a=e.ff,b=e.ss;

		while(a!=s.ff or b!=s.ss) {
			st.push_back(path[a][b]);

			if(st.back()=='U') a++;
			else if(st.back()=='D') a--;
			else if(st.back()=='L') b++;
			else b--;
		}

		reverse(st.begin(),st.end());
		cout << "YES\n" << st.size() << '\n' << st << '\n';
	}
	
	return 0;
}
