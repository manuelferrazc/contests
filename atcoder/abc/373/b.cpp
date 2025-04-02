#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
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

int main() { _
    string s;
    cin >> s;

    map<char,ll> m;

    for(int i=0;i<26;i++) m.insert({s[i],i});

    ll ans=0;
    ll act = m.at('A');

    for(char c='B';c<='Z';c++) {
        ans+=abs(act-m.at(c));
        act = m.at(c);
    }

    cout << ans << '\n';

    return 0;
}
