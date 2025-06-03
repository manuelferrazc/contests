#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void solve() {
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    
    vector<vector<int>> c(3,vector<int>(3,0)),cont(3,vector<int>(3,0));
    vector<pair<char,char>> v(q);

    map<char,ordered_set> m;
    m.insert(make_pair('a',ordered_set()));
    m.insert(make_pair('b',ordered_set()));
    m.insert(make_pair('c',ordered_set()));
    for(int i=0;i<n;i++) m[s[i]].insert(i);

    for(int i=0;i<q;i++) {
        string a,b;
        cin >> a >> b;

        v[i].ff = a[0];
        v[i].ss = b[0];
        c[a[0]-'a'][b[0]-'a']++;
    }

    // for(int i=0;i<n;i++) {
    //     if(s[i]=='b') {
    //         if(c[1][0]) {
    //             s[i]='a';
    //             c[1][0]--;
    //         } else if(c[1][2] and c[2][0]) {
    //             c[1][2]--;
    //             c[2][0]--;
    //             s[i]='a';
    //         }
    //     } else if(s[i]=='c') {
    //         if(c[2][0]) {
    //             c[2][0]--;
    //             s[i]='a';
    //         }
    //         else if(c[2][1] and c[1][0]) {
    //             c[2][1]--;
    //             c[1][0]--;
    //             s[i]='a';
    //         } else if(c[2][1]) {
    //             c[2][1]--;
    //             s[i] = 'b';
    //         }
    //     }
    // }

    for(int i=0;i<q;i++) {
        if(i) c[v[i-1].ff-'a'][v[i-1].ss-'a']--;
        if(cont[v[i].ff-'a'][v[i].ss-'a']) {
            cont[v[i].ff-'a'][v[i].ss-'a']--;
            continue;
        }

        if(v[i].ff==v[i].ss or v[i].ff=='a') continue;
        
        if(v[i].ff == 'b' and v[i].ss=='c') {
            if(m['b'].empty()) continue;

            if(c[2][0]>m['c'].size()) {
                auto it = m['b'].begin();
                s[*it] = 'a';
                m['a'].insert(*it);
                m['b'].erase(it);
                cont[2][0]++;
            }
        } else if(v[i].ff == 'b' and v[i].ss=='a') {
            if(m['b'].empty()) continue;

            auto it = m['b'].begin();
            s[*it] = 'a';
            m['a'].insert(*it);
            m['b'].erase(it);
        } else if(v[i].ff == 'c' and v[i].ss=='b') {
            if(m['c'].empty()) continue;
            
            if(c[1][0]>m['b'].size()) {
                auto it = m['b'].begin();
                s[*it] = 'c';
                m['c'].insert(*it);
                m['b'].erase(it);
            }
        } else {
            if(m['c'].empty()) continue;
            auto it = m['c'].begin();
            s[*it] = 'a';
            m['a'].insert(*it);
            m['b'].erase(it);
        }
    } 

    cout << s << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
