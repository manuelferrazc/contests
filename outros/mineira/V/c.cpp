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
    int n, m; cin >> n >> m;
    set<pair<string, string>> st;
    for(int i = 0; i < n; i++){
        string a, b; cin >> a >> b;
        st.insert({a, b});
    }
    for(int j = 0; j < m; j++){
        string a, b; cin >> a >> b;
        if(st.count({a, b})) cout << "Nao e a mamae" << endl;
        else cout << "nao e o Nao e a mamae" << endl;
    }

    return 0;
}