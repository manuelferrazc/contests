#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define p first
#define h second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,k;
    cin >> n >> k;

    vector<pair<ll,ll>> v(n);
    for(auto &i:v) cin >> i.h;
    for(auto &i:v) cin >> i.p;
    sort(v.begin(),v.end());
    ll dmg=0;
    for(ll i=0;i<n;i++) {
        v[i].h-=dmg;
        while(v[i].h>0) {
            if(k<=0) {
                cout << "No\n";
                return;
            }
            dmg+=k;
            v[i].h-=k;
            if(v[i].h>0) k-=v[i].p;
            else {
                for(;i<n;i++) {
                    v[i].h-=dmg;
                    if(v[i].h>0) {
                        k-=v[i].p;
                        v[i].h+=dmg;
                        i--;
                        break;
                    }
                }
                break;
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
