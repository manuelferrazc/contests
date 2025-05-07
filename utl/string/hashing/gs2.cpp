#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { 
    string s,l;
    ll k;
    cin >> s >> l >> k;
    ll n = s.size();

    set<string> st;
    for(ll i=0;i<n;i++) {
        string a;
        ll qtd=0;
        for(ll j=i;j<n;j++) {
            a.push_back(s[j]);
            if(l[s[j]-'a']=='0') qtd++;
            if(qtd>k) break;
            st.insert(a);
        }
    }

    cout << st.size() << '\n';
    return 0;
}
