#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,r,c;
    string s;
    cin >> n >> r >> c >> s;

    map<pair<int,int>,int> m;
    m.insert(make_pair(make_pair(r,c),0));
    int x=0,y=0;
    for(int t=0;t<n;t++) {
        char a = s[t];
        if(a=='N') x--;
        else if(a=='S') x++;
        else if(a=='E') y++;
        else y--;
        if(m.count({r+x,c+y})) continue;
        else m.insert(make_pair(make_pair(r+x,c+y),t));
    }

    x=0;
    y=0;
    string ans(n,'0');
    for(int t=0;t<n;t++) {  
        char a = s[t];
        if(a=='N') x--;
        else if(a=='S') x++;
        else if(a=='E') y++;
        else y--;
        if(m.count({x,y})) {
            if(t>=m.at({x,y})) ans[t]='1';
        }
    }

    cout << ans << '\n';

    return 0;
}
