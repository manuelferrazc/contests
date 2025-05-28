#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<vector<int>> dp(501,vector<int>(501,-1));

int ddp(int a, int b) {
    if(b>a) swap(a,b);
    if(dp[a][b]!=-1) return dp[a][b];

    dp[a][b] = 1+ddp(a-b,b);
    for(int i=1;i<a;i++) dp[a][b] = min(dp[a][b],1+ddp(a-i,b)+ddp(i,b));
    for(int i=1;i<b;i++) dp[a][b] = min(dp[a][b],1+ddp(a,b-i)+ddp(a,i));
    return dp[a][b];
}

int main() { _
    int a,b;
    cin >> a >> b;
    if(b>a) swap(a,b);

    for(int i=0;i<=500;i++) dp[i][i] = 0;
    cout << ddp(a,b) << '\n';
    return 0;
}
