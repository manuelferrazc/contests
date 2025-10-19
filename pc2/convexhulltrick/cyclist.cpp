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
    while(dq.size()>1ull and dq.front().val(x)<=dq[1].val(x)) dq.pop_front();

    return dq.front().val(x);
}

int main() { _
    int n,q;
    cin >> n >> q;

    // ff -> velocidade, ss -> 
    vector<ll> vel(n,0), space(n,0), when(n,0);

    deque<line> dq;

    dq.push_back(line(0,0));

    ll op,time,c,ns;

    while(q--) {
        cin >> op >> time;

        if(op==1) {
            cin >> c >> ns;
            c--;

            if(vel[c]==ns) continue;

            line newline(ns,space[c]+(time-when[c])*vel[c]-time*ns);
            space[c] += vel[c]*(time-when[c]);
            vel[c] = ns;
            when[c] = time;
            
            if(dq.back().a>newline.a) continue;
            else if(dq.back().a==newline.a and dq.back().b<newline.b) dq.pop_back(); 

            while(dq.size()>1ull and dq.back().intersect(newline)<=dq.back().intersect(dq[dq.size()-2])) {
                dq.pop_back();
            }

            dq.push_back(newline);

        } else cout << findopt(dq,time) << '\n';
    }

    return 0;
}