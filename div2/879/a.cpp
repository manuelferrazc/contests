#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m=0,u=0,a;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a;
        if(a==1) u++;
        else m++;
    }
    int ans=0;
    while(true) {
        if(m&1) {
            u++;
            m--;
            ans++;
        } else if(m>u) {
            m--;
            u++;
            ans++;
        } else break;
    }
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
