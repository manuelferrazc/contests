#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int sigma = 27;

struct SuffAuto {
    vector<int> len, link;
    vector<vector<int>> t;
    vector<int> dist;

    int last;

    SuffAuto(): len(1,0), link(1,-1), t(1,vector<int>(sigma,-1)), last(0) {}

    void add(char c) {
        int cur = len.size(), p = last;

        len.push_back(len[last]+1);
        t.push_back(vector<int>(sigma,-1));
        link.push_back(0);

        while(p!=-1 and t[p][c-'a']==-1) {
            t[p][c-'a'] = cur;
            p = link[p];
        }

        if(p!=-1) {
            int q = t[p][c-'a'];

            if(len[p]+1==len[q]) link[cur] = q;
            else {
                int clone = len.size();
                
                len.push_back(len[p]+1);
                t.push_back(t[q]);
                link.push_back(link[q]);
                link[cur] = link[q] = clone;

                while(p!=-1 and t[p][c-'a']==q) {
                    t[p][c-'a'] = clone;
                    p = link[p];
                }
            }
        }

        last = cur;
    }
    
    void dfs(int v) {
        dist[v] = 0;
        for(int j=0;j<sigma;j++) {
            if(t[v][j]!=-1) {
                if(dist[t[v][j]]==-1) dfs(t[v][j]);
                dist[v] = max(dist[t[v][j]]+1,dist[v]); 
            }
        }
    }

    void build(string &s) {
        for(char c:s) add(c);
        dist.resize(t.size(),-1);
        dfs(0);
        // for(int i:count) cout << i << ' ';
        // cout << '\n';
    }

    int contains(string &s) {
        int act = 0;

        for(char c:s) {
            if(t[act][c-'a']==-1) return -1;
            act = t[act][c-'a'];
        }

        return dist[act];
    }
};

int main() { _
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    // t.push_back('{');
    
    SuffAuto aut;
    aut.build(s);

    // for(int i=0;i<aut.t.size();i++) {
    //     cout << i << " : ";
    //     for(int j=0;j<sigma;j++) {
    //         if(aut.t[i][j]!=-1)
    //         cout << "( " << ((char)(j+'a')) << " -> " << aut.t[i][j] << " ) ";
    //     }
    //     cout << '\n';
    // }

    while(k--) {
        cin >> s;
        int c = aut.contains(s);
        if(c==-1) cout << -1 << '\n';
        else cout << n-c-s.size()+1 << '\n';
    }

    return 0;
}
