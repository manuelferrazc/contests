#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
#define x ff.ff
#define y ff.ss
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<pair<pair<ll,ll>,int>> v(n), q1,q2,q3,q4,a1,a2;
    for(int i=0;i<n;i++) {
        v[i].ss = i+1;
        cin >> v[i].x >> v[i].y;
    }

    if(n==2) {
        cout << "1 2\n";
        return;
    }

    sort(v.begin(),v.end());

    for(ull i=0,j=v.size()-1;i<j;i++,j--) {
        a1.push_back(v[i]);
        a2.push_back(v[j]);
    }

    auto s = [&](pair<pair<ll,ll>,int> const &a, pair<pair<ll,ll>,int> const &b) -> bool {
        if(a.y<b.y) return true;
        if(a.y>b.y) return false;
        return a.x<b.x;
    };

    sort(a1.begin(),a1.end(),s);
    sort(a2.begin(),a2.end(),s);

    for(ull i=0,j=a1.size()-1;i<=j;i++,j--) {
        q2.push_back(a1[j]);
        if(i!=j)q3.push_back(a1[i]);
    }

    for(ull i=0,j=a2.size()-1;i<=j;i++,j--) {
        if(i!=j) q1.push_back(a2[j]);
        q4.push_back(a2[i]);
    }
    // ll ans=0;
    for(ull i=0;i<q1.size();i++) cout << q1[i].ss << ' ' << q3[i].ss << '\n';
    // for(ull i=0;i<q1.size();i++) ans+=abs(q1[i].x-q3[i].x)+abs(q1[i].y-q3[i].y);
    for(ull i=0;i<q2.size();i++) cout << q2[i].ss << ' ' << q4[i].ss << '\n';
    // for(ull i=0;i<q2.size();i++) ans+=abs(q2[i].x-q4[i].x)+abs(q2[i].y-q4[i].y);
    // cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
