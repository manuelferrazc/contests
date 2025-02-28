#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,p;
    cin >> n;
    vector<ll> v(n+1,0);
    vector<pair<ll,ll>> sp(n+1,{0,-1});
    for(ll i=0;i<n;i++) {
        cin >> p;
        v[p]++;
    }

    p=0;
    vector<ll> primes;
    vector<pair<ll,ll>> semiprimes;

    vector<bool> c(n+1,true);
    for(ll i=2;i<=n;i++) {
        if(not c[i]) continue;
        p+=v[i];
        primes.push_back(i);

        for(ll j=i+i;j<=n;j+=i) {
            c[j] = false;
            if(sp[j].ff==0) {
                sp[j].ff=1;
                sp[j].ss = i;
            } else if(sp[j].ff == 1) {
                sp[j].ff=2;
                if((j/i)==sp[j].ss) semiprimes.push_back({j,i});
            }
        }
    }

    ll ans = 0;
    for(auto i:primes) {
        ll qtd = v[i];
        p-=v[i];
        ans+=qtd*p;
        ll sq = i*i;
        if(sq<=n and v[sq]) {
            ans+=v[sq]*v[i];
            qtd=v[sq];
            ans+=qtd*(qtd-1)/2;
            ans+=qtd;
        }
    }
    
    for(auto &i:semiprimes) {
        ll qtd = v[i.ff];
        ans+=qtd*(qtd-1)/2;
        ans+=qtd;
        ans+=qtd*(v[i.ss]+v[i.ff/i.ss]);
    }
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
