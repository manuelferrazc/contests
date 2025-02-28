#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string l,r;
    cin >> l >> r;
    l = string(r.size()-l.size(),'0')+l;
    int ans = 0;
    for(ull i=0;i<r.size();i++) {
        if(r[i]==l[i]) continue;
        if(abs(r[i]-l[i])>=1) {
            ans+=abs(r[i]-l[i]);
            i++;
            for(;i<r.size();i++) ans+=9;
            break;
        }
        else ans+= abs(r[i]-l[i]);
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
