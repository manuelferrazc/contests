#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

ld dp[301][301][301];
ld N;

ld ddp(int i, int j, int k) {
    if(dp[i][j][k]>-0.5) return dp[i][j][k];

    dp[i][j][k] = 1;

    if(i>0) dp[i][j][k] += ddp(i-1,j,k)*i/N;
    if(j) dp[i][j][k] += ddp(i+1,j-1,k)*j/N;
    if(k) dp[i][j][k] += ddp(i,j+1,k-1)*k/N;

    ld z = N-i-j-k;
    dp[i][j][k] /= (1-z/N);

    return dp[i][j][k];
}

int main() { _
    for(int i=0;i<301;i++) for(int j=0;j<301;j++) for(int k=0;k<301;k++) dp[i][j][k] = -1;
    dp[0][0][0] = 0;

    int n;
    cin >> n;
    N = n;

    int q1=0,q2=0,q3=0;

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;

        if(x==1) q1++;
        else if(x==2) q2++;
        else q3++;
    }

    cout << fixed << setprecision(13) << ddp(q1,q2,q3) << '\n';

    return 0;
}
