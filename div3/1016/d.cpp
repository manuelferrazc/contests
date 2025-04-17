#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll x,y;

ll find_number(ll x1,ll x2,ll y1,ll y2) {
    if(x1==x2-1 and y1==y2-1) {
        if(x==1 and y==1) return 1;
        if(x==2 and y==2) return 2;
        if(x==2 and y==1) return 3;
        return 4;
    }
    // cout << x << ' ' << y << '\n';
    // cout << x2 << ' ' << y2 << '\n' << '\n';
    if(x>x2/2 and y>y2/2) {
        x-=x2/2;
        y-=y2/2;
        return y2*y2/4+find_number(x1,x2/2,y1,y2/2);
    } else if(x>x2/2) {
        x-=x2/2;
        return y2*y2/4*2+find_number(x1,x2/2,y1,y2/2);
    } else if(y>y2/2) {
        y-=y2/2;
        return y2*y2/4*3+find_number(x1,x2/2,y1,y2/2);
    } else return find_number(x1,x2/2,y1,y2/2);
}

pair<ll,ll> find_pos(ll v, ll p) {
    if(v==1) return {1,1};
    if(v==2) return {2,2};
    if(v==3) return {2,1};
    if(v==4) return {1,2};

    if(v>(1LL<<(2*p-2)) and v<=(1LL<<(2*p-1))) {
        v-=1LL<<(p*2-2);
        auto c = find_pos(v,p-1);
        c.ff+=1LL<<(p-1);
        c.ss+=1LL<<(p-1);
        return c;
    } else if(v>((1LL<<(2*p-1))) and v<=((1ll<<(2*p-1))+(1LL<<(2*p-2)))) {
        v-=(1LL<<(2*p-1));
        auto c = find_pos(v,p-1);
        c.ff+=1LL<<(p-1);
        return c;
    } else if(v>((1ll<<(2*p-1))+(1LL<<(2*p-2)))) {
        v-=((1ll<<(2*p-1))+(1LL<<(2*p-2)));
        auto c = find_pos(v,p-1);
        c.ss+=1LL<<(p-1);
        return c;
    } else return find_pos(v,p-1);
}

void solve() {
    ll n,q;
    cin >> n >> q;
    string op;
    while(q--) {
        cin >> op >> x;
        if(op[0]=='-') {
            cin >> y;
            cout << find_number(1,1LL<<n,1,1LL<<n) << '\n';
        } else {
            auto p = find_pos(x,n+1);
            cout << p.ff << ' ' << p.ss << '\n';
        }
    }

}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}