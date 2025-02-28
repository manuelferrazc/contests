#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

void solve() {
    ll n, q;
    cin >> n >> q;

    vll v(n+1);
    v[0] = 0;
    for(ll i=1;i<=n;i++) cin >> v[i];
    
    vll sp(n+1), spp(n+1);
    spp[0] = 0;
    spp.back() = v.back();
    for(ll i=n-1;i;i--) spp[i] = spp[i+1]+v[i];
    sp[0] = 0;
    for(ll i=1;i<=n;i++) sp[i] = sp[i-1]+v[i];
    
    while(q--) {
        ll l,r;
        cin >> l >> r;

        ll ans = sp.back()*((r/n - (l%n!=0) - (l/n))); // fechados

        // preciso ir de r/n+1 ate  r/n+r%n, posivelmente circular (?)
        // if(r/n==l/n) {
        //     r= (r + r/n);
        // }
        if(r%n) { // aberto por cima
            ll inicio = r/n+1, final = (r/n+r%n)%n+1;
            if(inicio<final) ans += sp[final] - sp[inicio-1];
            else ans += sp.back() + sp[inicio] - sp[final-1];
        }

        if(l%n) {// aberto por baixo
            ll inicio = (l/n+l%n)%n+1, final = n-l/n;
            if(inicio<final) ans += sp[final] - sp[inicio-1];
            else ans += sp.back() + sp[inicio] - sp[final-1];
        }

        cout << ans << '\n';
    }
}

int main() { _
    int n;
    cin >> n;

    while(n--) solve();

    return 0;
}