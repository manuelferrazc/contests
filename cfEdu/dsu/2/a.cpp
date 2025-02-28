#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int get(vector<int> &p, int a) {
    return p[a] = (p[a]==a ? a : get(p,p[a]));
}

void Union(vector<int> &p, int a, int b) {
    b = get(p,b);
    p[a] = b;
}

int main() { _
    int n,q;
    cin >> n >> q;
    vector<int> p(n+1);
    for(int i=0;i<=n;i++) p[i]=i;

    string s;
    int x;
    while(q--) {
        cin >> s >> x;
        x--;
        if(s[0]=='-') {
            Union(p,x,x+1);
        } else {
            x = get(p,x);
            cout << (x==n?-1:x+1) << '\n';
        }
    }

    return 0;
}
