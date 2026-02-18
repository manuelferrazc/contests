#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

void walk(ld &x, ld &y, int deg, int p) {

}

void solve() {
    int n;
    cin >> n;

    ld x=0,y=0;
    int deg = 0;

    string s,p2;
    ll p;
    bool mv = false;
    bool l;
    while(n--) {
        cin >> s >> p2;
        if(p2[0]=='?') {
            if(s[0]=='f' or s[0]=='b') mv = true;
            else {
                l = s[0]=='l';
                break;
            }
        }

        if(s[0]=='f') {
            walk(x,y,deg,p);
        } else if(s[0]=='b') {
            deg+=180;
            deg%=360;
            walk(x,y,deg,p);
            deg+=180;
            deg%=360;
        } else if(s[0]=='l') {
            deg+=p;
            deg%=360;
        } else {
            deg+=360;
            deg-=p;
            deg%=mod;
        }
    }

    // ? = sqrt(x²+y²)
    if(mv) cout << (ll)(sqrt(x*x+y*y)+0.0001) << '\n';
    else {
        stack<pair<string,int>> st;
        while(n--) {
            cin >> s >> p2;
            st.push({s,p2});
        }
        
        ld x2=0,y2=0;
        while(st.size()) {

        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
