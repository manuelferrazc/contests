#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;

#define MAX 200'001
#define MAX2 18

ll fexp(ll n, ll e) {
    if(e==0) return 1;
    if(e==1) return n;

    ll r = fexp(n,e>>1);
    r = r*r%mod;
    if(e&1) r = r*n%mod;

    return r;
}

struct seg {
    ll l,r,p,q;

    ll pe,pn;

    seg() {}
    seg(ll _l,ll _r,ll _p, ll _q) {
        l = _l;
        r = _r;
        p = _p;
        q = _q;
        // cout << p << ' ' << q << "aaaaaaaa\n";
        // cout.flush();
        ll g = gcd(p,q);
        if(g) {

            p/=g;
            q/=g;
            pe = p*fexp(q,mod-2);
            pn = mod-pe;
        }
    }

    bool const operator<(const seg& o) {
        if(l<o.l) return true;
        if(l==o.l and r<o.r) return true;
        return false;
    }
};

namespace sparse {
	pair<ll,ll> m[MAX2][MAX];
    int n;
	void build(int n2, vector<seg> &v) {
		n = n2;
		for (int i = 0; i < n; i++) {
            m[0][i].ff = mod-v[i].p, m[0][i].ss = v[i].q;
            // ll g = gcd(m[0][i].ff,m[0][i].ss);
            // m[0][i].ff/=g;
            // m[0][i].ss/=g;
        }

		for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++) {
            ll p = m[j-1][i].ff*m[j-1][i+(1<<(j-1))].ff;
            ll q = m[j-1][i].ss*m[j-1][i+(1<<(j-1))].ss;

            ll g = gcd(p,q);
            p/=g;
            q/=g;
            m[i][j] = make_pair(p%mod,q%mod);
        }
			// m[j][i] = min(m[j-1][i], m[j-1][i+(1<<(j-1))]);
	}
	pair<ll,ll> query(int a, int b) {
        int j = __builtin_clz(1) - __builtin_clz(b-a+1);

        ll p = m[j][a].ff*m[j][b-(1<<j)+1].ff;
        ll q = m[j][a].ss*m[j][b-(1<<j)+1].ss;
		ll g = gcd(p,q);
        p/=g;
        q/=g;

        return make_pair(p%mod,q%mod);
	}
}


vector<seg> v;
vector<pair<ll,ll>> dp(200'001,{-1,-1});
ll n,m;

pair<ll,ll> ddp(ll i) {
    cout << i << '\n';
    if(i>m) return make_pair(1,1);
    if(dp[i].ff!=-1) return dp[i];
    auto it = lower_bound(v.begin(),v.end(),seg(i,-1,0,0));

    if(it==v.end() or it->l>i) return dp[i] = make_pair(0,1);
    dp[i].ff = 0;
    dp[i].ss = 1;
    ll pos = it-v.begin();
    ll init = pos;
    ll mx = lower_bound(v.begin(),v.end(),seg(i,10000000LL,0,0)) - v.begin()-1;
    cout << pos << ' ' << mx << '\n';
    while(pos<=mx) {
        auto p = ddp(v[pos].r+1);

        pair<ll,ll> pnot(1,1);
        if(pos!=init) pnot = sparse::query(init,pos-1);
        if(pos!=mx) {
            auto psuf = sparse::query(pos+1,mx);

            pnot.ff *= psuf.ff;
            pnot.ss *= psuf.ss;
            ll g = gcd(pnot.ff,pnot.ss);
            pnot.ff/=g;
            pnot.ss/=g;
            pnot.ff%=mod;
            pnot.ss%=mod;

        }

        // prob de usar esse e nenhum dos outros
        pair<ll,ll> pok = make_pair(v[pos].p,v[pos].q);
        pok.ff *= pnot.ff;
        pok.ss *= pnot.ss;
        ll g = gcd(pok.ff,pok.ss);
        pok.ff/=g;
        pok.ss/=g;
        pok.ff%=mod;
        pok.ss%=mod;

        // combina com a dp
        pok.ff *= p.ff;
        pok.ss *= p.ss;
        g = gcd(pok.ff,pok.ss);
        pok.ff/=g;
        pok.ss/=g;
        pok.ff%=mod;
        pok.ss%=mod;

        // combina com a do pra posicao atual
        dp[i].ff = dp[i].ff*pok.ss+dp[i].ss*pok.ff;
        dp[i].ss = dp[i].ss*pok.ss;
        g = gcd(pok.ff,pok.ss);
        dp[i].ff/=g;
        dp[i].ss/=g;
        dp[i].ff%=mod;
        dp[i].ss%=mod;
        pos++;
    }
    return dp[i];
}

void solve() {
    cin >> n >> m;

    for(ll i=0;i<n;i++) {
        // cout << "FOR\n";
        // cout.flush();
        ll l,r,p,q;
        cin >> l >> r >> p >> q;
        v.push_back(seg(l,r,p,q));
    }

    sort(v.begin(),v.end());
    sparse::build(n,v);

    auto p = ddp(1);
    cout << (p.ff*fexp(p.ss,mod-2))%mod << '\n';
}

int main() {
    solve();
    return 0;
}
