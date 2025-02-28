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

int dp(vvi &dp, string &a, string &b, const int i, const int j) {
    if(dp[i][j]!=INT_MAX) return dp[i][j];

    if(i==0 and j==0) return dp[i][j] = 0;
    else if(i==0) return dp[i][j] = j;
    else if(j==0) return dp[i][j] = i;

    if(a[i-1]==b[j-1]) return
        dp[i][j] = min(::dp(dp,a,b,i-1,j-1),min(::dp(dp,a,b,i,j-1),::dp(dp,a,b,i-1,j))+1);
    else return
        dp[i][j] = min(::dp(dp,a,b,i-1,j-1),min(::dp(dp,a,b,i,j-1),::dp(dp,a,b,i-1,j)))+1;
}


int main() { _
    int t;
    cin >> t;

    while(t--) {
        string a,b;
        cin >> a >> b;
        vvi dp(a.size()+1,vi(b.size()+1,INT_MAX));

        cout << ::dp(dp,a,b,(int)a.size(),(int)b.size()) << '\n';
    }
    return 0;
}