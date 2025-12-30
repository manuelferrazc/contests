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

    int a[n],b[n],c[n];
    for(int i=0;i<n;i++) cin >> i[a];
    for(int i=0;i<n;i++) cin >> i[b];
    for(int i=0;i<n;i++) cin >> i[c];

    ll q1=0,q2=0;

    for(int s=0;s<n;s++) {
        bool ok = true;
        for(int i=0;i<n;i++) {
            if(a[i]>=b[(i+s)%n]) {
                ok = false;
                break;
            }
        }
        if(ok) q1++;
    }

    for(int s=0;s<n;s++) {
        bool ok = true;
        for(int i=0;i<n;i++) {
            if(b[i]>=c[(i+s)%n]) {
                ok = false;
                break;
            }
        }
        if(ok) q2+=n;
    }

    cout << q1*q2 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
