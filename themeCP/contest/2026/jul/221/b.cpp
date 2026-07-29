#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int no() {
	cout << -1 << '\n';
	return 0;
}

int main() { _
	int n;
	cin >> n;
	
	int v[2*n+1];
	for(int i=1;i<=2*n;i++) cin >> v[i];
	
	short tab[2*n+1][2*n+1];
	short op[2*n+1][2*n+1];
	
	for(int i=1;i<=2*n;i++) for(int j=1;j<=2*n;j++) tab[i][j] = -(i!=j);
	for(int i=1;i<=2*n;i++) {
		queue<int> q;
		q.push(i);

		while(q.size()) {
			int v = q.front();
			q.pop();

			// op1
			int nv = v+1;
			if(v%2==0) nv-=2;

			if(tab[i][nv]==-1) {
				tab[i][nv] = v;
				op[i][nv] = 1;
				q.push(nv);
			}

			// op2
			nv = v+n;
			if(v>n) nv = v-n;

			if(tab[i][nv]==-1) {
				tab[i][nv] = v;
				op[i][nv] = 2;
				q.push(nv);
			}
		}
	}

	//for(int i=1;i<=2*n;i++) {
	//	for(int j=1;j<=2*n;j++) {
	//		cout << tab[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	vector<short> opv;
	int act = v[1];
	for(int i=1;i<=2*n;i++) if(tab[i][v[i]]==-1) return no();
	
	while(act!=1) {
		opv.push_back(op[1][act]);
		act = tab[1][act];
	}

	for(int i=2;i<=2*n;i++) {
		vector<short> penis;
		act = v[i];
		while(act!=i) {
			penis.push_back(op[i][act]);
			act = tab[i][act];
		}
		if(penis!=opv) {
			return no();
			cout << i << "\n";
			for(short cu:opv) cout << cu << ' ';
			cout << '\n';
			for(short cu:penis) cout << cu << ' ';
			cout << '\n';
		}
	}

	cout << opv.size() << '\n';

	
	
	return 0;
}
