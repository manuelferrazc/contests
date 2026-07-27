#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


vector<pair<int,int>> calc(vector<int> v) {
	vector<int> aux;
	for(int i:v) aux.push_back(i);
	sort(aux.begin(),aux.end());
	for(int i=0;i<v.size();i++)
		v[i] = lower_bound(aux.begin(),aux.end(),v[i]) - aux.begin();
	
	vector<pair<int,int>> r;
 	int n = v.size();
	for(int i=0;i<n;i++) {
		while(v[i]!=i) {
			r.push_back(pair(i,v[i]));
			swap(v[i],v[v[i]]);
		}
	}

	return r;
}

void print(int n, int m,int v[100][100]) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) cout << v[i][j] << ' ';
		cout << '\n';
	}
}

int main() { _
	int n,m;
	cin >> n >> m;

	int v[n][m];
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) cin >> v[i][j];
	}

	vector<int> vl(m), vc(n);
	for(int i=0;i<m;i++) vl[i] = v[0][i];
	for(int i=0;i<n;i++) vc[i] = v[i][0];

	//cout << "linhas f\n";
	//for(int i:vl) cout << i << ' ';
	//cout << '\n';
	//for(int i:vc) cout << i << ' ';
	//cout << '\n';

	vector<pair<int,int>> sl = calc(vl), sc = calc(vc);
	//cout << "V:\n";
	//print(n,m,v);
	for(auto [l1,l2]:sc) {
		for(int j=0;j<m;j++) swap(v[l1][j],v[l2][j]);
	}
	//cout << "\nv dps das linhas\n";
	//print(n,m,v);

	for(auto [c1,c2]:sl) {
		for(int i=0;i<n;i++) swap(v[i][c1],v[i][c2]);
	}
	//cout << "\nv dps das cols\n";
	//print(n,m,v);

	int act = 1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(v[i][j]!=act) {
				cout << "*\n";
				return 0;
			}
			act++;
		}
	}

	cout << sc.size()+sl.size() << '\n';

	return 0;
}
