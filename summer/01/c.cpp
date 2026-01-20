#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct sla {
    int beg;
    int end;
    bool black;
    int h;

    sla(int a, int b, bool c, int d):beg(a),end(b),black(c),h(d) {}
};

void solve() {
    string s;
    cin >> s;

    stack<sla> st;
    int qtd = 0;
    ll ans = 0;

    for(ull i=0;i<s.size();i++) {
        char c = s[i];
        if(c=='(') {
            qtd++;
            if(st.size() and st.top().h) st.push(sla(st.top().end+2,-1,qtd%2,0));
            else if(st.size()) st.push(sla(st.top().beg+1,-1,qtd%2,0));
            else st.push(sla(0,-1,qtd%2,0));
        } else if(st.top().h) {
            qtd--;
            int mx = 0;
            int end = st.top().end;

            while(st.size() and st.top().h) {
                mx = max(mx,st.top().h);
                st.pop();
            }

            st.top().end = end+1;
            st.top().h = mx+1;

            if(st.top().black) ans+=(1ll+st.top().end-st.top().beg)*(mx+1ll);
            else ans-=(1ll+st.top().end-st.top().beg)*(mx+1ll);
        } else {
            qtd--;
        
            if(st.top().black) ans++;
            else ans--;

            st.top().h = 1;
            st.top().end = st.top().beg;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
