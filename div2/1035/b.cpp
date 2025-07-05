#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,px,py,qx,qy;
    cin >> n >> px >> py >> qx >> qy;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    ll dx = px-qx,dy = py-qy;
    dx*=dx;
    dy*=dy;
    sort(v.begin(),v.end());

    if(n==1) {
        if(dx+dy==v[0]*v[0]) cout << "YES\n";
        else cout << "nO\n";
    } else {
        if(n==2 and max(dx,dy)==0) {
            if(v[0]==v[1]) cout << "yes\n";
            else cout << "NO\n";    
        }
        else {
            ll d = accumulate(v.begin(),v.end(),0LL);
            if(d*d==dx+dy) cout << "yES\n";
            else if(d*d<dx+dy) cout << "NO\n";
            else {
                ll dm = d-v[n-1];
                // (sqrt(dx+dy)+dm)^2
                // = dx+dy +2*dm*sqrt(dx+dy) + dm*dm
                if(dx+dy+dm*dm+2*dm*sqrt(dx+dy)<v[n-1]*v[n-1]) cout << "No\n";
                else cout << "YeS\n";
            }
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
