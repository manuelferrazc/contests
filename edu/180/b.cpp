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
    for(int &i:v) cin >> i;

    if(n==2 and abs(v[0]-v[1])>1) cout << "-1\n";
    else {
        int ok = 0;
        for(int i=0;i<n-1;i++) {
            if(abs(v[i]-v[i+1])<=1) {
                ok = 1;
                break;
            } else if (i and (v[i-1]>=min(v[i],v[i+1])-1 and v[i-1]<=max(v[i],v[i+1])+1)) ok = 2;
            else if(i+2<n and (v[i+2]>=min(v[i],v[i+1])-1 and v[i+2]<=max(v[i],v[i+1])+1)) ok = 2;
        }
        if(ok==1) cout << "0\n";
        else if(ok==0) cout << "-1\n";
        else cout << "1\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
