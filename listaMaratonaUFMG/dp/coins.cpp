#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

long double ddp(vector<vector<long double>> &dp, vector<long double> &v, int j, int c) {
    if(j==0 and c==0) return dp[j][c] = 1;
    else if(j==0) return dp[j][c] = 0;
    
    if(dp[j][c]>-5) return dp[j][c];
    if(c>j) return 0;

    if(c>0) return dp[j][c] = ddp(dp,v,j-1,c-1)*v[j-1] + ddp(dp,v,j-1,c)*(1-v[j-1]); // chance de conseguir + chance de n conseguir
    else return dp[j][c] = ddp(dp,v,j-1,c)*(1-v[j-1]); // chance de n conseguir
}

int main() { _
    int n;
    cin >> n;

    vector<long double> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<long double>> dp(n+1,vector<long double>(n+1,-10));

    long double p=0;
    for(int i=n;i+i>n;i--) p += ddp(dp,v,n,i);

    cout << fixed << setprecision(10);
    cout << p << '\n';

    return 0;
}