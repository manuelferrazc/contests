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
    while(dq.size()>1ull and dq[0].val(x)>dq[1].val(x)) dq.pop_front();

    return dq.front().val(x);
}

int main() { _
    int n;
    cin >> n;
    ll a[n],b[n];

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];


    deque<line> dq;

    dq.push_back(line(b[0],0));

    for(int i=1;i<n-1;i++) {
        ll act = findopt(dq,a[i]);

        line newline(b[i],act);

        while(dq.size()>1ull and dq.back().intersect(newline)<=dq[dq.size()-2].intersect(dq.back())) {
            dq.pop_back();
        }

        dq.push_back(newline);
    }

    cout << findopt(dq,a[n-1]) << '\n';


    return 0;
}