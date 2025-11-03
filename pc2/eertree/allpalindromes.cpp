#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define SIG 26

struct EertreE {
    vector<vector<int>> to;
    vector<int> len;
    vector<int> suf;
    vector<int> t;
    int sz = 0;
    int cur = 0;

    EertreE() {
        to.push_back(vector<int>(26,-1));
        len.push_back(-1);
        suf.push_back(0);

        to.push_back(vector<int>(26,-1));
        len.push_back(0);
        suf.push_back(0);
        sz+=2;

        t.push_back(-1);
    }

    int add(char ch) {
        int c = ch-'a';

        t.push_back(c);

        while(cur>0 and t[t.size()-2-len[cur]]!=c) cur = suf[cur];
        if(to[cur][c]!=-1) {
            cur = to[cur][c];
            return len[cur];
        }

        if(cur) {
            to.push_back(vector<int>(SIG,-1));
            len.push_back(len[cur]+2);
            to[cur][c] = sz;

            cur = suf[cur];
            while(cur>0 and t[t.size()-2-len[cur]]!=c) cur = suf[cur];
            suf.push_back(to[cur][c]);
            cur = sz++;
        } else {
            to.push_back(vector<int>(SIG,-1));
            len.push_back(len[cur]+2);
            suf.push_back(1);
            to[cur][c] = sz;
            cur = sz++;
        }

        return len[cur];
    }
};

int main() { _
    string s;
    cin >> s;

    EertreE er;

    for(char c:s) 
        cout << er.add(c) << ' ';

    cout << '\n';
    
    return 0;
}
