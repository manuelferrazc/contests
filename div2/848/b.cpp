#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m,d;
    cin >> n >> m >> d;
    vector<int> a(m);
    map<int,int> perm;
    for(int i=1;i<=n;i++) {
        cin >> a.front();
        perm.insert({a.front(),i});
    }
    for(auto &i:a) cin >> i;

    int ans = INT_MAX;
    m--;
    for(int i=0;i<m;i++) {
        if(perm.at(a[i])<perm.at(a[i+1]) and perm.at(a[i+1])<=perm.at(a[i])+d) {
            int x = perm.at(a[i+1])-perm.at(a[i]);
            ans = min(ans,x);
            int sn = d-(perm.at(a[i+1])-perm.at(a[i]))+1;
            if(perm.at(a[i])-1+(n-perm.at(a[i+1]))>=sn) ans = min(ans,sn);
        } else {
            cout << "0\n";
            return;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
