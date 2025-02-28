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
    vector<int> v(n);
    vector<bool> b(n,false);
    for(auto &i:v) {
        cin >> i;
        b[i-1] = true;
    }
    for(int i=0;i<n;i++) if(not b[i]) {
        int q;
        if(i==n-1) q=1;
        else q=i+2;
        cout << "? " << i+1 << ' ' << q << '\n';
        cout.flush();
        cin >> q;

        if(q==0) cout << "! A\n";
        else cout << "! B\n";
        cout.flush();
        return;
    }

    int p1,pn;
    for(int i=0;i<n;i++) {
        if(v[i]==1) p1 = i+1;
        else if(v[i]==n) pn = i+1;
    }
    cout << "? " + to_string(p1) + " " + to_string(pn) + "\n";
    cout.flush();
    int x,y;
    cin >> x;
    cout << "? " + to_string(pn) + " " + to_string(p1) + "\n";
    cout.flush();
    cin >> y;

    if(x>=n-1) {
        if(x==y) cout << "! B\n";
        else cout << "! A\n";
        cout.flush();
    }
    else cout << "! A\n";
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
