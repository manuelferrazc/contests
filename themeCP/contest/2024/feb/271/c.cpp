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
    if((n&1)==0) {
        for(int i=1;i<=n;i+=2) cout << i << ' ' << i << ' ';
        cout << '\n';
    } else if(n>26) {
        vector<int> v(n,0);
        v[0] = v[9] = v[25] = 1'000'000;
        v[10] = v[26] = 999'999;
        
        int c=1;
        for(int i=0;i<n;) {
            if(v[i]) {
                i++;
                continue;
            }
            v[i] = v[i+1] = c;
            c++;
            i+=2;
        }
        for(auto i:v) cout << i << ' ';
        cout << '\n';
    } else cout << "-1\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
