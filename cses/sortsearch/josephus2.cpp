#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> st(800'001);

int build(int pos, int l, int r) {
    if(l==r) return st[pos] = 1;

    int m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] = build(ls,l,m)+build(ls+1,m+1,r);
}

int set(int pos, int l, int r, ll i) {
    if(i<l or r<i) return st[pos];
    if(l==r) return st[pos] = 0;

    int m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] = ::set(ls,l,m,i)+::set(ls+1,m+1,r,i);
}

int get(int pos, int l, int r, int q) {
    if(l==r) return l;
    int m = (l+r)>>1, ls = 2*pos+1;
    if(st[ls]<q) return get(ls+1,m+1,r,q-st[ls]);
    else return get(ls,l,m,q);
}

int main() { 
    build(0,0,200000);
    ll n,k,act=0;

    cin >> n >> k;
    while(n) {
        act+=k;
        act%=n;
        ll x = get(0,0,200000,(act%n)+1);
        cout << x+1 << ' ';
        ::set(0,0,200000,x);
        n--;
    }

    cout << '\n';
    return 0;
}
