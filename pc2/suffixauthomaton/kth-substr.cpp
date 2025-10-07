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
    vector<int> count;

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
        count[v] = 1;
        for(int j=0;j<sigma;j++) {
            if(t[v][j]!=-1) {
                if(count[t[v][j]]==-1) dfs(t[v][j]);
                count[v]+=count[t[v][j]]; 
            }
        }
    }

    void build(string &s) {
        for(char c:s) add(c);
        count.resize(t.size()+1,-1);
        dfs(0);
    }

    int contains(string &s) {
        int act = 0;

        for(char c:s) {
            if(t[act][c-'a']==-1) return 0;
            act = t[act][c-'a'];
        }

        return count[act];
    }

    void find(int k, int v=0) {
        // cout << "sla" << k << "\n";
        if(k==1) return;
        k--;
        for(int i=0;i<sigma;i++) {
            int nxt = t[v][i];
            if(nxt!=-1) {
                // cout << nxt << ' ' << ((char)(i+'a')) << ' ' << k << ' ' << count[nxt] << '\n';;
                if(k<=count[nxt]) {
                    cout << (char)(i+'a');
                    if(k>1) find(k,nxt);
                    return;
                } else k-=count[nxt];
            }
        }
    }
};

int main() { _
    int k;
    string s;
    cin >> s >> k;

    SuffAuto aut;
    aut.build(s);

    aut.find(k+1);
    cout << '\n';

    return 0;
}
