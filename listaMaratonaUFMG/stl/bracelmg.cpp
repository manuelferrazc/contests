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

void solve() {
    string p,b;
    cin >> p >> b;

    for(ull i=0;i<b.size();i++) {
        if(b[i]==p[0]) {
            bool e=true;
            for(ull j=1;j<p.size();j++) {
                if(b[(i+j)%b.size()]!=p[j]) {
                    e=false;
                    break;
                }
            }
            if(e) {
                cout << "S\n";
                return;
            }
        }
    }

    reverse(b.begin(),b.end());

    for(ull i=0;i<b.size();i++) {
        if(b[i]==p[0]) {
            bool e=true;
            for(ull j=1;j<p.size();j++) {
                if(b[(i+j)%b.size()]!=p[j]) {
                    e=false;
                    break;
                }
            }
            if(e) {
                cout << "S\n";
                return;
            }
        }
    }
    
    cout << "N\n";
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}