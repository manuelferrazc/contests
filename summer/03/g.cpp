#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct ST {
    int n;
    int *st;

    ST(int _n) {
        n = _n;
        st = new int[4*n];
        for(int i=0;i<4*n;i++) st[i] = 0;
    }

    ~ST() {
        delete[] st;
    }

    void add(int pos, int l, int r, int x) {
        while(true) {
            st[pos]++;
            if(l==r) break;
            
            int m = (l+r)/2;
            pos = 2*pos+1;

            if(x<=m) r = m;
            else {
                l = m+1;
                pos++;
            }
        }
    }

    int get(int pos, int l, int r, int lq, int rq) {
        if(rq<l or r<lq) return 0;
        if(lq<=l and r<=rq) return st[pos];
        
        int m = (l+r)/2,ls = 2*pos+1;
        return get(ls,l,m,lq,rq)+get(ls+1,m+1,r,lq,rq);
    }

    int get(int l, int r) {
        if(r==-1) r = n-1;
        return get(0,0,n-1,l,r);
    }

    void add(int x) {
        add(0,0,n-1,x);
    }
};

bool comp(const array<int,4> &a, const array<int,4> &b) {
    if(a[0]<b[0]) return true;
    if(a[0]>b[0]) return false;

    if(a[1]>b[1]) return true;
    if(a[1]<b[1]) return false;

    return a[2]<b[2];
}

void solve(int n) {
    vector<pair<int,int>> v(n);
    vector<pair<int,int>> aux(2*n);

    for(int i=0;i<n;i++) {
        cin >> v[i].ff >> v[i].ss;
        aux[2*i].ff = v[i].ff;
        aux[2*i+1].ff = v[i].ss;

        aux[2*i].ss = aux[2*i+1].ss = 0;
    }

    sort(aux.begin(),aux.end());
    aux.erase(unique(aux.begin(),aux.end()),aux.end());

    for(ull i=0;i<aux.size();i++) aux[i].ss = i;

    pair<int,int> p;
    p.ss = -1;
    for(int i=0;i<n;i++) {
        p.ff = v[i].ff;
        v[i].ff = lower_bound(aux.begin(),aux.end(),p)->ss;
        p.ff = v[i].ss;
        v[i].ss = lower_bound(aux.begin(),aux.end(),p)->ss;
    }

    ST st(aux.back().ss+2);

    vector<array<int,4>> ev;
    for(int i=0;i<n;i++) {
        ev.push_back({v[i].ff,v[i].ss,0,i});
        ev.push_back({v[i].ff,v[i].ss,1,i});
    }

    sort(ev.begin(),ev.end(), comp);
    
    int ans[n];

    for(ull i=0;i<ev.size();i++) {
        int r = ev[i][1];
        int op = ev[i][2];
        int id = ev[i][3];

        if(op==0) ans[id] = st.get(r,-1);
        else st.add(r);
    }

    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() { _
    int n;
    while(cin >> n) solve(n);
    return 0;
}
