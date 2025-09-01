#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ge first
#define ti second
typedef long long ll;
typedef unsigned long long ull;

struct G {
    ll t;
    ll m;
    bool c;
    ll i;

    bool operator<(G o) {
        return t<o.t;
    }
};

int main() { _
    ll n;
    cin >> n;
    
    vector<G> v(n);
    vector<ll> sad;
    ll cnt=1;
    for(auto &i:v) {
        cin >> i.t >> i.m >> i.c;
        i.i = cnt++;
    }

    sort(v.begin(),v.end());
    ll tf;

    deque<pair<ll,ll>> q;

    for(auto const &i:v) {
        while(q.size() and q.front().ti<=i.t-tf) {
            tf+=q.front().ti;
            q.pop_front();
        }

        if(q.empty()) tf=i.t;
        if(q.size() and i.c) {
            sad.push_back(q.front().ge);
            q.pop_front();
            q.push_front({i.i,i.m});
            tf=i.t;
        } else q.push_back(make_pair(i.i,i.m));
    }

    cout << sad.size() << '\n';
    for(auto i:sad) cout << i << ' ';
    cout << '\n';

    return 0;
}