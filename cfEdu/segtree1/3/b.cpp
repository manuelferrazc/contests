#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> st,v;

int build(int pos, int l, int r) {
    if(l==r) return st[pos] = 1;

    int m = (l+r)>>1;
    return st[pos] = build(2*pos+1,l,m)+build(2*pos+2,m+1,r);
}

void set(int pos, int l, int r, int i) {
    if(i<l or r<i) return;
    st[pos]--;
    if(l==r) return; 
    int m = (l+r)>>1;
    ::set(2*pos+1,l,m,i);
    ::set(2*pos+2,m+1,r,i);
}

int get(int pos, int l, int r, int q) {
    if(l==r) return l+1;

    int m=(l+r)>>1, ls=2*pos+1;
    if(st[ls]<q) return get(ls+1,m+1,r,q-st[ls]);
    return get(ls,l,m,q);
}

int main() { _
    int n;
    cin >> n;
    v.resize(n);
    for(auto &i:v) cin >> i;
    st.resize(n*4);
    build(0,0,n-1);

    stack<int> ans;
    for(auto it = v.rbegin();it!=v.rend();it++) {
        ans.push(get(0,0,n-1,st[0]-*it));
        ::set(0,0,n-1,ans.top()-1);
    }

    while(ans.size()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << '\n';

    return 0;
}
