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
    int a[n],b[n];
    for(int i=0;i<n;i++) cin >> i[a];
    for(int i=0;i<n;i++) cin >> i[b];

    vector<int> op(n),pass(n);
    if(a[0]==b[0]) op[0] = pass[0] = 0;
    else if(a[0]) {
        op[0] = 1;
        pass[0] = 2;
    } else {
        op[0] = 2;
        pass[0] = 1;
    }

    for(int i=1;i<n;i++) {
        if(i&1) { // mai, b
            if(a[i]==b[i]) {
                if(op[i-1]==1 or pass[i-1]==1) op[i] = pass[i] = 1;
                else if(op[i-1]==0 or pass[i-1]==0) op[i] = pass[i] = 0;
                else op[i] = pass[i] = 2;
            } else {
                if(op[i-1]==2 or pass[i-1]==2) op[i] = pass[i] = 0;
                else if(op[i-1]==1 or pass[i-1]==1) op[i] = pass[i] = 0;
                else op[i] = pass[i] = 2;
            }
        } else { // ajusai, a
            if(a[i]==b[i]) {
                if(op[i-1]==2 or pass[i-1]==2) op[i] = pass[i] = 2;
                else if(op[i-1]==0 or pass[i-1]==0) op[i] = pass[i] = 0;
                else op[i] = pass[i] = 1;
            } else {
                if(op[i-1]==1 or pass[i-1]==1) op[i] = pass[i] = 0;
                else if(op[i-1]==2 or pass[i-1]==2) op[i] = pass[i] = 0;
                else op[i] = pass[i] = 1;
            }
        }
    }

    if(n&1) {
        if(op[n-1]==1 or pass[n-1]==1) cout << "Ajisai\n";
        else if(op[n-1]==0 or pass[n-1]==0) cout << "Tie\n";
        else cout << "Mai\n";
    } else {
        if(op[n-1]==2 or pass[n-1]==2) cout << "Mai\n";
        else if(op[n-1]==0 or pass[n-1]==0) cout << "Tie\n";
        else cout << "Ajisai\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
