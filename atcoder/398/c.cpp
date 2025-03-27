#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    map<int,int> m;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    for(int i=0;i<n;i++) {
        int x = v[i];
        m[x]++;
    }
    int x=-1;
    for(auto i:m) 
        if(i.ss==1) x=max(x,i.ff);
    

    for(int i=0;i<n;i++) if(v[i]==x) {
        cout << i+1 << '\n';
        return;
    }
    cout << x << '\n';
}

int main() { _
    int t=1;
    while(t--) solve();
    return 0;
}
