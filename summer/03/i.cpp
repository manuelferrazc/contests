#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
string v[20];

int dp[40][1<<20];

int ddp(int diag, int mask) {
    if(dp[diag][mask]!=3000) return dp[diag][mask];
    if(diag==2*n-2) {
        if(v[n-1][n-1]=='a') return dp[diag][mask] = 1;
        else if(v[n-1][n-1]=='b') return dp[diag][mask] = -1;
        return dp[diag][mask] = 0;
    }
    
    map<char,int> m;
    int c = 0;
    for(int y=0;y<=diag;y++) {
        int x = diag-y;

        if(x<0 or x>=n or y>=n) continue;
        
        if((mask&(1<<x))==0) continue;
        if(v[x][y]=='a') c = 1;
        else if(v[x][y]=='b') c = -1;
        
        for(int i=0;i<2;i++) {
            int x2 = x+i;
            int y2 = y+(1-i);
            
            if(x2<n and y2<n) {
                m[v[x2][y2]]|=(1<<x2);
            }
        }
    }
    
    int mx = INT_MIN,mi = INT_MAX;

    for(auto [l,mask2]:m) {
        int r = ddp(diag+1,mask2);

        mx = max(mx,r);
        mi = min(mi,r);
    }

    if(diag&1) return dp[diag][mask] = c+mx;
    else return dp[diag][mask] = c+mi;
}

int main() { _
    cin >> n;
    for(int i=0;i<n;i++) cin >> v[i];
    
    for(int i=0;i<40;i++) for(int j=0;j<(1<<20);j++) dp[i][j] = 3000;

    int x = ddp(0,1);

    if(x>0) cout << "FIRST\n";
    else if(x<0) cout << "SECOND\n";
    else cout << "DRAW\n";

    return 0;
}
