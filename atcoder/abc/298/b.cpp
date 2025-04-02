#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void rotate(vector<vector<int>> &v) {
    vector<vector<int>> a(v.size(),vector<int>(v.size()));
    for(ull i=0;i<v.size();i++) for(ull j=0;j<v.size();j++) a[i][j] = v[i][j];

    for(ull i=0;i<v.size();i++) {
        for(ull j=0;j<v.size();j++) {
            v[i][j] = a[v.size()-j-1][i];
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n)), b(n,vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> b[i][j];

    for(int r=0;r<4;r++) {
        bool bb=true;
        // for(int i=0;i<n;i++) {for(int j=0;j<n;j++) cout << a[i][j];cout << endl;}
        // cout << endl;
        for(int i=0;i<n and bb;i++) for(int j=0;j<n;j++) if(a[i][j] and not b[i][j]) {bb=false;break;}
        if(bb) {cout << "Yes\n"; return;}
         rotate(a);
    }

    cout << "No\n";
}

int main() { _
    solve();
    return 0;
}
