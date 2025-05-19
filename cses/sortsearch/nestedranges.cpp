#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct cmp {

};

int main() { _
    int n;
    cin >> n;
    vector<pair<pair<int,int>,int>> v(n);
    vector<int> a1(n), a2(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].ff.ff >> v[i].ff.ss;
        v[i].ss = i;
    }

    // sort(v.begin(),v.end());
    sort(v.begin(),v.end(),
    [&](const pair<pair<int,int>,int> &p1,const pair<pair<int,int>,int> &p2) -> bool {
        if(p1.ff.ff<p2.ff.ff) return true;
        if(p1.ff.ff>p2.ff.ff) return false;
        return p1.ff.ss>p2.ff.ss;
    });
    
    multiset<int> m;
    
    for(int i=n-1;i>=0;i--) {
        auto it = m.upper_bound(v[i].ff.ss);
        if(it!=m.begin() and *prev(it)<=v[i].ff.ss) a1[v[i].ss] = 1;
        else a1[v[i].ss] = 0;
        m.insert(v[i].ff.ss);
    }
    
    
    m.clear();

    for(int i=0;i<n;i++) {
        auto it = m.lower_bound(v[i].ff.ss);
        if(it==m.end()) a2[v[i].ss] = 0;
        else a2[v[i].ss] = 1;

        m.insert(v[i].ff.ss);
    }

    for(int i:a1) cout << i << ' ';
    cout << '\n';
    for(int i:a2) cout << i << ' ';
    cout << '\n';
    
    return 0;
}
