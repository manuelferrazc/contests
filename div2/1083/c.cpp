#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<int> v[n];
    for(int i=0;i<n;i++) {
        set<int> s;
        stack<int> st;
 
        int l;
        cin >> l;
        while(l--) {
            int x;
            cin >> x;
            st.push(x);
        }
 
        while(st.size()) {
            int x = st.top();
            st.pop();
 
            if(s.count(x)) continue;
 
            v[i].push_back(x);
            s.insert(x);
        }
 
        reverse(v[i].begin(),v[i].end());
    }

    
    map<int,vector<int>> m;
    set<int> s;
    
    for(int i=0;i<n;i++) m[v[i].back()].push_back(i);
    
    vector<int> ans;
    
    while(m.size()) {
        if(s.count(m.begin()->ff)) {
            auto v2 = m.begin()->ss;
            m.erase(m.begin());
            for(int i:v2) {
                while(v[i].size() and s.count(v[i].back()))
                    v[i].pop_back();
                if(v[i].size()>0) m[v[i].back()].push_back(i);
            }

            continue;
        }

        vector<int> opt = m.begin()->ss; // indices do ótimo
        sort(opt.begin(),opt.end());
        m.erase(m.begin());

        while(true) {
            // map valor do novo final -> indices
            map<int,vector<int>> aux;

            bool c = true;
            for(auto i:opt) {
                if(v[i].size()==0) cout << "SLA?????????\n";
                if(not s.count(v[i].back())) {
                    int x = v[i].back();
                    ans.push_back(v[i].back());
                    s.insert(v[i].back());
                    
                    for(ull k=0;k<m[x].size();) {
                        int j = m[x][k];
                        
                        auto it = lower_bound(opt.begin(),opt.end(),j);
                        if(it==opt.end() or *it!=j) {
                            while(v[j].size() and s.count(v[j].back()))
                                v[j].pop_back();

                            if(v[j].size()) m[v[j].back()].push_back(j);
                            swap(m[x][k],m[x].back());
                            m[x].pop_back();
                        } else k++;
                    }
                }

                while(v[i].size() and s.count(v[i].back()))
                    v[i].pop_back();

                if(v[i].size()) {
                    aux[v[i].back()].push_back(i);
                } else c = false;

            }
            
            if(aux.empty()) break;
            opt = aux.begin()->ss;
            sort(opt.begin(),opt.end());

            for(auto it = next(aux.begin());it!=aux.end();it++) {
                for(auto j:it->ss) if(v[j].size()) m[v[j].back()].push_back(j);
            }
            if(not c) {
                for(auto i:opt) if(v[i].size()) m[v[i].back()].push_back(i);
                break;
            }
        }
    }

    for(int i:ans) cout << i << ' ';
    cout << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
