#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

short t[8][8];
short qtd[8][8];

const pair<short,short> adj[] = {pair(2,1),pair(1,2),pair(-1,2),pair(2,-1),pair(1,-2),pair(-2,1),pair(-1,-2),pair(-2,-1)};

bool find(short x, short y, short o) {
	t[x][y] = o;
	if(o==64) return true;

	vector<array<short,3>> v;

	for(auto [a,b]:adj) {
		short x2 = x+a,y2=y+b;
		if(x2<0 or x2>=8 or y2<0 or y2>=8 or t[x2][y2]!=-1) continue;
		qtd[x2][y2]--;
		v.push_back({qtd[x2][y2],x2,y2});
	}

	sort(v.rbegin(),v.rend());

	while(v.size()) {
		auto [lixo,x2,y2] = v.back();
		v.pop_back();

		if(::find(x2,y2,o+1)) return true;
	}

	for(auto [a,b]:adj) {
		short x2 = x+a,y2=y+b;
		if(x2<0 or x2>=8 or y2<0 or y2>=8 or t[x2][y2]!=-1) continue;
		qtd[x2][y2]++;
	}

	t[x][y] = -1;
	return false;
}

int main() { _
    int x,y;
	cin >> x >> y;
	x--;
	y--;
	
	for(int i=0;i<8;i++) for(int j=0;j<8;j++) t[i][j] = -1;
	for(int i=0;i<8;i++) for(int j=0;j<8;j++) qtd[i][j] = 0;

	for(int i=0;i<8;i++) for(int j=0;j<8;j++) {
		for(auto [a,b]:adj) {
			int x = i+a,y=j+b;
			if(x>=0 and x<8 and y>=0 and y<8) qtd[x][y]++;
		}
	}


	::find(x,y,1);

	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) cout << t[j][i] << ' ';
		cout << '\n';
	}

	return 0;
}
