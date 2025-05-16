#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,x;
    cin >> n >> x;

    vector<pair<int,int>> v(n);
    for(int i=1;i<=n;i++) {
        cin >> v[i-1].ff;
        v[i-1].ss = i;
    }

    sort(v.begin(),v.end());

    int a=0,b=n-1;

    while(a<b) {
        if(v[a].ff+v[b].ff==x) {
            cout << v[a].ss << ' ' << v[b].ss << '\n';
            return 0;
        } else if(v[a].ff+v[b].ff>x) b--;
        else a++;        
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
