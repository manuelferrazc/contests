#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> v(n,vector<int>(m));
    int mx = 0,t=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> v[i][j];
            mx = max(mx,v[i][j]);
        }
    }

    vector<int> ml(n,0), mc(m,0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]==mx) {
                t++;
                ml[i]++;
                mc[j]++;
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]==mx) {
                if(ml[i]+mc[j]-1==t) {
                    cout << mx-1 << '\n';
                    return;
                }
            } else {
                if(ml[i]+mc[j]==t) {
                    cout << mx-1 << '\n';
                    return;
                }
            }
        }
    }

    cout << mx << '\n';

}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
