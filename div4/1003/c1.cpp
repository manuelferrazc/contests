#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &i:v) cin >>i;
    cin >> m;

    v[0] = min(v[0],m-v[0]);
    for(int i=1;i<n;i++) {
        int aux = v[i];
        v[i] = min(v[i],m-v[i]);
        if(v[i]>=v[i-1]) continue;
        v[i] = aux;
        v[i] = max(v[i],m-v[i]);
        if(v[i]<v[i-1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YEs\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
