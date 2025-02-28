#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

int count = 0;
pii arr[] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(vs &v, vector<vb> &vi, int i, int j, int n, int m) {
    if(vi[i][j]) return;
    vi[i][j] = true;

    bool al = false;

    for(auto p: arr) {
        int a = i+p.f,b = j+p.s;
        if(a<0 or b<0 or a>=n or b>=m) continue;

        if(v[a][b]=='.') {al = true;continue;}
        else dfs(v,vi,a,b,n,m);
    }

    if(i==0 or j==0 or i==n-1 or j==m-1) al = true;

    if(al) ::count++;
}

int main() { _
    int n,m;
    cin >> n >> m;

    vs v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vb> vi(n,vector<bool>(m,false));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]=='#') {
                dfs(v,vi,i,j,n,m);
            }
        }
    }

    cout << ::count << '\n';

    return 0;
}
