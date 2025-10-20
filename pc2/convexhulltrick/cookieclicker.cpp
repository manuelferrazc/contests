#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define custo first
#define prod second
typedef long long ll;
typedef unsigned long long ull;


struct line { // f(x) = ax+b
    __int128 a, b;

    line(__int128 _a=0, __int128 _b=0) {
        a=_a;
        b=_b;
    }

    __int128 val(__int128 x) {
        // cout << (ll) x << '\n';
        // cout.flush();
        return a*x+b;
    }

    double intersect(const line &o) {
        return (b-o.b)/(double)(o.a-a);
    }
};

__int128 findopt(deque<line> &dq, __int128 x) {
    int l=0,r=dq.size()-1;
    while(l<r) {
        int m = (l+r)/2;
        
        if(dq[m].val(x)>dq[m+1].val(x)) r = m;
        else l=m+1;
    }

    return dq[l].val(x);
}

int main() { _
    int n;
    __int128 s;
    cin >> n;
    pair<ll,ll> v[n];
    cin >> v[0].prod;
    s = v[0].prod;

    for(int i=0;i<n;i++) cin >> v[i].prod >> v[i].custo;

    sort(v,v+n);

    deque<line> dq;

    dq.push_back(line(v[0].prod,0));

    for(int i=1;i<n;i++) {
        if(v[i].custo==0) {
            dq.back().a = v[i].prod;
            continue;
        }
        if((__int128)v[i].prod<=dq.back().a or (i<n-1 and v[i].custo==v[i+1].custo)) continue;
        if(v[i].custo>=s) break;

        __int128 ans = 0;
        __int128 l=1,r=v[i].custo,anst;

        while(l<=r) {
            __int128 m = (l+r)>>1;
            // cout << (ll)l  << '\n';
            // cout.flush();
            
            // int x;
            // cin >> x;
            // cout << "val de m:" << m << ", com size " << dq.size() << ", ";
            __int128 q = findopt(dq,m);
            // cout << "val: " << (ll)q << '\n';

            if(q>=(__int128)v[i].custo) {
                ans = q;
                anst = m;
                r = m-1;
            } else l = m+1;

        }

        // cout << v[i].prod << ' ' << ans-v[i].custo-anst*v[i].prod << '\n';

        line newline(v[i].prod,ans-v[i].custo-anst*v[i].prod);

        while(dq.size()>1ull and dq.back().intersect(newline)<=dq[dq.size()-2].intersect(dq.back())+1e-9) {
            dq.pop_back();
        }

        // exit(0);
        dq.push_back(newline);
    }

    __int128 ans = s, l=1,r=s;

    while(l<=r) {
        __int128 m = (l+r)>>1;
        if(findopt(dq,m)>=(__int128)s) {
            ans = m;
            r = m-1;
        } else l = m+1;
    }

    cout << (ll)ans << '\n';

    return 0;
}