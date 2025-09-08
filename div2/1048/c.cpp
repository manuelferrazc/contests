#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll x,k;
    cin >> k >> x;

    ll qa = 1LL<<k, qb = 1ll<<k;

    vector<int> ans;
    
    while(qa!=x) {
        cout << qa << ' ' << qb << '\n';
        if(qa>x) {
            if(qa%4==0) {
                ans.push_back(1);
                qb+=qa/2;
                qa/=2;
            }
            else {
                ans.push_back(2);
                qa+=qb/2;
                qb/=2;
            }
        } else {
            if(qb%4==0) {
                ans.push_back(2);
                qa+=qb/2;
                qb/=2;
            }
            else {
                ans.push_back(1);
                qb+=qa/2;
                qa/=2;
            }
        }
        cout << qa << ' ' << qb << '\n';
break;
    }

    cout << ans.size() << '\n';
    for(int i:ans) cout << i << ' ';
    if(ans.size()) cout << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
