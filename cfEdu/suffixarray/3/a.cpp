#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
 
void sort(vector<pair<pair<int,int>,int>> &v) {
    vector<pair<pair<int,int>,int>> aux = v;
    vector<int> count(v.size()+1,0);
    for(auto i:v) count[i.ff.ff+1]++;    
    for(ull i=1;i<count.size();i++) count[i]+=count[i-1];
    for(auto i:aux) v[count[i.ff.ff]++] = i;
}
 
auto suffixArray(string &s) {
    s.push_back('$');
    int n=s.size();
 
    vector<int> p(n),c(n);
 
    {   vector<pair<char,int>> v(n);
        for(int i=0;i<n;i++) v[i] = {s[i],i};
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++) p[i]=v[i].ss;
        c[p[0]] = 0;
        for(int i=1;i<n;i++) {
            c[p[i]] = c[p[i-1]];
            if(v[i].ff!=v[i-1].ff) c[p[i]]++;
        }
    }
 
    for(int k=0;;k++) {
        int size = 1<<k;
        vector<pair<pair<int,int>,int>> aux(n);
        for(int i=0;i<n;i++) aux[i] = {{c[(p[i]-size+n)%n],c[(p[i])%n]},(p[i]-size+n)%n};
        sort(aux);
 
        for(int i=0;i<n;i++) p[i]=aux[i].ss;
        c[p[0]] = 0;
        for(int i=1;i<n;i++) {
            c[p[i]] = c[p[i-1]];
            if(aux[i].ff!=aux[i-1].ff) c[p[i]]++;
        }
        if(c[p.back()]==n-1) break;
    }
 
    return p;
}
    

int main() { _
    string s;
    cin >> s;
    s.push_back('{');
    auto p = suffixArray(s);

    int q;
    cin >> q;

    while(q--) {
        string x;
        cin >> x;

        int l=1,r=p.size(),sz=x.size();
        bool ok;
        while(l<=r) {
            ok = false;
            int m = (l+r)>>1;
            for(int i=0;i<sz;i++) {
                if(x[i]<s[p[m]+i]) {
                    r=m-1;
                    break;
                } else if(x[i]>s[p[m]+i]) {
                    l=m+1;
                    break;
                } else if(i==sz-1) ok=true;
            }
            if(ok) break;
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
