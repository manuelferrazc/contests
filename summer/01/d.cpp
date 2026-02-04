#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct bit {
    int *v;
    int n;
    
    bit(int n2,int *v2) {
        n = n2;
        v = new int[n+1];
        for(int i=1;i<=n;i++) v[i] = 0;

        if(v2!=nullptr) {
            for(int i=1;i<=n;i++) {
                v[i]+=v2[i];
                int j = i+(i&(-i));
                if(j<=n) v[j]+=v[i];
            }
        }
    }
    
    ~bit() {
        delete[] v;
    }
    
    void update(int i, int x) {
        for(i+=1;i<=n;i+=(i&(-i))) v[i]+=x;
    }

    int pref(int i) {
        int r = 0;
        for(i++;i;i-=(i&(-i))) r+=v[i];
        return r;
    }

    int query(int l, int r) {
        return pref(r)-pref(l-1);
    }
};

int main() { _
    int n;
    cin >> n;

    map<int,list<int>> m;
    int v[n];
    for(int i=0;i<n;i++) {
        cin >> v[i];
        m[v[i]].push_back(i);
    }

    bit b(n,nullptr);

    for(auto it = m.begin();it!=m.end();it++) {
        int id = it->ss.front();
        b.update(id,1);
    }

    int q;
    cin >> q;
    int ans[q];

    vector<pair<int,int>> qr[n];
    for(int i=0;i<q;i++) {
        int l,r;
        cin >> l >> r;

        qr[l-1].push_back({r-1,i});
    }

    for(int i=0;i<n;i++) {
        for(auto [r,id]:qr[i]) ans[id] = b.query(i,r);
        
        b.update(i,-1);
        m[v[i]].pop_front();
        if(m[v[i]].size()) {
            int nx = m[v[i]].front();
            b.update(nx,1);
        } else m.erase(v[i]);
    }

    for(int i=0;i<q;i++) cout << ans[i] << '\n';

    return 0;
}
