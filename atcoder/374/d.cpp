#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

struct line {
    pair<ll,ll> st,en;
};

double ans = 1e9;

double dist(pair<ll,ll> p1,pair<ll,ll> p2) {
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

void testat(vector<line> &v, vll &p, vector<bool> &end, ll s, ll t) {
    double act = 0;
    auto pos = make_pair(0LL,0LL);

    for(ull i=0;i<v.size();i++) {
        if(not end[p[i]]) {
            act += dist(pos,v[p[i]].st)/s;
            act += dist(v[p[i]].st,v[p[i]].en)/t;
            pos = v[p[i]].en;
        } else {
            act += dist(pos,v[p[i]].en)/s;
            act += dist(v[p[i]].en,v[p[i]].st)/t;
            pos = v[p[i]].st;
        }
    }

    ans = min(ans, act);
}

void testa(vector<line> &v, vll &p, vector<bool> &end, ll s, ll t) {
    if(v.size()==end.size()) testat(v,p,end,s,t);
    else {
        end.push_back(true);
        testa(v,p,end,s,t);
        end.back() = false;
        testa(v,p,end,s,t);
        end.pop_back();
    }
}

int main() { _
    ll n,s,t;
    cin >> n >> s >> t;

    vector<line> v(n);
    for(auto &i : v) cin >> i.st.x >> i.st.y >> i.en.x >> i.en.y;
    
    vector<ll> p;
    for(ll i=0;i<n;i++) p.push_back(i);
    vector<bool> end;

    do{
        testa(v,p,end,s,t);
    } while(next_permutation(p.begin(),p.end()));

    cout << fixed << setprecision(8);
    cout << ans << endl;
    return 0;
}
