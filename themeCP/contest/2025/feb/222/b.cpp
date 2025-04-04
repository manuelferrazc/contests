#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define min first
#define y second
#define max second
typedef long long ll;
typedef unsigned long long ull;

int n,m;
int area;
pair<int,int> dd[4] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(vector<string> &v, int i, int j) {
    area++;
    v[i][j] = '0';

    for(auto d:dd) {
        int x = i+d.x, y = j + d.y;
        if(x<0 or x>=n or y<0 or y>=m or v[x][y]=='0') continue;
        dfs(v,x,y);
    }
}

void solve() {
    cin >> n >> m;
    vector<string> v(n);
    for(auto &i:v) cin >> i;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]=='1') {
                int k;
                for(k=0;i+k<n and v[i+k][j]=='1';k++) continue;
                int ss=1;
                for(int s=1;s+j<m;s++) {
                    bool ok = true;
                    for(int x=0;x<k;x++) {
                        if(v[i+x][j+s]=='0') {
                            ok=false;
                            break;
                        }
                    }
                    if(ok) ss++;
                    else break;
                }
                area=0;
                dfs(v,i,j);
                if(area!=k*ss) {
                    cout << "nO\n";
                    return;
                }
            }
        }
    }
    
    cout << "YeS\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
