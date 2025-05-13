#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ull n;
    cin >> n;

    vector<string> v;
    v.push_back("0");
    v.push_back("1");

    while(v.back().size()!=n) {
        vector<string> aux = v;
        for(string &s:aux) s.push_back('0');

        for(auto it = v.rbegin();it!=v.rend();it++  ) {
            aux.push_back((*it)+"1");
        }

        v = aux;
    }

    for(string &s:v) cout << s << '\n';
    
    return 0;
}
