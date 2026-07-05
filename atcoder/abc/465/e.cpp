#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353ll;
string n;

ll dp[501][2<<10][2][3][2];
int cnt[2<<10];

ll ddp(int i, int mask, bool eq, int m, bool nz) {
	ll &val = dp[i][mask][eq][m][nz];

	if(val!=-1) return val;
	val = 0;

	if(i==n.size()) {
		if(cnt[mask]==0 and m==0 and nz==1) return val = 1;
		return val = 0;
	} else if(nz==false) {
		if(i==0) {
			val += ddp(i+1,mask,0,m,0);
			for(int d=1;d<n[i]-'0';d++) if(mask&(1<<d)) {
				val += ddp(i+1,mask,0,(30-d+m)%3,1);
				val += ddp(i+1,mask-(1<<d),0,(30-d+m)%3,1);
			}

			int d = n[i]-'0';
			if(mask&(1<<d)) {
				val += ddp(i+1,mask,1,(30-d+m)%3,1);
				val += ddp(i+1,mask-(1<<d),1,(30-d+m)%3,1);
			}
		} else {
			val += ddp(i+1,mask,0,m,0);
			for(int d=1;d<10;d++) if(mask&(1<<d)) {
				val += ddp(i+1,mask,0,(m+30-d)%3,1);
				val += ddp(i+1,mask-(1<<d),0,(m+30-d)%3,1);
			}
		}
	} else if(eq) {
		for(int d=0;d<n[i]-'0';d++) if(mask&(1<<d)){
			val += ddp(i+1,mask,0,(m-d+30)%3,1);
			val += ddp(i+1,mask-(1<<d),0,(m-d+30)%3,1);
		}

		int d = n[i]-'0';
		if(mask&(1<<d)) {
			val += ddp(i+1,mask,1,(m-d+30)%3,1);
			val += ddp(i+1,mask-(1<<d),1,(m-d+30)%3,1);
		}
	} else {
		for(int d=0;d<10;d++) if(mask&(1<<d)) {
			val += ddp(i+1,mask,0,(m-d+30)%3,1);
			val += ddp(i+1,mask-(1<<d),0,(m-d+30)%3,1);
		}
	}

	val%=mod;
	return val;
}

int main() { _
	for(int i=0;i<=500;i++) for(int j=0;j<(2<<10);j++)
		for(int k=0;k<2;k++) for(int l=0;l<3;l++) 
			for(int m=0;m<2;m++) dp[i][j][k][l][m] = -1;
	cnt[0] = 0;
	cnt[1] = 1;
	for(int i=2;i<(2<<10);i++) 
		cnt[i] = cnt[i/2] + (i&1);

	
	cin >> n;

	ll ans = 0;
	for(int mask = 1;mask<(2<<10);mask++) {
		// c1
		if(cnt[mask]!=3 and (1&(mask>>3))!=1) ans += ddp(0,mask,1,0,0);
		// c2
		else if(cnt[mask]!=3 and (1&(mask>>3))) ans+=ddp(0,mask,1,1,0)+ddp(0,mask,1,2,0);
		// c3
		else if(cnt[mask]==3 and (1&(mask>>3))!=1) ans += ddp(0,mask,1,1,0)+ddp(0,mask,1,2,0);
	}

	cout << ans%mod << '\n';

    return 0;
}
