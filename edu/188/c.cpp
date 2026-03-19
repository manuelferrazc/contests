#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll a,b,c,m;
    cin >> a >> b >> c >> m;

    ll ab = lcm(a,b), bc = lcm(b,c), ac = lcm(a,c);
    ll abc = lcm(ab,c);

    ll qabc = m/abc;

    ll qa = 2*qabc;
    ll qb = qa, qc = qa;

    ll qab = m/ab - qabc;
    ll qac = m/ac - qabc;
    ll qbc = m/bc -qabc;

    qa += (qab+qac)*3;
    qb += (qab+qbc)*3;
    qc += (qac+qbc)*3;

    qa += (m/a - qab - qac - qabc)*6;
    qb += (m/b - qab - qbc - qabc)*6;
    qc += (m/c - qac - qbc - qabc)*6;
    

    cout << qa << ' ' << qb << ' ' << qc << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
