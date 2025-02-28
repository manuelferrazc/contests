#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define ff first
#define ss second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

void solve() {
    string s;
    cin >> s;

    int u=s[0]=='1',d=s[0]=='2',t=s[0]=='3';
    ull a=0,b=0,m=ULLONG_MAX;

    while(true) {
        if(u and d and t) {
            if(s[a]=='1') u--;
            else if(s[a]=='2') d--;
            else t--;
            
            if(u and t and d) m = min(m,b-a);
            a++;
            continue;
        } else if(b<s.size()-1) {
            b++;
            if(s[b]=='1') u++;
            else if(s[b]=='2') d++;
            else t++;
            if(u and t and d) m = min(m,b-a+1ULL);
        } else break;
    }

    cout << (m == ULLONG_MAX ? 0 : m) << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
