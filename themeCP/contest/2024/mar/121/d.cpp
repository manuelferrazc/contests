#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,m,d;
    cin >> n >> m >> d;
    vector<ll> v(m);
    for(auto &i:v) cin >> i;

    ll qtd = m;
    for(int i=0;i<m-1;i++) {
        qtd+=(v[i+1]-v[i]-1)/d;
    }
    qtd+=(v[0]-1)/d+((v[0]-1)%d!=0);
    qtd+=(n-v[m-1])/d;

    ll opt = LLONG_MAX,qt=0;

    for(int i=1;i<m-1;i++) {
        ll co = (v[i+1]-v[i-1]-1)/d;
        ll ti = 1+(v[i+1]-v[i]-1)/d + (v[i]-v[i-1]-1)/d;
        if(qtd-ti+co<opt) {
            opt = qtd-ti+co;
            qt=1;
        } else if(qtd-ti+co==opt) qt++;
    }

    ll fc = (n-v[m-2])/d, ft = 1+(n-v.back())/d+(v.back()-v[m-2]-1)/d;
    if(qtd-ft+fc<opt) {
        opt = qtd-ft+fc;
        qt=1;
    } else if(qtd-ft+fc==opt) qt++;

    fc = (v[1]-1)/d+((v[1]-1)%d!=0);
    ft = 1+(v[1]-v[0]-1)/d+(v[0]-1)/d+
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
