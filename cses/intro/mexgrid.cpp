#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++) v[i][0] = v[0][i] = i;

    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++) {
            vector<bool> x(2*n+1,true);

            for(int c=0;c<i;c++) x[v[c][j]] = false;
            for(int c=0;c<j;c++) x[v[i][c]] = false;
            for(int c=0;;c++) {
                if(x[c]) {
                    v[i][j] = c;
                    break;
                }
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cout << v[i][j] << ' ';
        cout << '\n';
    }

    
    return 0;
}
