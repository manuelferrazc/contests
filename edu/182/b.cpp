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

    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    vector<int> v(n);
    for(int &i:v) {
        cin >> i;
        s.erase(i);
    }

    for(int i=n-1;i>=0;i--) {
        if(v[i]==0) {
            v[i] = *s.begin();
            s.erase(s.begin());
        }
    }
    
    int f = -1, e=0;
    for(int i=0;i<n;i++) {
        if(v[i]!=i+1) {
            f = i;
            break;
        }
    }

    for(int i=n-1;i>=0;i--) {
        if(v[i]!=i+1) {
            e = i;
            break;
        }
    }

    if(f==-1) cout << 0 << '\n';
    else cout << e-f+1 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
