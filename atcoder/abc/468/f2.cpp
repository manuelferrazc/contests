#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int ans = 0;
int v[1000];
int n;

void eval(int *op) {
	int ans2 = 0;
	int x = 0,y=0;
	for(int i=0;i<n;i++) {
		if(op[i]==1) {
			if(x>=v[i]) return;
			ans2++;
			x = v[i];
		} else if(op[i]==2) {
			if(y>=v[i]) return;
			ans2++;
			y = v[i];
		}
	
	}
	//cout << "penis\n";
	ans = max(ans,ans2);
	if(false and ans==ans2) {
		for(int i=0;i<n;i++) cout << op[i] << ' ';
		cout << endl;
	}
}

void brute(int *op, int i) {
	if(i==n) return eval(op);
	for(int j=0;j<3;j++) {
		op[i] = j;
		brute(op,i+1);
	}
}

int main() { _
	cin >> n;

	for(int i=0;i<n;i++) cin >> v[i];
	int op[n];
	brute(op,0);

	cout << ans << '\n';

    return 0;
}
