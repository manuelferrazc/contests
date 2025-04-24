#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    for(string &s:v) cin >> s;

    int ans=0;
    pair<int,int> dd[] = {{0,1},{0,-1},{1,0},{-1,0}};

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]=='P') {
                for(pair<int,int> d:dd) {
                    int x=i+d.ff, y=j+d.ss;
                    if(x<0 or x>=n or y<0 or y>=m) continue;
                    if(v[x][y]=='W') {
                        ans++;
                        v[x][y]='.';
                        break;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
