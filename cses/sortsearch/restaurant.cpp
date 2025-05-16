#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,ans=0;
    cin >> n;
    vector<int> ev;
    map<int,int> c;

    for(int i=0;i<n;i++) {
        pair<int,int> a;
        cin >> a.ff >> a.ss;
        c.insert(a);
        ev.push_back(a.ff);
        ev.push_back(a.ss);
    }

    sort(ev.begin(),ev.end());

    set<int> x;
    for(int i:ev) {
        if(c.count(i)) x.insert(c[i]);
        else x.erase(i);
        ans = max(ans,(int)x.size());
    }

    cout << ans << '\n';

    return 0;
}
