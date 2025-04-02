#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n;
    cin >> n;

    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].ff;
        v[i].ss = i;
    }

    sort(v.rbegin(),v.rend());

    vector<int> ans(n);

    ans[v[0].ss] = 1;
    int r=1;
    for(int i=1;i<n;i++) {
        if(v[i].ff!=v[i-1].ff) r=i+1;
        ans[v[i].ss] = r;
    }

    for(int i:ans) cout << i << '\n';

    return 0;
}
