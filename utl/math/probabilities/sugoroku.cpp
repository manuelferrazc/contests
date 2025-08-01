#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

pair<double,double> operator+(pair<double,double> p,pair<double,double> q) {
    return make_pair(p.ff+q.ff,p.ss+q.ss);
}

pair<double,double> operator*(pair<double,double> p,double x) {
    return make_pair(p.ff*x,p.ss*x);
}

void set1(vector<double> &st, int pos, int l, int r, int lq, int rq, double x) {
    if(rq<l or r<lq) return;
    if(lq<=l and r<=rq) {
        st[pos]+=x;
        return;
    }

    int m = (l+r)>>1, ls = 2*pos+1;
    set1(st,ls,l,m,lq,rq,x);
    set1(st,ls+1,m+1,r,lq,rq,x);
}

double get1(vector<double> &st, int pos, int l, int r, int i) {
    if(i<l or r<i) return 0;
    if(l==r) return st[pos];

    int m = (l+r)>>1, ls = 2*pos+1;
    return get1(st,ls,l,m,i)+get1(st,ls+1,m+1,r,i)+st[pos];
}

pair<double,double> set2(vector<pair<double,double>> &st, int pos, int l, int r, int i, pair<double,double> p) {
    if(i<l or r<i) return st[pos];
    if(l==r) return st[pos] = p;

    int m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] =  set2(st,ls,l,m,i,p)+set2(st,ls+1,m+1,r,i,p);
}

pair<double,double> get2(vector<pair<double,double>> &st, int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return make_pair(0.0,0.0);
    if(lq<=l and r<=rq) return st[pos];

    int m = (l+r)>>1, ls = 2*pos+1;
    return get2(st,ls,l,m,lq,rq)+get2(st,ls+1,m+1,r,lq,rq);
}

int main() { _
    int n,m,k;
    cin >> n >> m >> k;

    vector<double> stp((n+1)<<2,0);
    set1(stp,0,0,n,0,0,1);
    set<int> err;
    for(int i=0;i<k;i++) {
        int x;
        cin >> x;
        err.insert(x);
    }

    double ex=0;
    for(int i=0;i<n;i++) {
        if(err.count(i)) continue;
        set1(stp,0,0,n,i+1,min(n,i+m),get1(stp,0,0,n,i)/m);
        if(i+m>n) ex+=get1(stp,0,0,n,i)*(i+m-n)/(double)m;
    }

    set1(stp,0,0,n,n,n,ex);
    if(get1(stp,0,0,n,n)<0.00000000001) {
        cout << -1 << '\n';
        return 0;
    }

    vector<pair<double,double>> st2((n+1)<<2,make_pair(0,0));

    for(int i=n-1;i>=0;i--) {
        if(err.count(i)) {
            set2(st2,0,0,n,i,make_pair(0.0,1.0));
            continue;
        }


        auto p = get2(st2,0,0,n,i+1,min(n,i+m));
        p=p*(1.0/m);
        if(i+m>n) {
            auto x = get2(st2,0,0,n,n,n);
            x = x*((i+m-n+1)/(double)m);
            p = p + x;
        }
        p.ff+=1;
        set2(st2,0,0,n,i,p);
    }

    auto p = get2(st2,0,0,n,0,0);

    double ans = 1 - p.ss;
    ans = p.ff/ans;
    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}
