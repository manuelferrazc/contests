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
    pair<int,int> v[m];
    int lx=2;
    
    vector<int> init(n+1,-1);

    for(int i=0;i<m;i++) {
        cin >> v[i].ff >> v[i].ss;

        for(int j=v[i].ff;j<=v[i].ss;j++) init[j]=max(init[j],v[i].ff);
    }

    sort(v,v+m);
    multiset<int> s;

    int a=0;

    // mex(M) = 0
    for(int i=1;i<=n;i++) {
        while(a<m and v[a].ff<=i) {
            s.insert(v[a].ss);
            a++;
        }

        while(s.size() and *s.begin()<i) {
            s.erase(s.begin());
        }

        if(s.size()==m) {
            for(int j=1;j<i;j++) cout << j << ' ';
            cout << 0 << ' ';
            for(int j=i;j<n;j++) cout << j << ' ';
            cout << '\n';
            return;
        }
    }

    a=0;
    s.clear();
    // mex(M) = 1
    for(int i=1;i<=n;i++) {
        while(a<m and v[a].ff<=i) {
            s.insert(v[a].ss);
            a++;
        }

        while(s.size() and *s.begin()<i) {
            s.erase(s.begin());
        }

        if(s.empty()) {
            for(int j=1;j<i;j++) cout << j << ' ';
            cout << 0 << ' ';
            for(int j=i;j<n;j++) cout << j << ' ';
            cout << '\n';
            return;
        }
    }
    
    a=0;
    set<int> s2;
    for(int i=1;i<=n;i++) {
        while(a<m and v[a].ff<=i) {
            s2.insert(v[a].ss);
            a++;
        }
        
        while(s2.size() and *s2.begin()<i) 
            s2.erase(s2.begin());
        
        if(s2.size()) {
            if(i+1<=*s2.rbegin() and i!=*s2.begin()) {
                int pj = i+1;
                // cout << "cu ";
                for(int j=1;j<i;j++) cout << lx++ << ' ';
                cout << 0 << ' ';
                for(int j=i+1;j<pj;j++) cout << lx++ << ' ';
                cout << 1 << ' ';
                for(int j=pj+1;j<=n;j++) cout << lx++ << ' ';
                cout << '\n';
                return;
            }

            for(int j=i+1;j<=n;j++) {
                if(init[j]<=i) { // todo intervalo q contém o j tbm contém o i
                    for(int k=1;k<i;k++) cout << lx++ << ' ';
                    cout << 1 << ' ';
                    for(int k=i+1;k<j;k++) cout << lx++ << ' ';
                    cout << 0 << ' ';
                    for(int k=j+1;k<=n;k++) cout << lx++ << ' ';
                    cout << '\n';
                    return;
                }
            }

        }

    }

    // mex(M)=2
    cout << "0 2 1 ";
    for(int i=3;i<n;i++) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
