#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<vector<vector<double>>> dp(1001,vector<vector<double>>(1001,vector<double>(2,-1)));

// p = 1 -> princesa jogando
double ddp(int w, int b, int p) {
    if(dp[w][b][p]>-0.5) return dp[w][b][p];
    if(w==0 and b==0) return dp[w][b][p] = !p;
    if(b==0) return dp[w][b][p] 
}

int main() { _
    int w,b;
    cin >> w >> b;

    cout << fixed << setprecision(10);
    cout << ddp(w,b,1) << '\n';

    return 0;
}
