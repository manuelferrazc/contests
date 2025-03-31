#include <bits/stdc++.h>
#include <ostream>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ql=0,qi=0,qt=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='I') qi++;
        else if(s[i]=='T') qt++;
        else ql++;
    }

    if((ql==0 and min(qt,qi)==0) or (qi==0 and qt==0)) {
        cout << -1 << '\n';
        return;
    }

    list<char> l;
    for(char c:s) l.push_back(c);

    vector<int> ans;
    map<pair<char,char>,pair<char,int*>> m;
    m.insert({{'I','L'},{'T',&qt}});
    m.insert({{'I','T'},{'L',&ql}});
    m.insert({{'L','T'},{'I',&qi}});
    int max = ::max({ql,qt,qi});

    while(max!=min({ql,qt,qi})) {
        int i=0;
        auto it = l.begin();
        bool f = false;
        for(;it!=prev(l.end());) {
            if(*it==*next(it)) {
                it++;
                i++;
                continue;
            }
            auto &p = m.at(make_pair(min(*it,*next(it)),::max(*it,*next(it))));
            if((*p.ss)==max) {
                i++;
                it++;
                continue;
            }
            (*p.ss)++;
            ans.push_back(i+1);
            it++;
            l.insert(it,p.ff);
            it--;
            it--;
            f=true;
            if(max==min({ql,qt,qi})) break;
        }
        if(f==false) {
            i=0;
            it=l.begin();
            for(;it!=prev(l.end());) {
                if(*it==*next(it)) {
                    it++;
                    i++;
                    continue;
                }
                auto &p = m.at(make_pair(min(*it,*next(it)),::max(*it,*next(it))));
                if((*p.ss)!=max) {
                    i++;
                    it++;
                    continue;
                }
                (*p.ss)++;
                ans.push_back(i+1);
                it++;
                l.insert(it,p.ff);
                it--;
                it--;
                max++;
                break;
            }   
        }
    }
    cout << ans.size() << '\n';
    for(auto i:ans) cout << i << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
