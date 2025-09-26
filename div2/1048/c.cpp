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

    ll qa = (1LL<<(k+1))-x, qb = x;

    vector<int> ans;
    
    while(qa!=qb) {
        if(qa<qb) {
            qb-=qa;
            qa<<=1;
            ans.push_back(2);
        } else {
            qa-=qb;
            qb<<=1;
            ans.push_back(1);
        }
    }

    reverse(ans.begin(),ans.end());
    
    cout << ans.size() << '\n';
    for(int i:ans) cout << i << ' ';
    cout << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
