#include <bits/stdc++.h>

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

int obj;

bool testa(string &s, int d) {
    int act = 0;

    while(true) {
        if((act+d)>=obj) return true;
        bool p = false;
        for(int i = 1;i<=d;i++) {
            if(s[act+i]=='R') {
                act += i;
                p = true;
                break;
            }
        }
        if(p==false) return false;
    }
    return false;
}

int bb(string &s,int a, int b) {
    if(a==b) return (testa(s,a) ? a : -INT_MAX);

    int m = (a+b)/2;
    if(testa(s,m)) return bb(s,a,m);
    else return bb(s,m+1,b);
}

void solve() {
    string s;
    cin >> s;
    obj = s.size()+1;
    s = "R"+s;

    cout << bb(s,1,obj) << '\n';
}

int main() { _
    int n;
    cin >> n;
    while(n--) solve();

    return 0;
}