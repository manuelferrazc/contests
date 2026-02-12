#include <bits/stdc++.h>

// Otimizacoes agressivas, pode deixar mais rapido ou mais devagar
#pragma GCC optimize("Ofast")
// Auto explicativo
#pragma GCC optimize("unroll-loops")
// Vetorizacao
#pragma GCC target("avx2")
// Para operacoes com bits
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    int sq = sqrt(n);

    ll v[n];
    for(int i=0;i<n;i++) cin >> i[v];
    
    ll ans = 0;
    for(int i=0;i<n;i++) {
        if(v[i]>=sq) {
            for(ll j=v[i];j+i<n;j+=v[i]) if(v[i+j]==j/v[i]) ans++;
        }
    }

    for(int f=1;f<sq;f++) {
        for(int i=1;i<n;i++) {
            if(v[i]*f<=i and v[i-v[i]*f]==f) ans++;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
