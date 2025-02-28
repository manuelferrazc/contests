#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m;

int fun(vector<string> &v, int x,int y) {
    int r = 0;
    if(v[x-1][y-1]=='.') return 0;
    for(int i=1;x-i and y-i and x+i<=n and y+i<=m;i++) {
        if(v[x+i-1][y+i-1]=='#' and v[x+i-1][y-i-1]=='#' and v[x-i-1][y+i-1]=='#' and v[x-i-1][y-i-1]=='#') r++;
        else return r;
    }
    return r;
}

int main() { _
    cin >> n >> m;
    vector<string> v(n);
    for(auto &i:v) cin >> i;
    map<int,int> ans;
    for(int i=0;i<=min(m,n);i++) ans.insert({i,0});

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans.at(fun(v,i,j))++;

    ans.erase(0);
    for(auto i:ans) cout << i.ss << ' ';
    cout << '\n';
    return 0;
}
