#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> p,a;

ll calc(int px, int k) {
    vector<bool> vis(p.size(),false);
    ll ret = 0,acc = 0;

    for(int i=px;vis[i]==false and k;i=p[i]) {
        acc+=a[i];
        k--;
        ret=max(ret,acc+a[i]*k);
        vis[i] = true;
    }
    return ret;
}

void solve() {
    int k;
    int n,pb,ps;
    cin >> n >> k >> pb >> ps;
    pb--;
    ps--;
    p.resize(n);
    a.resize(n);
    for(auto &i:p) {
        cin >> i;
        i--;
    }

    for(auto &i:a) cin >> i;
    ll b=calc(pb,k),s=calc(ps,k);
    if(b==s) cout << "Draw\n";
    else if(b>s) cout << "Bodya\n";
    else cout << "Sasha\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
