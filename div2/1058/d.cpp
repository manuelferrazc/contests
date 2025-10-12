#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<int> ans(2*n+1,-1);

    vector<int> que, ok;
    que.push_back(1);

    for(int i=2;i<=2*n;i++) {
        que.push_back(i);
        cout << "? " << que.size() << ' ';
        for(int i:que) cout << i << ' ';
        cout << '\n';
        cout.flush();

        int x;
        cin >> x;
        if(x) {
            ans[i] = x;
            que.pop_back();
            ok.push_back(i);
        } 
    }

    while(que.size()) {
        cout << "? " << n+1 << ' ';
        for(int i:ok) cout << i << ' ';
        cout << que.back() << '\n';
        
        cout.flush();
        
        int x;
        cin >> x;
        ans[que.back()] = x;

        que.pop_back();
    }

    cout << "! ";
    for(int i=1;i<=2*n;i++) cout << ans[i] << ' ';
    cout << '\n';
    cout.flush();
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
