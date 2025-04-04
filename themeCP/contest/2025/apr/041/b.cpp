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

    vector<int> v;
    for(int i=1;i<n;i++) v.push_back(i);
    
    int m=0;
    for(int i=0;i<n-2;i++) {
        if((v[i]^v[i+1])>(v[m]^v[m+1])) m=i;
    }

    for(int i=0;i<=m;i++) cout << v[i] << ' ';
    cout << "0 ";
    for(int i=m+1;i<n-1;i++) cout << v[i] << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
