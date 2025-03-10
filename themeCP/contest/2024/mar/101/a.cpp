#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k,x=1;
    cin >> n >> k;

    vector<int> v(n,-1);
    for(int i=k-1;i<n;i+=k) v[i] = x++;
    int x=n;
    for(int i=0;i<n;i++) {
        if(v[i]==-1) v[i] = x--;
    }

    for(int i:v) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
