#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;
    double ans=0;
    double nans = 1;
    vector<int> v(n);
    for(auto &i:v) cin >> i;
    bool s=true;
    for(int i=1;i<n;i++) {
        if(v[i-1]>v[i]) s=false;
    }
    
    if(s) {
        while(m--) cin >> n >> ans;
        cout << nans << '\n';
        return;
    }

    int idx;
    {
        auto x = v;
        sort(x.begin(),x.end());
        for(int i=n-1;i>=0;i--) if(v[i]!=x[i]) {
            idx=i+1;
            break;
        }
    }

    while(m--) {
        double p;
        cin >> n >> p;
        if(n<idx) continue;
        double sa = nans*p;
        ans+=sa;
        nans-=sa;
    }
    
    cout << ans << '\n';
}

int main() { _
    cout << fixed << setprecision(15);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
