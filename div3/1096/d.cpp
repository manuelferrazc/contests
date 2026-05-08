#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    int v[2*n];
    for(int i=0;i<2*n;i++) cin >> v[i];

    int ans = 0;
    vector<int> z;

    for(int i=0;i<2*n;i++) {
        if(v[i]==0) {
            z.push_back(i);
            vector<bool> m(n+1,false);
            m[0] = true;
            for(int l=i-1,r=i+1;l>=0 and r<2*n;l--,r++) {
                if(v[l]!=v[r]) break;
                m[v[l]] = true;
            }

            for(int j=0;;j++) {
                if(m[j]==false) {
                    ans = max(ans,j);
                    break;
                }
            }
        }
    }

    vector<bool> m(n+1,false);
    m[0] = true;
    bool ok = true;
    for(int l=z[0]+1,r=z[1]-1;l<=r;l++,r--) {
        if(v[l]!=v[r]) {
            ok = false;
            break;
        }
        m[v[l]] = true;
    }

    for(int l = z[0]-1,r=z[1]+1;l>=0 and r<2*n;l--,r++) {
        if(v[l]!=v[r]) break;
        m[v[l]] = true;
    }

    if(ok) {
        for(int j=0;;j++) {
            if(m[j]==false) {
                ans = max(ans,j);
                break;
            }
        }
    }

    // for(int i=0;i<=n;i++) cout << m[i] << ' ';
    // cout << '\n';

    cout << ans << '\n';
    // exit(0);
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
