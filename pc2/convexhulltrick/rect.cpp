#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct rect {
    ll x,y,a;
    
    bool operator<(rect &o) {
        return x<o.x;
    }

    rect() {}

    friend istream& operator>>(istream & in, rect &r) {
        in >> r.x >> r.y >> r.a;
        return in;
    }

    ll val() {
        return x*y-a;
    }
};

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
        // f(x) = ax+b
        // g(x) = cx+d
        // ax+b = cx+d
        // ax-cx = d-b
        // x(a-c) = d-b
        // x = (d-b)/(a-c)

        return (b-o.b)/(double)(o.a-a);
    }
};

ll findopt(deque<line> &dq, ll x) {
    while(dq.size()>1ull and dq.back().val(x)<=dq[dq.size()-2].val(x)) dq.pop_back();

    return dq.back().val(x);
}

int main() { _
    int n;
    cin >> n;

    rect *v = new rect[n];
    for(int i=0;i<n;i++) cin >> v[i];

    sort(v,v+n);

    deque<line> dq;
    ll ans = 0;

    dq.push_back(line(0,0));
    // cout << ans << ' ';

    for(int i=0;i<n;i++) {
        ll act = v[i].val()+findopt(dq,v[i].y);

        ans = max(ans,act);

        line newline(-v[i].x,act);

        while(dq.size()>1ull and dq[0].intersect(newline)>=dq[0].intersect(dq[1])) {
            dq.pop_front();
            // if(dq[0].intersect(newline)>=dq[0].intersect(dq[1])+1e-9) dq.pop_front();
            // else break;
        }

        // cout << act << ' ';

        dq.push_front(newline);
    }

    cout << ans << '\n';

    delete[] v;

    return 0;
}