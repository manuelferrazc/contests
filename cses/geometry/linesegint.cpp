#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int dir(ll x1,ll y1, ll x2, ll y2) {
		ll d = x1*y2-y1*x2;
		if(d==0) return 0;
		else if(d>0) return 1;
		return -1;
}

bool inseg(ll x1,ll y1,ll x2,ll y2, ll px, ll py) {
	if(px>max(x1,x2) or px<min(x1,x2) or py>max(y1,y2) or py<min(y1,y2)) return false;
	return dir(x2-x1,y2-y1,px-x2,py-y2)==0;
}

int main() { _
	int t;
	cin >> t;
	while(t--) {
		ll x[4],y[4];
		for(int i=0;i<4;i++) cin >> x[i] >> y[i];

		if(inseg(x[0],y[0],x[1],1[y],x[2],y[2]) or inseg(x[0],y[0],x[1],1[y],x[3],y[3]) or
			inseg(x[2],y[2],x[3],3[y],x[1],y[1]) or inseg(x[2],y[2],x[3],y[3],x[0],y[0])) cout << "YES\n";
		else if((dir(x[1]-x[0],y[1]-y[0],x[2]-x[1],y[2]-y[1])!=dir(x[1]-x[0],y[1]-y[0],x[3]-x[1],y[3]-y[1]))
			and (dir(x[3]-x[2],y[3]-y[2],x[1]-x[3],y[1]-y[3])!=dir(x[3]-x[2],y[3]-y[2],x[0]-x[3],y[0]-y[3])))
			cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
