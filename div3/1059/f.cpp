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
        
        while(s2.size() and *s2.begin()<=i) {
            s2.erase(s2.begin());
        }
        
        if(s2.size()>=1ull) {
            for(int k=*s2.begin();k<=*s2.rbegin();k++) {
                if(init[k]>i) continue;
                int pj = k;
                int lx=2;
                for(int j=1;j<i;j++) cout << lx++ << ' ';
                cout << 1 << ' ';
                for(int j=i+1;j<pj;j++) cout << lx++ << ' ';
                cout << 0 << ' ';
                for(int j=pj+1;j<=n;j++) cout << lx++ << ' ';
                cout << '\n';
                return;
            }

        }
    }

    s2.clear();
    a=m-1;
    for(int i=0;i<m;i++) swap(v[i].ff,v[i].ss);
    sort(v,v+m);
    for(int i=0;i<m;i++) swap(v[i].ff,v[i].ss);

    for(int i=0;i<(int)init.size();i++) init[i] = INT_MAX;

    for(int i=0;i<m;i++) {
        for(int j=v[i].ff;j<=v[i].ss;j++) init[j]=min(init[j],v[i].ss);
    }

    for(int i=n;i;i--) {
        while(a<=0 and v[a].ss>=i) {
            s2.insert(v[a].ff);
            a--;
        }

        while(s2.size() and *s2.begin()>=i) {
            s2.erase(s2.begin());
        }

        if(s2.size()>=1ull) { // i agr é o segundo
            for(int k=*s2.rbegin();k>=*s2.begin();k--) {
                if(init[k]<i) continue;

                int pj = k;
                int lx=2;
                for(int j=1;j<i;j++) cout << lx++ << ' ';
                cout << 0 << ' ';
                for(int j=i+1;j<pj;j++) cout << lx++ << ' ';
                cout << 1 << ' ';
                for(int j=pj+1;j<=n;j++) cout << lx++ << ' ';
                cout << '\n';
                return;
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
