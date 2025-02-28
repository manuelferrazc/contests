#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    string s;
    ll nb,ns,nc,pb,ps,pc,ru;
    cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> ru;

    ll l = 0, r = 1e12+200, ans=0;
    ll xb=0,xs=0,xc=0;
    for(auto i:s) {
        if(i=='B') xb++;
        else if(i=='S') xs++;
        else xc++;
    }

    while(l<=r) {
        ll m = (l+r)>>1;
        ll c=max(m*xb-nb,0LL)*pb + max(m*xs-ns,0LL)*ps + max(m*xc-nc,0LL)*pc;
        if(c<=ru) {
            ans=max(ans,m);
            l=m+1;
        } else r=m-1;
    }

    cout << ans << '\n';

    return 0;
}
