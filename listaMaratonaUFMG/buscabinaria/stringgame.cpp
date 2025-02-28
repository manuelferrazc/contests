#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define f first
typedef unsigned ui;
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

bool testa(const string &s,const  string &r) {
    ull j = 0;
    for(auto i:s) {
        if(r[j]==i) {
            j++;
            if(j==r.size()) return true;
        }
    }
    return false;
}

void cria(string &out,string const &t, vi &v, int x) {
    si s;
    for(int i=0;i<=x;i++) s.insert(v[i]);

    for(ull i=0;i<t.size();i++) {
        if(not s.count(i)) out.push_back(t[i]);
        else s.erase(i);
    }
}

int bb(string &t, string &p, vi &v, int a, int b) {
    if(a==b) {
        string s;
        cria(s,t,v,a);
        return testa(s,p) ? a : a-1;
    }

    int m = (a+b)/2;
    string s;
    cria(s,t,v,m);
    if(testa(s,p)) return bb(t,p,v,m+1,b);
    return bb(t,p,v,a,m);
}

int main() { _
    string p,t;
    cin >> t >> p;
    
    vi v(t.size());
    for(auto &i:v) {
        cin >> i;
        i--;
    }

    cout << bb(t,p,v,0,t.size()-p.size())+1 << '\n';

    return 0;
}
