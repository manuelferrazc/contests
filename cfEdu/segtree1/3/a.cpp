#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> v, st;

int get(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return 0;
    if(lq<=l and r<=rq) return st[pos];

    int m = (l+r)>>1;
    return get(2*pos+1,l,m,lq,rq)+get(2*pos+2,m+1,r,lq,rq);
}

void set(int pos, int l, int r, int i) {
    if(i<l or r<i) {st[pos];return;}
    if(l==r) {++st[pos];return;}
    ++st[pos];

    int m = (l+r)>>1;
    if(i<=m) ::set(2*pos+1,l,m,i);
    else ::set(2*pos+2,m+1,r,i);
}

int main() { _
    int n;
    cin >> n;
    v.resize(n);
    st.resize(4*(n+1),0);
    for(auto &i:v) cin >> i;

    for(int i=0;i<n;i++) {
        cout << get(0,0,n,v[i],n) << ' ';
        ::set(0,0,n,v[i]);
    }
    cout << '\n';

    return 0;
}
