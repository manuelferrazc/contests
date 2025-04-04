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
    multiset<int> s;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        s.insert(a);
    }

    int o=0, act=*s.rbegin();
    for(auto it = s.begin();it!=s.end();it++) o|=*it;
    s.erase(prev(s.end()));
    cout << act << ' ';
    
    while(o!=act) {
        int m=-1,x=0;

        for(int i:s) {
            if((act|i)>m) {
                m=act|i;
                x=i;
            }
        }

        act = act|x;
        cout << x << ' ';
        s.erase(s.lower_bound(x));
    }
    for(int i:s) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
