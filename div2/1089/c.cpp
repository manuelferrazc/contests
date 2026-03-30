#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll lcm1(ll a, ll b) {
    if(a==0) return b;
    if(b==0) return a;

    return lcm(a,b);
}

void solve() {
    int n;
    cin >> n;

    int a[n],b[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int ans = 0;
    bool s[n];
    fill(s,s+n,false);

    for(int i=0;i<n;i++) {
        ll m1 = i ? gcd(a[i],a[i-1]) : 0;
        ll m2 = i<n-1 ? gcd(a[i],a[i+1]) : 0;

        ll m = lcm1(m1,m2);

        for(int k=1;k<=10000;k++) {
            if(m*k>b[i]) break;
            if(m*k==a[i]) continue;

            if((i==0 or gcd(a[i-1],m*k)==m1) and (i==n-1 or gcd(a[i+1],m*k)==m2)) {
                // cout << "ok " << i << ' ' << m*k << '\n';
                a[i] = m*k;
                s[i] = true;
                ans++;
                break;
            }
        }
    }

    for(int i=0;i<n;i++) {
        if(s[i]) continue;
        ll m1 = i ? gcd(a[i],a[i-1]) : 0;
        ll m2 = i<n-1 ? gcd(a[i],a[i+1]) : 0;

        ll m = lcm1(m1,m2);

        for(int k=1;k<=10000;k++) {
            if(m*k>b[i]) break;
            if(m*k==a[i]) continue;

            if((i==0 or gcd(a[i-1],m*k)==m1) and (i==n-1 or gcd(a[i+1],m*k)==m2)) {
                // cout << "ok " << i << ' ' << m*k << '\n';
                a[i] = m*k;
                ans++;
                break;
            }
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
