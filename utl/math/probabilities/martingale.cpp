#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

double dp[1'000'001][21]; // prob
double dp2[1'000'001][21]; // e(x)
int qtd[1'000'001][21]; // qtd de jeitos de chegar aq
bool vis[1'000'001][21];
double ans=0;

void dfs(int nlim, int n, int x) {
    if(vis[n][x]) return;
    vis[n][x] = 1;
    
    if(n+(1<<x)<nlim) {
        dp[n+(1<<x)][0]+=dp[n][x]/2;
        qtd[n+(1<<x)][0]+=qtd[n][x];
        dp2[n+(1<<x)][0]+=qtd[n][x]*dp[n][x]/2;
    } else ans+=qtd[n][x]*dp[n][x]/2;
    
    if(n-(1<<x)>0) {
        dp[n-(1<<x)][x+1]+=dp[n][x]/2;
        qtd[n-(1<<x)][x+1]+=qtd[n][x];
        dp2[n-(1<<x)][x+1]+=qtd[n][x]*dp[n][x]/2;
    } else ans+=qtd[n][x]*dp[n][x]/2;
    

    if(n-(1<<x)>0) dfs(nlim,n-(1<<x),x+1);
    if(n+(1<<x)<nlim) dfs(nlim,n+(1<<x),0);
}

int main() { _
    int n;
    cin >> n;

    for(int i=0;i<1'000'001;i++) for(int j=0;j<21;j++) {
        dp[i][j] = dp2[i][j] = 0;
        vis[i][j] = qtd[i][j] = 0;
    }

    dp[n][0] = 1;
    qtd[n][0] = 1;
    
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}
