#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ul;

vector<int> st;

void set(int pos, int l, int r, int lq, int rq, int x) {
    if(r<lq or rq<l) return;
    
    if(lq<=l and r<=rq) {
        st[pos] = x;
        return;
    }
    
    if(st[pos]!=-1 and l!=r) {
        int p = 2*pos+1;
        st[p] = st[p+1] = st[pos];
        st[pos] = -1;
    }

    int m = (l+r)>>1;
    ::set(2*pos+1,l,m,lq,rq,x);
    ::set(2*pos+2,m+1,r,lq,rq,x);
}

int get(int pos, int l, int r, int i) {
    if(l==r or st[pos]!=-1) return st[pos];

    int m = (l+r)>>1;
    if(i<=m) return get(2*pos+1,l,m,i);
    else return get(2*pos+2,m+1,r,i);
}

int main() { _
    int n,m,op,a,b,c;
    cin >> n >> m;
    
    st.resize(n<<2,-1);

    while(m--) {
        cin >> op >> a;

        if(op==1) {
            cin >> b >> c;
            b--;
            ::set(0,0,n-1,a,b,c);
        } else cout << max(0,get(0,0,n-1,a)) << '\n';
    }

    return 0;
}
