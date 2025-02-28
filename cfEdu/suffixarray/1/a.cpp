#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    string s;
    cin >> s;
    s.push_back('$');
    int n=s.size();

    vector<int> p(n),c(n);
    vector<pair<char,int>> v(n);
    for(int i=0;i<n;i++) v[i] = {s[i],i};
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) p[v[i].ss]=i;
    c[v[0].ss] = 0;
    for(int i=1;i<n;i++) {
        c[v[i].ss] = c[v[i-1].ss];
        if(v[i].ff!=v[i-1].ff) c[v[i].ss]++;
    }

    for(int k=0;;k++) {
        if(*max_element(c.begin(),c.end())>=n-1) break;
        int size = 1<<k;
        vector<pair<pair<int,int>,int>> aux(n);
        for(int i=0;i<n;i++) aux[i] = {{c[i],c[(i+size)%n]},i};
        sort(aux.begin(),aux.end());

        for(int i=0;i<n;i++) p[aux[i].ss]=i;
        c[aux[0].ss] = 0;
        int max = 0;
        for(int i=1;i<n;i++) {
            c[aux[i].ss] = c[aux[i-1].ss];
            if(aux[i].ff!=aux[i-1].ff) c[aux[i].ss]++;
            max=::max(max,c[aux[i].ss]);
        }
    }

    vector<int> ans(n);
    for(int i=0;i<n;i++) ans[p[i]]=i;
    for(auto i:ans) cout << i << ' ';
    cout << '\n';

    return 0;
}
