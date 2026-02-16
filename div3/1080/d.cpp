#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void print(ll *v, int n) {
    for(int i=0;i<n;i++) cout << v[i] << ' ';
    cout << '\n';
}

void solve() {
    int n;
    cin >> n;

    ll v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    if(n==2) {
        cout << v[1] << ' ' << v[0] << '\n';
        return;
    }

    ll ans[n];
    for(int i=0;i<n-2;i++) {
        ll x = v[i]-v[i+1];
        ll y = v[i+1]-v[i+2];

        ll dif = x-y; // = 2a(i+1)
        ans[i+1] = dif/2;
    }

    ll sum = 0;
    for(int i=1;i<n-1;i++) sum+=i*ans[i];

    ans[n-1] = (v[0]-sum)/(n-1);

    sum = 0;

    for(int i=1;i<n-1;i++) sum += (n-i-1)*ans[i];

    ans[0] = (v[n-1]-sum)/(n-1);

    print(ans,n);
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
