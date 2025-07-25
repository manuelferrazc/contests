#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int r,s,p;
    cin >> r >> s >> p;

    vector<vector<vector<double>>> v(r+1,vector<vector<double>>(s+1,vector<double>(p+1,0)));
    v[r][s][p] = 1;

    for(int i=r;i>=0;i--) { // rock
        for(int j=s;j>=0;j--) { // scijor
            for(int k=p;k>=0;k--) { // paper
                double t = i*j+i*k+j*k;
                if(i and j) v[i][j-1][k]+=v[i][j][k]*(i*j/t);
                if(i and k) v[i-1][j][k]+=v[i][j][k]*(i*k/t);
                if(j and k) v[i][j][k-1]+=v[i][j][k]*(j*k/t);
            }
        }
    }

    double ans=0;
    for(int i=r;i;i--) ans+=v[i][0][0];
    cout << fixed << setprecision(15) << ans << ' ';

    ans=0;
    for(int i=s;i;i--) ans+=v[0][i][0];
    cout << ans << ' ';
    
    ans=0;
    for(int i=p;i;i--) ans+=v[0][0][i];
    cout << ans << '\n';

    return 0;
}
