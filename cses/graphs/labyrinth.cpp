#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m;
vector<string> v;
vector<vector<char>> path;

const pair<int,int> dd[] = {{1,0},{-1,0},{0,1},{0,-1}};

bool bfs(int i, int j) {
	queue<pair<int,int>> q;
	q.push({i,j});

	while(not q.empty()) {
		auto p = q.front();
		q.pop();

		for(int a=0;a<4;a++) {
			auto const &d = dd[a];
			int x = p.ff+d.ff,y=p.ss+d.ss;
			if(x<0 or x>=n or y<0 or y>=m or path[x][y]!='x' or v[x][y]=='#') continue;
			
			if(a==0) path[x][y] = 'D';
			else if(a==1) path[x][y] = 'U';
			else if(a==2) path[x][y] = 'R';
			else path[x][y] = 'L';

			if(v[x][y]=='B') return true;
			q.push({x,y});
		}
	}
	return false;
}

int main() { 
	cin >> n >> m;
	v.resize(n);
	path.assign(n,vector<char>(m,'x'));
	for(string &s:v) cin >> s;
	
	pair<int,int> p1,p2;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(v[i][j]=='A') {
				p1.ff=i;
				p1.ss=j;
			} else if(v[i][j]=='B') {
				p2.ff=i;
				p2.ss=j;
			}
		}
	}

	
	if(bfs(p1.ff,p1.ss)) {
		string s;
		auto [a,b] = p2;
		
		while(a!=p1.ff or b!=p1.ss) {
			s.push_back(path[a][b]);
			if(path[a][b]=='D') a--;
			else if(path[a][b]=='U') a++;
			else if(path[a][b]=='R') b--;
			else b++;
		}

		reverse(s.begin(),s.end());
		cout << "YES\n" << s.size() << '\n' << s << '\n';;
	} else cout << "NO\n";

	return 0;
}
