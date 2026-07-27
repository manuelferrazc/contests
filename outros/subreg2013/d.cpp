#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> r,rr;


vector<int> bend(vector<int> &d, int id) {
	//cout << "init = ";
	//print(d);
	vector<int> ret(max(id,(int)d.size()-id));

	for(int i=0;i<id;i++) ret[i] = d[i];
	int ir = ((ll)ret.size())-1;
	
	for(int i = id;i<d.size();i++) {
		ret[ir] += d[i];
		ir--;
	}
	//cout << "end = ";
	//print(ret);
	return ret;
}


void brute(vector<int> d, int f = 0) {
	if(d.size()<r.size()) return;
	if(d.size()==r.size()) {
		if(d==r) {
			cout << "S\n";
			//print(d);
			exit(0);
		}
		//reverse(d.begin(),d.end());
		if(d==rr) {
			cout << "S\n";
			//print(d);
			exit(0);
		} else return;
	}
	//print(d);
	for(int id=1;id<d.size();id++) brute(bend(d,id));
	if(f) return;
	reverse(d.begin(),d.end());
	for(int id=1;id<d.size();id++) brute(bend(d,id),1);
}

int main() { _
	int n,m;
	cin >> n;
	vector<int> d;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		d.push_back(x);
	}

	cin >> m;
	for(int i=0;i<m;i++) {
		int x;
		cin >> x;
		r.push_back(x);
	}

	rr = r;
	reverse(r.begin(),r.end());

	brute(d);
	cout << "N\n";

	return 0;
}
