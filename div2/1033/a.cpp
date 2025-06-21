#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll l[3],b[3];
    for(int i=0;i<3;i++) cin >> l[i] >> b[i];
    bool ok = false;
    if(l[0]==l[1] and l[1]==l[2] and l[2]==(b[0]+b[1]+b[2])) ok = true;
    if(b[0]==b[1] and b[1]==b[2] and b[2]==(l[0]+l[1]+l[2])) ok = true;
    if(l[0]==l[1]+l[2] and b[1]==b[2] and b[1]+b[0]==l[0]) ok = true;
    for(int i=0;i<3;i++) if(l[i]==l[(i+1)%3]+l[(i+2)%3] and b[(i+1)%3]==b[(i+2)%3] and b[(i+1)%3]+b[i]==l[i]) ok = true;
    for(int i=0;i<3;i++) if(b[i]==b[(i+1)%3]+b[(i+2)%3] and l[(i+1)%3]==l[(i+2)%3] and l[(i+1)%3]+l[i]==b[i]) ok = true;

    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
