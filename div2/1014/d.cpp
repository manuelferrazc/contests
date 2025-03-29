#include <bits/stdc++.h>

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

    if((ql==0 and qi==0) or (ql==0 and qt==0) or (qi==0 and qt==0)) {
        cout << -1 << '\n';
        return;
    }
    list<char> l;
    for(char c:s) l.push_back(c);

    vector<int> ans;
    auto it = l.begin();
    ull i=0;
    while(max(ql,max(qt,qi))!=min(ql,min(qt,qi))) {
        char c1,c2,d;
        int *p;
        if(ql==min(ql,min(qt,qi))) {
            c1='T';
            c2='I';
            d='L';
            p = &ql;
        } else if (qt==min(ql,min(qt,qi))) {
            c1='L';
            c2='I';
            d='T';
            p=&qt;
        } else {
            c1='T';
            d='I';
            c2='L';
            p=&qi;
        }
        for(;it!=l.end();) {
            if((*it==c1 and *next(it)==c2) or (*it==c2 and *next(it)==c1)) {
                ans.push_back(i+1);
                it++;
                l.insert(it,d);
                (*p)=*p+1;
                it--;
                it--;
                break;
            }
            it++;i++;
        }
        if(max(ql,max(qt,qi))==min(ql,min(qt,qi))) break;
        if(it==l.end()) it=l.begin(),i=0;
    }
    cout << ans.size() << '\n';
    for(auto i:ans) cout << i << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
