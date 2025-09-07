#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
    cin >> n;

    for(int i = 0;i<n;i++) {
        int x;
        cin >> x;
        cout << n+1-x << ' ';
    }
    // vector<int> q[3];
    // for(int i=1;i<=n;i++) q[i%3].push_back(i);

    // for(int i:v) {
    //     if(q[(3-i%3)%3].size()) {
    //         cout << q[(3-i%3)%3].back() << ' ';
    //         q[(3-i%3)%3].pop_back();
    //     }
    //     else {
    //         for(int i=0;i<3;i++) {
    //             if(q[i].size()) {
    //                 cout << q[i].back() << ' ';
    //                 q[i].pop_back();
    //                 break;
    //             }
    //         }
    //     }
    // }

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
