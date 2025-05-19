#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,qtd=0,a=0;
    cin >> n;
    vector<pair<pair<int,int>,int>> v(n);
    vector<int> ans(n),q;
    set<int> s;

    for(int i=0;i<n;i++) {
        s.insert(i+1);
        cin >> v[i].ff.ff >> v[i].ff.ss;
        v[i].ss = i;
        q.push_back(v[i].ff.ss);
    }

    sort(v.begin(),v.end());
    sort(q.begin(),q.end());
    multimap<int,int> m;

    for(int i:q) {
        while(a < n and v[a].ff.ff<=i) {
            m.insert({v[a].ff.ss,*s.begin()});
            ans[v[a].ss] = *s.begin();
            s.erase(s.begin());
            a++;
        }

        qtd = max(qtd,(int)m.size());

        while(m.size() and m.begin()->ff<=i) {
            auto it = m.begin();
            s.insert(it->ss);
            m.erase(it);
        }
    }

    cout << qtd << '\n';
    for(int i:ans) cout << i << ' ';
    cout << '\n';

    return 0;
}
