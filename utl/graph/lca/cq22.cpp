#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void get(set<int> &s, vector<int> &v, int x) {
    s.clear();
    while(x!=-1) {
        s.insert(x);
        x = v[x];
    }
}

int get2(set<int> &s, vector<int> &v, int x) {
    while(not s.count(x)) x = v[x];
    return x;
}

int main() { _
    int n,q;
    cin >> n >> q;

    vector<int> p(n);
    p[0] = -1;
    for(int i=1;i<n;i++) {
        cin >> p[i];
        p[i]--;
    }

    while(q--) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        set<int> s;
        get(s,p,a);

        cout << get2(s,p,b)+1 << '\n';
    }
    return 0;
}
