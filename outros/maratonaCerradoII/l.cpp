#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define _ ios_base::sync_with_stdio();cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

int ask(int i) {
	println("? {}",i);
	cin >> i;
	return i;
}

int ans(int i) {
	println("! {}",i);
	return 0;
}

int main() {
	int n;
	cin >> n;

	vector<pair<int,int>> inter;

	// indice do usado nessa camada, indice do pai, valor do usado
	array<int,3> v[n+3];
	int x = ask(2);
	v[2] = {2+(x==0),1,x==1?1:-1};
	if(x==0) inter.push_back({3,2});
	
	int an = 1;

	for(int i=3;i<=n+1;i++) {
		int act = v[i-1][0];
		int left = act+i-1;
		int val = ask(left);

		if(val==1) {
			v[i] = {left,act,val};
			an = left;
			if(i==n+1) return ans(left);
		} else {
			v[i] = {left+1,act,-1};
			inter.push_back({left+1,i});
		}
	}

	int l = 0, r = inter.size()-1;

	//for(int i=2;i<=n+1;i++) 
		//cout << i << ": " << v[i][0] << ", pai = "<< v[i][1] << " e o act = " << v[i][2] << '\n';
	

	while(l<=r) {
		int m = (l+r)/2;

		auto [id,cam] = inter[m];
		int val = ask(id);
		
		if(val==1) {
			l = m+1;
			an = id;
			while(v[cam+1][2]==1) {
				an = v[cam+1][0];
				cam++;
			}
		} else {
			if(v[cam-1][2]==1) return ans(v[cam-1][0]);
			r = m-1;
		}
	}

	ans(an);

	return 0;
}
