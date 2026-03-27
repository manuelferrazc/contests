#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/1856/B

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


void solve() {
    int n;
    cin >> n;

    ll a[n],b[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    sort(a,a+n);
    for(int i=0;i<n;i++) {
        if(a[i]==1) b[i] = 2;
        else b[i] = 1;
    }

    ll sa = accumulate(a,a+n,0ll);
    ll sb = accumulate(b,b+n,0ll);
    
    if(sb>sa) cout << "NO\n";
    else if(sb==sa) cout << "YES\n";
    else {
        ll rem = sa - sb; // quanto falta aumentar
        for(int i=0;i<n;i++) if(b[i]+rem!=a[i]) {
            cout << "YES\n";
            return;
        }

        for(int i=0;i<n;i++) {
            if(b[i]+1!=a[i]) {
                b[i]++;
                rem--;
                break;
            }
        }

        for(int i=0;i<n;i++) if(b[i]+rem!=a[i]) {
            cout << "YES\n";
            return;
        }

        cout << "NO\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
