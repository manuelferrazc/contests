#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void make(ll *v, ll *sp, int n) {
    sp[0] = v[0];
    for(int i=1;i<n;i++) sp[i] = sp[i-1]+v[i];
}


void solve() {
    int n;
    cin >> n;

    ll v[n+1],sp[n+1];
    for(int i=1;i<=n;i++) cin >> v[i];
    v[0] = 0;

    make(v,sp,n+1);
    ll sum = sp[n];

    ll minl = INT_MIN;

    for(ll i=1;i<=n;i++) {
        minl = max(minl,-i*i+i+sp[i-1]);
        sum = max(sum,minl+i*i+i+sp[n]-sp[i]);

    }

    cout << sum << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
