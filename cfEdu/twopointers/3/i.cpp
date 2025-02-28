#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void add(vector<int> &qtd, int x) {
    for(int i=(int)qtd.size()-1;i-x>=0;i--) qtd[i]+=qtd[i-x];
}

void remove(vector<int> &qtd, int x) {
    for(int i=x;i<(int)qtd.size();i++) qtd[i]-=qtd[i-x];
}

int main() { _
    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    vector<int> qtd(s+1,0);
    qtd[0] = 1;

    int ans=INT_MAX,l=0,r=-1;

    while(r<n) {
        if(l>r) {
            r++;
            if(r==n) break;
            add(qtd,v[r]);
        } else if(qtd.back()) {
            ans=min(ans,r-l+1);
            remove(qtd,v[l]);
            l++;
        } else {
            r++;
            if(r==n) break;
            add(qtd,v[r]);
        }
    }

    cout << (ans==INT_MAX? -1 : ans) << '\n';

    return 0;
}
