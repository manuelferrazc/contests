#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
int v[200'000];


int bb1(int tg) {
    int l = 1,r=1'000'000'000;

    while(l<=r) {

    }
}

void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> i[v];

    sort(v,v+n);
    // int l = v[0],r=v[n-1],ans = v[0];

    // while(l<=r) {
        // int tg = (l+r)>>1;

    // }
    cout << max(v[0],v[1]-v[0]) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
