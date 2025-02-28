#include <bits/stdc++.h>
#include <string>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
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

ll logg(ll a) {
    ll ret = 1;
    ll act = 10;

    while(act<a) {
        ret++;
        act*=10;
    }

    return act==a?act : act/10;
}

void print(string &s, ll a, ll b) {
    // cout << "entrou " << a << " " << b << "\n";
    if(a==0 or b==0) return;

    // auto a1 = logg(a), b2 = logg(b);

    if(a-((a/10)*10) and a>10) {
        ll aux = (a/10)*10;
        print(s,a-aux,b);
        print(s,aux,b);
    } else if(b-((b/10)*10) and b>10) {
        ll aux = (b/10)*10;
        print(s,a,b-aux);
        print(s,a,aux);
    } else {
        if(s.size()){
            s.push_back(' ');
            if(a<0LL) s.push_back('-');
            else s.push_back('+');
            s.push_back(' ');
            
            s = s+to_string((abs(a))) + " x " + to_string(b);
        } else {
            if(a<0LL) s = "-";
            s += to_string((abs(a))) + " x " + to_string(b);
        }
    }
}

void solve() {
    ll a,b;
    cin >> a >> b;

    if(a<0LL and b<0LL) {a=-a;b=-b;}
    else if(b<0LL) {auto aux = a;a=b;b=aux;}

    string s;
    print(s,a,b);
    cout << s << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}