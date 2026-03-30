#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int ans;
int n;

void brute(int *v, bool *m, int i, int acc) {
    if(i>n or m[i]) return;
    // cout << i << ' ' <<acc << '\n';
    // for(int i=1;i<=n;i++) cout << m[i] << ' ';
    // cout << '\n';
    
    for(int j=i;j<=n;j++) {
        if(m[j]) return;

        m[v[j]] = true;
        ans = max(ans,acc+1);
        brute(v,m,j+1,acc+1);
        m[v[j]] = false;
    }
}

void solve() {
    cin >> n;

    int v[n+1];
    for(int i=0;i<n;i++) {
        cin >> v[i+1];
    }

    ans = 0;

    bool m[n+1];
    fill(m,m+n+1,false);

    brute(v,m,1,0);

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
