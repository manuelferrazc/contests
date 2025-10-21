#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


struct line { // f(x) = ax²+bx+c
    ll a, b, c;

    line(ll _a=0, ll _b=0, ll _c=0) {
        a=_a;
        b=_b;
        c=_c;
    }

    ll val(ll x) {
        return a*x*x+b*x+c;
    }

    double intersect(const line &o) {
        return (c-o.c)/(double)(o.b-b);
    }
};

ll findopt(deque<line> &dq, ll x) {
    while(dq.size()>1ull and dq[0].val(x)>dq[1].val(x)) dq.pop_front();

    return dq.front().val(x);
}

int main() { _
    int n;
    ll c;
    cin >> n >> c;

    ll num,costl=0;
    
    deque<line> dq;
    cin >> num;
    dq.push_back(line(1,-2*num,c+num*num));
    
    for(int i=1;i<n;i++) {
        cin >> num;
        costl = findopt(dq,num);

        line newline(1,-2*num,num*num+c+costl);
        
        while(dq.size()>1ull and dq.back().intersect(newline)<=dq[dq.size()-2].intersect(dq.back())) {
            dq.pop_back();
        }

        dq.push_back(newline);
        
    }

    cout << costl << '\n';

    return 0;
}