#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool ith(ll d, int i) {
    return (d&(1ll<<i))>0;
}

ll solve() {
    ll b,c,d;
    cin >> b >> c >> d;

    ll a = 0;

    for(int i=0;i<=61;i++) {
        bool bi = ith(b,i);
        bool ci = ith(c,i);
        bool di = ith(d,i);

        if(di) {
            if(ci and bi==false) return -1;
            else if(bi==false and ci==false) a|=(1ll<<i);
        } else {
            if(ci) a|=(1ll<<i);
            else if(bi) return -1;
        }
    }

    return a;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
