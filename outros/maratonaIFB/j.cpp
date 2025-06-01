#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
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

int main() { _
    int n,m;
    cin >> n >> m;

    vi med(m);
    for(int i=0;i<m;i++) cin >> med[i];

    vi max(m);
    for(int i=0;i<m;i++) cin >> max[i];

    vi v;
    v.push_back(0);

    for(int i=0;i<m;i++) while(max[i]--) v.push_back(med[i]);


    vvi dp(v.size()+1,vi(n+1,INT_MAX));
    dp[0][0] = 0;
    
    for(int i=1;i<=(int)v.size();i++) { // pra cada competicao
        for(int c=0;c<=n;c++) { // pra cada qtd de medalha
            // se consigo ter essa qtd ganhando, ve o melhor
            if(c>=v[i] and dp[i-1][c-v[i]]!=INT_MAX) dp[i][c] = min(dp[i-1][c],1+dp[i-1][c-v[i]]);
            else dp[i][c] = dp[i-1][c];
        }
    }

    int ans = INT_MAX;
    for(int i=0;i<=(int)v.size();i++) {
        if(dp[i][n]!=INT_MAX) ans = min(ans,dp[i][n]);
    }

    cout << (ans==INT_MAX ? -1 : ans) << '\n';

    return 0;
}
