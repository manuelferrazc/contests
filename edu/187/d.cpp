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
    int n,m;
    cin >> n >> m;
    int cnt[n+m+1];
    for(int i=0;i<=m+n;i++) cnt[i] = 0;

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int cnt2[n+m+1];
    for(int i=0;i<=m+n;i++) cnt2[i] = 0;

    for(int i=1;i<=m+n;i++) {
        for(int j=i;j<=n+m;j+=i) cnt2[j]+=cnt[i];
    }

    int div = 0, ndiv = 0, both = 0;

    int b[m];
    for(int i=0;i<m;i++) cin >> b[i];

    for(int i=0;i<m;i++) {
        int x = b[i];

        int d = cnt2[x];

        if(d==n) div++;
        else if(d==0) ndiv++;
        else both^=1;
    }

    // alice pode pegar qualquer um de div + qualquer um de both
    // bob pode pegar qualquer um de ndiv + qualquer um de both

    for(int i=0;;i++) {
        if(i%2==0) { // alice
            if(both) both--;
            else if(div) div--;
            else {
                cout << "Bob\n";
                return;
            }
        } else { // bob
            if(both) both--;
            else if(ndiv) ndiv--;
            else {
                cout << "Alice\n";
                return;
            }
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
