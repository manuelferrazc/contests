#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> v,st;

int build(int pos, int l, int r) {
    if(l==r) {
        if(v[l]<10) st[pos] = 0;
        else st[pos] = 1;
    } else {
        int m = (l+r)>>1;
        st[pos] = build(2*pos+1,l,m)+build(2*pos+2,m+1,r);
    }
    return st[pos];
}

void change(int pos, int l, int r, int lq, int rq) {
    if(r<lq or rq<l or st[pos]==0) return;
    if(l==r) {
        int s = 0;
        for(int i=v[l];i;i/=10) s+=i%10;
        v[l] = s;
        if(s<10) st[pos]--;
        return;
    }
    int m = (l+r)>>1,ls=2*pos+1;
    change(ls,l,m,lq,rq);
    change(ls+1,m+1,r,lq,rq);
    st[pos] = st[ls]+st[ls+1];
}

void solve() {
    int n,q;
    cin >> n >> q;

    v.resize(n);
    st.resize(n<<2);
    for(int &i:v) cin >> i;
    build(0,0,n-1);

    int op;
    while(q--) {
        cin >> op;
        if(op==1) {
            int l,r;
            cin >> l >> r;
            change(0,0,n-1,l-1,r-1);
        } else {
            int x;
            cin >> x;
            cout << v[x-1] << ' ';
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
