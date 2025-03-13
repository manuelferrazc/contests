#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    unsigned n,x,y;
    cin >> n >> x >> y;

    map<unsigned,multiset<unsigned>> mx;

    for(unsigned i=0,j;i<n;i++) {
        cin >> j;
        if(not mx.count(j%x)) mx.insert(make_pair(j%x,multiset<unsigned>()));
        mx.at(j%x).insert(j);
    }

    ll ans=0;

    for(auto &i:mx) {
        if(x-i.ff<i.ff) break;
        if(i.ff and not mx.count(x-i.ff)) continue;
        map<unsigned,unsigned> qi,qj;

        for(auto ababa:i.ss) qi[ababa%y]++;
        for(auto ababa:mx.at(i.ff?x-i.ff:0)) qj[ababa%y]++;

        if(i.ff and 2*i.ff!=x) {
            for(auto p:qi) if(qj.count(p.ff)) ans+=p.ss*qj.at(p.ff);
        } else {
            for(auto p:qi) ans+=p.ss*(p.ss-1LL)/2;
        }
    }

    cout << ans << '\n';
}

int main() { _
    unsigned t;
    cin >> t;
    while(t--) solve();
    return 0;
}
