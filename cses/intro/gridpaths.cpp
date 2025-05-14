#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

string s;

vector<vector<vector<ll>>> dp(7,vector<vector<ll>>(7,vector<ll>(48,-1)));
vector<vector<bool>> vis(7,vector<bool>(7,false));

ll brute(ll x, ll y, ll i=0) {
    if(x<0 or y<0 or x>6 or y>6) return 0;
    if(vis[x][y]) return 0;
    if(i==48) return x==6 and y==0;
    // if(dp[x][y][i]!=-1) return dp[x][y][i];
    vis[x][y] = true;
    ll r;
    if(s[i]=='U') r =  /*dp[x][y][i] =*/ brute(x-1,y,i+1);
    if(s[i]=='D') r =  /*dp[x][y][i] =*/ brute(x+1,y,i+1);
    if(s[i]=='L') r =  /*dp[x][y][i] =*/ brute(x,y-1,i+1);
    if(s[i]=='R') r =  /*dp[x][y][i] =*/ brute(x,y+1,i+1);
    else r = 
     /*dp[x][y][i] =*/ brute(x,y-1,i+1)+brute(x,y+1,i+1)+brute(x+1,y,i+1)+brute(x-1,y,i+1);
    vis[x][y] = false;
    return r;
}

int main() { _
    cin >> s;

    cout << brute(0,0) << '\n';
    
    return 0;
}
