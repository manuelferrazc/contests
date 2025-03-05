#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> v,vz,stt,stz;
vector<bool> inv;
int n;

void build(int pos, int l, int r) {
    if(l==r) {
        stt[pos] = v[l];
        stz[pos] = vz[l];
        return;
    }

    int m = (l+r)>>1, ls = 2*pos+1;
    build(ls,l,m);
    build(ls+1,m+1,r);
    stt[pos] = stt[ls]^stt[ls+1];
    stz[pos] = stz[ls]^stz[ls+1];
}

int getAll(int pos, int l, int r, int lq, int rq) {
    if(r<lq or rq<l) return 0;
    if(lq<=l and r<=rq) return stt[pos];
    
    int m = (l+r)>>1;
    return getAll(2*pos+1,l,m,lq,rq)^getAll(2*pos+2,m+1,r,lq,rq);
}

void propag(int pos, int l, int r) {
    if(inv[pos]==false) return;
    inv[pos] = false;
    stz[pos] = getAll(0,0,n-1,l,r)^stz[pos]; 
    if(l==r) return;

    inv[2*pos+1] = not inv[2*pos+1];
    inv[2*pos+2] = not inv[2*pos+2];
}

int replace(int pos, int l, int r, int lq, int rq) {
    propag(pos,l,r);
    if(r<lq or rq<l) return stz[pos];
    if(lq<=l and r<=rq) {
        inv[pos] = true;
        return stz[pos]^getAll(0,0,n-1,l,r);
    }

    int m = (l+r)>>1,ls=2*pos+1;
    stz[pos] = replace(ls,l ,m,lq,rq)^replace(ls+1,m+1,r,lq,rq);

    return stz[pos];
}

int getZ(int pos, int l, int r) {
    propag(pos,l,r);
    return stz[pos];
}

void solve() {
    cin >> n;
    v.resize(n);
    for(int &i:v) cin >> i;
    string s;
    cin >> s;
    vz.resize(n);

    for(int i=0;i<n;i++) {
        if(s[i]=='0') vz[i] = v[i];
        else vz[i] = 0;
    }

    stt.resize(4*n);
    stz.resize(4*n);
    inv.assign(4*n,false);

    build(0,0,n-1);

    int q;
    cin >> q;

    while(q--) {
        int op;
        cin >> op;

        if(op==1) {
            int l,r;
            cin >> l >> r;
            replace(0,0,n-1,l-1,r-1);
        } else {
            int g;
            cin >> g;
            if(g==0) cout << getZ(0,0,n-1) << ' ';
            else cout << (getZ(0,0,n-1)^getAll(0,0,n-1,0,n-1)) << ' ';
        }
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
