#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,q;
    cin >> n >> q;

    ll im=0,pa=0;
    ll qi=0,qp=0;
    while(n--) {
        ll i;
        cin >> i;
        if(i&1) im+=i,qi++;
        else pa+=i,qp++;
    }

    int op,val;
    
    while(q--) {
        cin >> op >> val;
        if(op&1) {
            im+=qi*val;
            if(val&1) {
                qp += qi;
                qi=0;
                pa += im;
                im = 0;
            }
        } else {
            pa+=qp*val;
            if(val&1) {
                qi+=qp;
                qp=0;
                im+=pa;
                pa = 0;
            }
        }

        cout << im+pa << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
