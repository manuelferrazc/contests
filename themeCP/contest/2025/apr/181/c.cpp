#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

string con, ncon;

int calc(int x) {
    int i=x;
    for(char c:con) {
        if(c==ncon[i]) {
            i++;
            if(i==ncon.size()) return 0;
        }
    }
    return ncon.size()-i;
}

void solve() {
    cin >> con >> ncon;

    int ans=con.size()+ncon.size();
    for(int i=0;i<ncon.size();i++) {
        ans = min(ans,i+(int)con.size()+calc(i));
    }
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
