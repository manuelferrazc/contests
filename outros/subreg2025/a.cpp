#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,m;
    cin >> n >> m;

    vector<int> ans(m,0);

    for(int f=0;f<n;f++) {
        for(int c=0;c<m;c++) {
            int x;
            cin >> x;
            ans[c] = max(ans[c],x);
        }
    }

    cout << accumulate(ans.begin(),ans.end(),0) << '\n';

    return 0;
}
