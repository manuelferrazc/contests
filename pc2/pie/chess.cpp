#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;
const int maxn = 200'000;

struct Peca {
    int x,y;
    ll qtd;

    bool operator<(Peca &o) {
        if(x<o.x) return true;
        return x==o.x and y<o.y;
    }
};

ll fexp(ll n, ll e) {
    ll ret=1;
    while(e) {
        if(e&1) ret = ret*n%mod;
        n = n*n%mod;
        e>>=1;
    }
    return ret;
}

ll fat[maxn];

ll perm(ll n1,ll n2) {
    return fat[n1+n2]*fexp(fat[n1],mod-2)%mod*fexp(fat[n2],mod-2)%mod;
}

int main() { _
    fat[0] = 1;
    for(int i=1;i<maxn;i++) fat[i] = fat[i-1]*i%mod;

    ll n,h,w;
    cin >> h >> w >> n;

    vector<Peca> v(n);
    for(int i=0;i<n;i++) cin >> v[i].x >> v[i].y;

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++) {
        v[i].qtd = perm(v[i].x-1,v[i].y-1);

        for(int j=0;j<i;j++) {
            if(v[j].x<=v[i].x and v[j].y<=v[i].y) {
                v[i].qtd += mod;
                v[i].qtd -= v[j].qtd*perm(v[i].x-v[j].x,v[i].y-v[j].y)%mod;
                v[i].qtd %= mod;
            }
        }
    }


    ll ans = perm(h-1,w-1);

    for(int i=0;i<n;i++) {
        ans += mod;
        ans -= v[i].qtd*perm(h-v[i].x,w-v[i].y)%mod;
        ans %= mod;
    }

    cout << ans << '\n';

    return 0;
}
