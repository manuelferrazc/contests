#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    string s,c;
    cin >> n >> m >> s;
    map<int,int> map;
    for(int i=0;i<m;i++) {
        int x;
        cin >> x;
        x--;
        map[x]++;
    }
    cin >> c;
    sort(c.begin(),c.end());
    list<char> l;
    for(char cc:c) l.push_back(cc);

    for(auto it = map.begin();it!=map.end();it++) {
        for(int i=1;i<it->ss;i++) l.pop_back();
        s[it->ff] = l.front();
        l.pop_front();
    }

    cout << s << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
