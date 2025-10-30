#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct line { // f(x) = ax+b
    ll a, b;

    line(ll _a=0, ll _b=0) {
        a=_a;
        b=_b;
    }

    ll val(ll x) {
        return a*x+b;
    }

    double intersect(const line &o) {
        return (b-o.b)/(double)(o.a-a);
    }
};

ll findopt(deque<line> &dq, ll x) {
    if(dq.empty()) return 1e15;
    if(dq.size()==1) return dq[0].val(x);

    int l = 0, r=dq.size()-1;

    while(l<r) {
        int m = (l+r)/2;
        if(dq[m].val(x)>dq[m+1].val(x)) l=m+1;
        else r=m;
    }

    return dq[l].val(x);
}

int main() { _
    int n;
    cin >> n;

    pair<ll,ll> v1[n];
    for(int i=0;i<n;i++) cin >> v1[i].ff >> v1[i].ss;
    
    sort(v1,v1+n);
    
    ll maxy=0;
    vector<pair<ll,ll>> v;

    for(int i=n-1;i>=0;i--) {
        if(v1[i].ss>maxy) {
            v.push_back(v1[i]);
            maxy = v1[i].ss;
        }
    }

    reverse(v.begin(),v.end());

    deque<line> dq;
    
    ll costlast=0;
    n = v.size();

    for(int i=0;i<n;i++) {
        line newline(v[i].ss,costlast);
        
        while(dq.size()>1ull and newline.intersect(dq[dq.size()-2])<=dq.back().intersect(dq[dq.size()-2]))
            dq.pop_back();
        dq.push_back(newline);
        
        costlast = findopt(dq,v[i].ff);
    }

    cout << costlast << '\n';

    return 0;
}
