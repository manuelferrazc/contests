#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<bool> lazy;
vector<int> st;

int get(int pos,int l, int r) {
    if(lazy[pos]) return r-l+1-st[pos];
    return st[pos];
}

void propagate(int pos, int l, int r) {
    if(lazy[pos]==false) return;
    lazy[pos] = 0;
    if(l==r) {
        st[pos] = 1-st[pos];
        return;
    }

    int p = 2*pos+1;
    lazy[p] = not lazy[p];
    lazy[p+1] = not lazy[p+1];
    st[pos] = r-l+1-st[pos];
}

int inv(int pos, int l, int r, int lq, int rq, bool acc=false) {
    if(r<lq or rq<l) return get(pos,l,r);
    if(lq<=l and r<=rq) {
        lazy[pos] = not lazy[pos];
        return get(pos,l,r);
    }

    int m = (l+r)>>1;
    st[pos] = inv(2*pos+1,l,m,lq,rq)+inv(2*pos+2,m+1,r,lq,rq);
    return get(pos,l,r);
}

void get(int pos, int l, int r, int k) {
    propagate(pos,l,r);
    if(l==r) {
        cout << l << '\n';
        return;
    }
    int p=2*pos+1,m=(l+r)>>1;
    
    if(get(p,l,m)<k) get(p+1,m+1,r,k-get(p,l,m));
    else get(p,l,m,k);
}

int main() { _
    int n,m,op,a,b;
    cin >> n >> m;

    lazy.assign(n<<2,false);
    st.assign(n<<2,0);

    while(m--) {
        cin >> op >> a;
        if(op==1) {
            cin >> b;
            b--;
            inv(0,0,n-1,a,b);
        } else get(0,0,n-1,a+1); 
    }

    return 0;
}
