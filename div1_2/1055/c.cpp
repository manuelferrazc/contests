#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int get(int *sp, int a, int b) {
    if(a==0) return sp[b];
    return sp[b]-sp[a-1];
}

void solve() {
    int n,q;
    cin >> n >> q;

    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    int sp0[n],sp1[n];
    sp0[0] = (v[0]==0);
    sp1[0] = v[0];
    
    for(int i=1;i<n;i++) {
        sp0[i] = sp0[i-1]+(v[i]==0);
        sp1[i] = sp1[i-1]+v[i];
    }

    int sp[n];
    sp[n-1] = 0;
    if(n>1) sp[0] = v[0]==v[1];

    for(int i=1;i<n-1;i++) {
        sp[i] = sp[i-1];
        if(v[i]==v[i+1]) sp[i]++;
    }

    while(q--) {
        int l,r;
        cin >> l >> r;
        l--;
        r--;

        if(get(sp0,l,r)%3 or get(sp1,l,r)%3) cout << -1 << '\n';
        else if(get(sp,l,r-1)) cout << (r-l+1)/3 << '\n';
        else cout << (r-l+4)/3 << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
