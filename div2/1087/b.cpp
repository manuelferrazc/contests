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

    ll v[n];
    for(int i=0;i<n;i++) cin >> i[v];
    
    for(int i=0;i<n;i++) {
        int ig=0,ma=0,mi=0;

        for(int j=i+1;j<n;j++) {
            if(v[j]>v[i]) ma++;
            if(v[j]<v[i]) mi++;
            // if(abs(v[i])==abs(v[j])) ig++;
        }

        cout << max({ig,ma,mi}) << ' ';
    }

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
