#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll get(ll *sp, int l, int r) {
    if(l==0) return sp[r];
    return sp[r]-sp[l-1];
}

void solve() {
    int n;
    cin >> n;

    ll v[n];
    ll sp[n], spm[n];

    cin >> v[0];
    sp[0] = v[0];
    spm[0] = abs(v[0]);

    for(int i=1;i<n;i++) {
        cin >> i[v];
        sp[i] = sp[i-1]+v[i];
        spm[i] = spm[i-1]+abs(i[v]);
    }

    ll ans = -get(sp,1,n-1);

    for(int i=1;i<n;i++) {
        ll act = v[0];
        if(i>1) act+=get(spm,1,i-1);
        if(i<n-1) act+=-get(sp,i+1,n-1);

        ans = max(ans,act);
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
