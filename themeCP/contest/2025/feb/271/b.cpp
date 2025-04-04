#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> c(10'000'001,-1);

void solve() {
    int l,r;
    cin >> l >> r;
    if(r<=3) cout << "-1\n";
    else if((r&1)==0) cout << (r>>1) << ' ' << (r>>1) << '\n';
    else {
        for(int i=r;i>=max(l,4);i--) {
            if(c[i]!=i) {
                cout << i-c[i] << ' ' << c[i] << '\n';
                return;
            }
        }
        cout << "-1\n";
    }
}

int main() { _
    for(ull i=2;i<c.size();i++) {
        if(c[i]==-1) c[i] = i;
        else continue;
        for(ull j=i+i;j<c.size();j+=i) c[j] = i;
    }

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
