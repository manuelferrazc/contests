#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> l(m);
    for(auto &i:l) cin >> i;
    set<int> sabe;
    for(int i=0;i<k;i++) {
        int a;
        cin >> a;
        sabe.insert(a);
    }
    if(sabe.size()<n-1) {
        cout << string(m,'0') << '\n';
        return;
    } else if(sabe.size()==n) {
        cout << string(m,'1') << '\n';
        return;
    }
    for(int i=0;i<m;i++) {
        if(sabe.count(l[i])) cout << 0;
        else cout << 1;
    }
    cout << '\n';
}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
