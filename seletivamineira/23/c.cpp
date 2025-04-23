#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    pair<int,int> s,e;
    cin >> s.x >> s.y >> e.x >> e.y;

    if(s.x==e.x or s.y==e.y) cout << 1 << ' ';
    else cout << 2 << ' ';

    if(abs(s.x-e.x)==abs(s.y-e.y)) cout << 1 << ' ';
    else if(((s.x+s.y)&1)==((e.x+e.y)&1)) cout << 2 << ' ';
    else cout << 0 << ' ';

    cout << max(abs(s.x-e.x),abs(s.y-e.y)) << '\n';
    
    return 0;
}
