#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n),b(m);
    for(ll &i:a) cin >> i;
    for(ll &i:b) cin >> i;
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());

    vector<ll> p(m),s(m);

    for(ll i=0;i<n;i++) p[i] = abs(a[i]-b[i]);
    for(ll i=0;i<n;i++) s[m-i-1] = abs(a[n-i-1]-b[m-i-1]);

    vector<ll> sp(m),ss(m);
    sp[0] = p[0];
    for(ll i=1;i<m;i++) sp[i] = sp[i-1]+p[i];
    ss.back()=s.back();
    for(ll i=m-1;i;i--) ss[i-1] = ss[i]+s[i-1];

    ll ans = ss[m-n];
    for(ll i=1;i<=n;i++) { // qtd da esquerda 
        if(i<n) ans = max(ans,sp[i-1]+ss[m-n+i]);
        else ans = max(ans,sp[n-1]);
    }

    cout << ans << '\n';
}
// 1 2 4 6
// 7 5 1 2
int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
