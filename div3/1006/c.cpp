#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,x;
    cin >> n >> x;
    vector<int> v(n,-1);
    v[0]=x;

    for(int i=0;i<n;i++) {
        if(i&(~x)) break;
        else v[i] = i;
    }

    for(int &i:v) i=max(0,i);
    int a=0;
    for(auto i:v) a|=i;
    if(a!=x) v.back()=x;
    for(auto i:v) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
