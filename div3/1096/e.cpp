#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    int v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    int sm[n+1];
    sm[n] = 1000000;
    for(int i=n-1;i>=0;i--) sm[i] = min(sm[i+1],v[i]);

    ll ans = 0;
    for(int i=0;i<n;i++) ans += max(0,v[i]-sm[i+1]);

    ll best = 0;

    for(int i=n-1;i>=0;) {
        if(v[i]<sm[i+1]) {
            int j = i;
            while(j>=0 and v[j]>=v[i]) j--;
            // j-> mais proximo pra tras que é menor
            best = max(best,i-j-1ll);
            i = j;
        }
    }


    cout << ans+best << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
