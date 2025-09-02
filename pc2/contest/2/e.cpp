#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,m,ans=0;
    cin >> n >> m;

    map<string,int> c;

    for(int i=0;i<n;i++) {
        int op;
        cin >> op;

        if(op==1) {
            int q=0;
            for(auto it = c.begin();it!=c.end();it++) q = max(q,it->ss);
            ans+=q;
            c.clear();
        } else {
            string s;
            cin >> s;
            c[s]++;
        }
    }

    int q=0;
    for(auto it = c.begin();it!=c.end();it++) q = max(q,it->ss);
    ans+=q;
    c.clear();

    cout << ans << '\n';
    return 0;
}
