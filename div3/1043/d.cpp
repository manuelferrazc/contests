#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll k;
    cin >> k;
    ll sum = 0;
    ll p=1;
    ll d=1;

    while(k) {
        if((p*10-p)*d<=k) {
            k-=(p*10-p)*d;
            sum+=45*p*d;
        } else {
            for(ll i=d;i and k;i--) {
                for(ll dd=1;dd<=9;dd++) {
                    if((d-1)*p/10*d<k) {
                        k-=(d-1)*p/10*d;
                        sum+=dd*(d-1)*p/10*d;
                        sum+=45*p/10*d;
                    } else {



                        break;
                    }
                }
            }

            break;
        }
        p*=10;
        d++;
        if(k==0) break;
    }

    cout << sum << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
