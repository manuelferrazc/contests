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
    int n;
    cin >> n;
    vector<string> v(n+1);
    for(int i=1;i<=n;i++) {cin >> v[i];v[i] = " "+v[i];}

    for(int i=1;i<=(n>>1);i++) {
        for(int x = i;x<=n+1-i;x++) {
            for(int y = i;y>=n+1-i;y++) {
                v[y][n+1-x] = v[x][y];
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout << v[i][j];
        cout << '\n';
    }

    return 0;
}
