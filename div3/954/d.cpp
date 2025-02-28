#include <bits/stdc++.h>
#include <vector>

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


int toint(string &s, int a, bool d=false) {
    int r=s[a]-'0';
    if(d) {
        r*=10;
        r+=s[a+1]-'0';
    }
    return r;
} 

int resolve(vi &v) {
    sort(v.begin(),v.end());
    int r=0;
    if(v.front()==0) return 0;
    for(int i=0;i<(int)v.size();i++) {
        if(v[i]==1) continue;
        r+=v[i];
    }

    return max(r,1);
}


void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if(n==2) {
        cout << stoi(s) << '\n';
        return;
    }

    for(int i=0;i<n;i++) if(s[i]=='0') {
        if(i==1 and s.size()==3) continue;
        cout << "0\n";
        return;
    }

    int r=INT_MAX;
    

    for(int i=0;i<n-1;i++) {
        vi v;
        for(int j=0;j<n;j++) {
            if(i==j) {v.push_back(toint(s,j,true));j++;}
            else v.push_back(toint(s,j));
        }
        r=min(r,resolve(v));
    }

    cout << r << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}