#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,t;
    double p;
    cin >> n >> p >> t;

    double np = 1-p;

    vector<vector<double>> v(n+1,vector<double>(t+1,0));

    for(int i=1;i<=n;i++) { // i is the person
        for(int j=1;j<=t;j++) { // j is the time
            v[i][j] = v[i-1][j-1]*p+p+v[i][j-1]*np;
        }
    }

    cout << fixed << setprecision(10) << v.back().back() << '\n';
    
    return 0;
}
