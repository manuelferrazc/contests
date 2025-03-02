#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    unsigned n,q;
    cin >> n >> q;
    vector<unsigned> v(n);
    for(auto &i:v) cin >> i;

    vector<unsigned> qq(q);
    for(unsigned i=0;i<q;i++) cin >> qq[i];

    vector<unsigned> ans;
    for(unsigned i=0;i<31;i++) ans.push_back(1<<i);
    
    for(auto &i:ans) 
        for(auto j:qq) if((i%(1<<(j)))==0) i+=(1<<(j-1));
    

    for(auto &i:v) {
        if(i&1) {
            cout << i << ' ';
            continue;
        }

        for(unsigned j=1;;j++) {
            if(i&(1<<j)) {
                i+=ans[j]-(1<<(j));
                break;
            }
        }
        cout << i << ' ';
    }

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
