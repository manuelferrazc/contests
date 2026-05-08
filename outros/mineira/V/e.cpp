#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n;
    cin >> n;

    map<string,string> m;

    set<string> s;

    while(n--) {
        string a,b;
        cin >> a >> b;
        m[b] = a;
        s.insert(a);
    }


    string raiz;
    for(auto [pai,filho]:m) {
        if(s.count(pai)==0) {
            raiz = pai;
            break;
        }
    }

    cout << raiz << '\n';
    while(m.count(raiz)) {
        raiz = m[raiz];
        cout << raiz << '\n';
    }

    return 0;
}