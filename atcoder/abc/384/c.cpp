#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void f(vector<int> &v, vector<bool> &us, map<int,set<string>> &se, int i) {
    if(i==5) {
        string s;
        int val=0;
        for(int j=0;j<5;j++) if(us[j]) {s.push_back('A'+j);val+=v[j];}
        if(s.size()) {
            if(not se.count(val)) se.insert({val,set<string>()});
            se.at(val).insert(s);
        }
        return;
    }
    us.push_back(true);
    f(v,us,se,i+1);
    us.back()=false;
    f(v,us,se,i+1);
    us.pop_back();
}

int main() { _
    vector<int> v(5);
    for(int i=0;i<5;i++) cin >> v[i];
    map<int,set<string>> s;

    vector<bool> b;
    f(v,b,s,0);
    for(auto it = s.rbegin();it!=s.rend();it++) for(auto st: it->ss) cout << st << '\n';
    return 0;
}
