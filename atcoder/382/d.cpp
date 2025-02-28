#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m;

vector<vector<int>> ans;

void pr(vector<int> &v) {
    for(auto i:v) cout << i << ' ';
    cout << '\n';
}

void brute(vector<int> &v, int f) {
    if(v.back()>m) return;
    if(v.size()==n) ans.push_back(v);
    else {
        for(int i=0;i<=f;i++) {
            v.push_back(v.back()+10+i);
            brute(v,f-i);
            v.pop_back();
        }
    }
}

int main() { _
    cin >> n >> m;
    int f = m-(n-1)*10-1;
    vector<int> v;

    for(int i=0;i<=f;i++) {
        v.push_back(1+i);
        brute(v,f-i);
        v.pop_back();
    }

    cout << ans.size() << '\n';
    for(auto &v: ans) pr(v);

    return 0;
}
