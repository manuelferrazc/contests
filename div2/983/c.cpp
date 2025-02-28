#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll median(multiset<ll> &s) {
    auto i = s.begin(), f = s.end();
    f--;
    while(true) {
        if(*i==*f) return *f;
        if(*i>*f) return (*f+*i)>>1;
        i++;
        f--;
    }
}

ll mean(multiset<ll> &s) {
    ll sum=0;
    for(auto i:s) sum+=i;
    return sum/(ll)s.size();
}

ll m,me;

ll c1(multiset<ll> s) {
    ll c=0;
    while(true) {
        auto it = s.begin();
        ll x1=*it;
        it++;
        ll x2=*it;
        ll f = *s.rbegin();
        if(x1+x2>f) return c;
        c++;
        s.erase(s.begin());
        s.insert(f);
    }
}

ll c2(multiset<ll> s) {
    ll c=0;

    while(true) {
        auto it = s.begin();
        ll x1=*it;
        it++;
        ll x2=*it;
        ll f = *s.rbegin();
        if(x1+x2>f) return c;
        c++;
        s.erase(prev(s.end()));
        s.insert(x2);
    }
}

ll c3(multiset<ll> s) {
    ll c=0;

    while(true) {
        auto it = s.begin();
        ll x1=*it;
        it++;
        ll x2=*it;
        ll f = *s.rbegin();
        if(x1+x2>f) return c;
        if((m<<1)>f) break;
        c++;
        s.erase(prev(s.end()));
        s.insert(m);
    }

    while(true) {
        auto it = s.begin();
        ll x1=*it;
        it++;
        ll x2=*it;
        ll f = *s.rbegin();
        if(x1+x2>f) return c;
        c++;
        s.erase(s.begin());
        s.insert(m);
    }
}

ll c4(multiset<ll> s) {
    ll c=0;

    while(true) {
        auto it = s.begin();
        ll x1=*it;
        it++;
        ll x2=*it;
        ll f = *s.rbegin();
        if(x1+x2>f) return c;
        if((me<<1)>f) break;
        c++;
        s.erase(prev(s.end()));
        s.insert(me);
    }

    while(true) {
        auto it = s.begin();
        ll x1=*it;
        it++;
        ll x2=*it;
        ll f = *s.rbegin();
        if(x1+x2>f) return c;
        c++;
        s.erase(s.begin());
        s.insert(me);
    }
}

ll c5(multiset<ll> s) {
    ll c=0;

    while(true) {
        ll f = *s.rbegin();
        if(m>=f) break;
        auto it = s.begin();
        ll x1=*it;
        it++;
        ll x2=*it;
        if(x1+x2>f) return c;
        c++;
        s.erase(prev(s.end()));
        s.insert(m);
    }

    while(true) {
        auto it = s.begin();
        ll x1=*it;
        it++;
        ll x2=*it;
        ll f = *s.rbegin();
        if(x1+x2>f) return c;
        c++;
        s.erase(s.begin());
        s.insert(m);
    }
}

ll c6(multiset<ll> s) {
    ll c=0;

    while(true) {
        ll f = *s.rbegin();
        if(me>=f) break;
        auto it = s.begin();
        ll x1=*it;
        it++;
        ll x2=*it;
        if(x1+x2>f) return c;
        c++;
        s.erase(prev(s.end()));
        s.insert(me);
    }

    while(true) {
        auto it = s.begin();
        ll x1=*it;
        it++;
        ll x2=*it;
        ll f = *s.rbegin();
        if(x1+x2>f) return c;
        c++;
        s.erase(s.begin());
        s.insert(me);
    }
}

void solve() {
    ll n;
    cin >> n;

    multiset<ll> s;
    {
    ll x;
    for(ll i=0;i<n;i++) {
        cin >> x;
        s.insert(x);
    }
    }
    m = median(s);
    me = mean(s);

    ll x = min(min(c6(s),c5(s)),min(min(c1(s),c3(s)),min(c4(s),c2(s))));
    m++;
    me++;
    x = min(min(x,c6(s)),min(min(c3(s),c4(s)),c5(s)));
    cout << x << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
