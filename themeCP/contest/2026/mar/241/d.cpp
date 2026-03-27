#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
    cout << "No\n";
}

void yes() {
    cout << "Yes\n";
}

void solve() {
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<bool> vis(n+1,false);

    for(int i=n-1;vis[i]==false and k>0;k--) {
        if(v[i]>n) return no();

        vis[i] = true;
        i-=v[i];
        i+=n;
        i%=n;
    }

    yes();
}

// 3 2 3 4 3
// 3 3 2 3 4
//   ^


// 4 3 3 2 3
// 2 3 4 3 3

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
