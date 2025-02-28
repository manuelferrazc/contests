#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
typedef long long ll;
typedef unsigned long long ull;


void solve() {
	int c, n;
	scanf("%d %d",&c,&n);
	map<string,double> m;

	char str[11];
	double ans=0,x;
	for(int i=0;i<c;i++) {
		scanf("%s %lf", str,&x);
		m.insert({str,x});
	}
	m.insert({"JD",1});
	
	for(int i=0;i<n;i++) {
		scanf("%lf %s", &x, str);
		ans+=m.at(str)*x;
	}
	
	printf("%.6f\n", ans);
}

int main() { _
    int t; scanf("%d", &t);
	cout << fixed << setprecision(6);
    while(t--) solve();

    return 0;
}