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

    list<int> v;
    vector<int> ans;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    while(v.size()) {
        if(v.size()==1ULL) {
            cout << 'R';
            break;
        }

        int x = ans.size()-1;

        if(v.front()<v.back()) {
            if(ans.empty() or ans[x-1]>ans[x] or ans[x]>v.front()) {
                cout << "LR";
                ans.push_back(v.front());
                ans.push_back(v.back());
            }
            else {
                cout << "RL";
                ans.push_back(v.back());
                ans.push_back(v.front());
            }
        }
        else { // front is bigger
            if(ans.empty() or ans[x-1]<ans[x] or ans[x]<v.front()) {
                cout << "LR";
                ans.push_back(v.front());
                ans.push_back(v.back());
            }
            else {
                cout << "RL";
                ans.push_back(v.back());
                ans.push_back(v.front());
            }
        }
        v.pop_back();
        v.pop_front();
    }

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
