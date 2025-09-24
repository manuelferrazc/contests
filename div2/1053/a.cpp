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

    vector<int> v(m);
    for(int &i:v) cin >> i;
    
    int q1=0;
    for(int i:v) if(i==1) q1++;

    if(q1>1) cout << 1 << '\n';
    else if(v[0]==1 or q1==0) cout << n-v.back()+1 << '\n';
    else cout << 1 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
