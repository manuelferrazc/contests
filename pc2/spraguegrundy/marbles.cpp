#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int mex(vector<bool> &v) {
    for(int i=0;i<(int)v.size();i++) if(not v[i]) return i;
}

int main() { 
    int dp[101][101];

    for(int i=0;i<=100;i++) {
        for(int j=0;j<=100;j++) {
            int mx = max(i,j);
            int mi = min(i,j);
            vector<bool> v(302,false);

            for(int u=1;u<=mx;u++) {
                if(mi-u>=0) {
                    v[dp[i][j-u]] = true;
                    v[dp[i-u][j-u]] = true;
                    v[dp[i-u][j]] = true;
                } else if(i-u>=0) v[dp[i-u][j]] = true;
                else v[dp[i][j-u]] = true;
            }

            dp[i][j] = mex(v);
        }
    }

    int x=0,n;
    cin >> n;

    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        if(a==b) {
            cout << 'Y' << '\n';
            return 0;
        }
        x^=dp[a][b];
    }

    if(x) cout << 'Y';
    else cout << 'N';

    cout << '\n';

    
    return 0;
}
