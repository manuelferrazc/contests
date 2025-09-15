#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct st {
    int x,y,prio;

    st() {}
    st(int _x, int _y, int _p): x(_x), y(_y), prio(_p) {}
};

int main() { _
    int n;
    cin >> n;

    map<string,st> dict;
    for(int i=0;i<n;i++) {
        string s;
        int x,y;
        cin >> s >> x >> y;

        dict.insert(make_pair(s,st(x,y,i)));
    }

    int m;
    cin >> m;
    vector<string> context(m);
    for(string &s:context) cin >> s;

    int q,k;
    cin >> q >> k;

    while(q--) {
        int f;
        cin >> f;
        bool ok = false;

        vector<string> words;
        for(int i=0;i<f;i++) {
            string x;
            cin >> x;
            cout << x << ' ';
            words.push_back(x);
        }

        while(words.size()!=k) words.erase(words.begin()); 

        for(int kl = k;kl;kl--) {
            vector<string> candidates;

            for(int i=0;i+kl<m;i++) {
                // if(i/8!=(i+kl)/8)
                bool err = false;
                for(int j=0;j<kl;j++) {
                    if(context[i+j]!=words[j]) {
                        err = true;
                        break;
                    }
                }
                if(err==false) candidates.push_back(context[i+kl]);
            }

            if(candidates.empty()) {
                words.erase(words.begin());
                continue;
            }
            
            ok = true;

            map<int,pair<const string*,int>> simi;
            for(auto const &[str,val]:dict) {
                auto [x,y,p] = val;
                ll sim = 0;
                for(string const &cand: candidates) {
                    if(dict.count(cand)) {
                        auto [x2,y2,p2] = dict[cand];
                        sim += x2*x + y*y2;
                    }
                }
                if(simi.count(sim)==0ull or simi[sim].ss>p) simi[sim] = make_pair(&str,p);
                // else if(simi[sim].ss>p) simi[sim] = {str,p};
            }
            // for(auto [a,b]:simi) cout << a << ' ' << b << '\n';
            cout << *simi.rbegin()->ss.ff << '\n';
            break;
        }
        if(not ok) cout << "*\n";

    }

    return 0;
}
