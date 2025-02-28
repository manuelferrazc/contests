#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> v, st;

void set(int pos, int l, int r, int i) {
    if(i<l or r<i) return;
    st[pos]++;
    if(l==r) return;

    int m=(l+r)>>1;
    ::set(2*pos+1,l,m,i);
    ::set(2*pos+2,m+1,r,i);
}

int get(int pos, int l, int r, int lq, int rq) {
    if(r<lq or rq<l) return 0;
    if(lq<=l and r<=rq) return st[pos];

    int m=(l+r)>>1;
    return get(2*pos+1,l,m,lq,rq)+get(2*pos+2,m+1,r,lq,rq);
}

int main() { _
    int n;
    cin >> n;
    v.resize(2*n);
    for(auto &i:v) cin >> i;
    st.assign(n<<3,0);

    vector<int> first(n,-1), ans(n);
    n<<=1;
    for(int i=0;i<n;i++) {
        if(first[v[i]-1]==-1) first[v[i]-1]=i;
        else {
            ans[v[i]-1] = get(0,0,n-1,first[v[i]-1],i);
            ::set(0,0,n-1,first[v[i]-1]);
        }
    }

    for(auto i:ans) cout << i << ' ';
    cout << '\n';

    return 0;
}
