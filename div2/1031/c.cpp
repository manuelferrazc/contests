#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for(string &s:v) cin >> s;
    vector<vector<int>> sp(n,vector<int>(m));
    vector<vector<int>> sp2(n,vector<int>(m));

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(v[j][i]=='.') sp[j][i] = 1;
            else sp[j][i] = 0;
            if(j) sp[j][i] += sp[j-1][i];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]=='.') sp2[i][j] = 1;
            else sp2[i][j] = 0;
            if(j) sp2[i][j] += sp2[i][j-1];
        }
    }

    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]!='g') continue;
            int qtd=0;

            if(j-k>=0) qtd+=sp[min(i+k,n-1)][j-k]-(i-k<=0?0:sp[i-k-1][j-k]);
            if(j+k<m) qtd+=sp[min(i+k,n-1)][j+k]-(i-k<=0?0:sp[i-k-1][j+k]);
            if(i-k>=0) qtd+=sp2[i-k][min(j+k-1,m-1)]-(j-k+1<=0?0:sp2[i-k][j-k]);
            if(i+k<n) qtd+=sp2[i+k][min(j+k-1,m-1)]-(j-k+1<=0?0:sp2[i+k][j-k]);

            if(qtd) ans++;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
