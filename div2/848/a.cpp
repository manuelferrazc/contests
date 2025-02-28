#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,s=0;
    cin >> n;
    vector<int> v(n);
    for(auto &i:v) {cin >> i;s+=i;}
    bool b = false;
    for(int i=0;i<n-1;i++) {
        if(v[i]==-1 and v[i+1]==-1) {
            cout << s+4 << '\n';
            return;
        }
        if((v[i]==-1 and v[i+1]==1) or (v[i]==1 and v[i+1]==-1)) b=true;
    }
    cout << (b?s:s-4) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
