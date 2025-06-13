#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<vector<vector<long double>>> dp(1001,vector<vector<long double>>(1001,vector<long double>(2,-1)));

long double ddp(int w, int b, int p) {
    if(dp[w][b][p]>-0.5) return dp[w][b][p];
    if(w==0 and b==0) return dp[w][b][p] = !p;
    if(b==0) return dp[w][b][p] = 1;
    if(w==0) return dp[w][b][p] = 0;

    if(p) return dp[w][b][p] = w/(long double)(w+b)+(b/(long double)(w+b))*(1-ddp(w,b-1,0));
    else {
        long double q = w+b-1;
        dp[w][b][p] = w/(long double)(w+b);

        if(b>1) {
            dp[w][b][p] += (b/(long double)(w+b))*((b-1)/q)*(1-ddp(w,b-2,1));
            dp[w][b][p] += (b/(long double)(w+b))*(w/q)*(1-ddp(w-1,b-1,1));
        } else if(w==1) return dp[w][b][p] = 1;

        return dp[w][b][p];
    }
}

int main() { _
    int w,b;
    cin >> w >> b;

    cout << fixed << setprecision(13);
    cout << ddp(w,b,1) << '\n';

    return 0;
}
