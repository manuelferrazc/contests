#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m,k, g=0;
    cin >> n >> m >> k;
    vector<string> v(n);
    for(string &s:v) cin >> s;

    vector<vector<int>> sp(n,vector<int>(m));
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]=='g') {
                sp[i][j] = 1;
                g++;
            }

            if(i==0 and j) sp[i][j]+=sp[i][j-1];
            else if(i and j==0) sp[i][j]+=sp[i-1][j];
            else if(i and j) sp[i][j] += sp[i-1][j]+sp[i][j-1]-sp[i-1][j-1];
        }
    }

    int ans = g;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]!='.') continue;

            int q = sp[min(n-1,i+k-1)][min(m-1,j+k-1)];
            if(i-k>=0 and j-k>=0) {
                q -= sp[i-k][min(m-1,j+k-1)]+sp[min(n-1,i+k-1)][j-k]-sp[i-k][j-k];
                // cout << "q: " << q << ' ' ;
            }else if(i-k>=0) q-=sp[i-k][min(m-1,j+k-1)];
            else if(j-k>=0) q-=sp[min(n-1,i+k-1)][j-k];
            
            ans = min(ans,q);
        }
    }

    cout << g-ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
