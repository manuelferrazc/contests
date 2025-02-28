#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll p,r,q;
    cin >> p >> r >> q;

    vector<vector<ll>> por(r,vector<ll>(p));
    for(ll i=0;i<p;i++) for(ll j=0;j<r;j++) cin >> por[j][i];

    for(ll i=0;i<r;i++) for(ll j=1;j<p;j++)
        por[i][j] = por[i][j]|por[i][j-1];

    ll m,a,b,re,c;
    string o;

    while(q--) {
        a=0;b=p;
        cin >> m;

        while(m--) {
            cin >> re >> o >> c;
            re--;
            if(o[0]=='<') {
                auto x = lower_bound(por[re].begin(),por[re].end(),c);
                ll m = x-por[re].begin();
                b = min(b,m); // primeiro q n pode dps dos q podem
            } else {
                auto x = upper_bound(por[re].begin(),por[re].end(),c);
                ll m = x-por[re].begin();
                a = max(a,m); // primeiro q pode
            }
        }
        a++;

        if(a>b) cout << "-1\n";
        else cout << a << '\n';
    }

    return 0;
}
