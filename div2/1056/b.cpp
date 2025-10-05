#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void print(vector<string> &v) {
    cout << "YES\n";
    for(string &i:v) cout << i << '\n';
}

void solve() {
    int n,k;
    cin >> n >> k;

    int rr = n*n - k;
    if(rr==1) {
        cout << "NO\n";
        return;
    }

    vector<string> v(n,string(n,'U'));

    if(rr==0) return print(v);

    v[n-2][n-1] = 'D';
    rr-=2;

    for(int i=n-1;i>=n-2 and rr;i--) {
        for(int j = n-2;j>=0 and rr;j--) {
            v[i][j] = 'R';
            rr--;
        }
    }

    for(int i=n-3;i>=0 and rr;i--) {
        for(int j = n-1;j>=0 and rr;j--) {
            v[i][j] = 'D';
            rr--;
        }
    }

    print(v);
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
