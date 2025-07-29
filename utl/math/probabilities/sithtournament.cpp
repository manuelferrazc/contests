#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int n;
double prob[18][18];

double dp[18][1<<18];

double ddp(int p, int mask) {
    if((mask&(1<<p))==0) return 0;
    if(dp[p][mask]>-0.5) return dp[p][mask];

    double a=0,b=0;
    int x=0;

    for(int i=0;i<n;i++) {
        if(i==p or (mask&(1<<i))==0) {if(i==p)x++;continue;} // continue;
        a = max(a,ddp(p,mask^(1<<i))*prob[p][i]);// esse já ganhou um e vai lutar dnv 
        // a += ddp(p,mask^(1<<i))*prob[p][i];// esse já ganhou um e vai lutar dnv 
        // b += ddp(i,mask^(1<<p))*prob[p][i];// quem ganhou foi o outro, mas o outro perde agr 
        b += ddp(i,mask^(1<<p))*prob[p][i];// quem ganhou foi o outro, mas o outro perde agr 
    }

    if(x!=1) {
        cerr << "ERRO!!!!!!!!!!!!!!\n";
        exit(13);
    }

    return dp[p][mask] = max(a,b);
}

int main() { _
    cin >> n;
    if(n==1) {
        cout << "1\n";
        return 0;
    }

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> prob[i][j];

    // for(int i=0;i<n;i++) for(int j=0;j<(1<<n);j++) dp[i][j] = -1;
    // for(int i=0;i<n;i++) dp[i][(1<<i)] = 1;

    double ans = 0;
    int v[n];
    iota(v,v+n,0);
    // shuffle (prob[0].begin(), prob[0].end(), rng);

    double dp[n];
    if(n<=10) { 
        do {
            dp[v[0]] = prob[v[0]][v[1]];
            dp[v[1]] = prob[v[1]][v[0]];

            for(int i=2;i<n;i++) {
                dp[v[i]] = 0;
                for(int j=0;j<i;j++) dp[v[i]]+=dp[v[j]]*prob[v[i]][v[j]];
                for(int j=0;j<i;j++) dp[v[j]]*=prob[v[j]][v[i]];
            }
            ans = max(ans,dp[0]);
        } while(next_permutation(v,v+n));
    } else {
        for(int cu=0;cu<7'000'000;cu++) {
            shuffle (v, v+n, rng);
            dp[v[0]] = prob[v[0]][v[1]];
            dp[v[1]] = prob[v[1]][v[0]];

            for(int i=2;i<n;i++) {
                dp[v[i]] = 0;
                for(int j=0;j<i;j++) dp[v[i]]+=dp[v[j]]*prob[v[i]][v[j]];
                for(int j=0;j<i;j++) dp[v[j]]*=prob[v[j]][v[i]];
            }

            ans = max(ans,dp[0]);
        }
    }

    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}
